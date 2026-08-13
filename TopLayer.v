`include "CPU.v"
`include "BRAM.v"
`include "GPIO.v"
`include "UART.v"

// TopLayer: CPU + RAM (BRAM) + MMIO (GPIO bank, 4x UART, CLINT) rerouting.
//
// Address map (load/store effective address is full 32-bit from the CPU):
//   0x00000000 .. 0x0000FFFF   RAM  (BRAM's unified Mem, indexed by addr[15:0] --
//                               shared by fetch and load/store, see BRAM.v)
//   0xFFFFFF00 .. 0xFFFFFFFF   MMIO (top 256 bytes = 64 word slots)
//
// MMIO slot = addr[7:2] (0..63):
//   0  GPIO_DATA_IN      RO      synchronized input, one bit per pin
//   1  GPIO_DATA_OUT     RW      output latch (readback of what's driven)
//   2  GPIO_DIR          RW      1 = pin's writes take effect, 0 = ignored
//   3  GPIO_SET          WO      write-1-to-set bits in DATA_OUT (masked by DIR)
//   4  GPIO_CLR          WO      write-1-to-clear bits in DATA_OUT (masked by DIR)
//   5  GPIO_INT_ENABLE   RW      1 = pin armed to raise an interrupt
//   6  GPIO_INT_RISE_EN  RW      1 = rising edge arms the interrupt
//   7  GPIO_INT_FALL_EN  RW      1 = falling edge arms the interrupt
//   8  GPIO_INT_PENDING  RW1C    edge-latched; write 1 to clear
//   9..15  reserved (future GPIO expansion)
//   16..19 UART0: DATA, STATUS, INT_ENABLE, reserved      (0xFFFFFF40..4C)
//   20..23 UART1: DATA, STATUS, INT_ENABLE, reserved      (0xFFFFFF50..5C)
//   24..27 UART2: DATA, STATUS, INT_ENABLE, reserved      (0xFFFFFF60..6C)
//   28..31 UART3: DATA, STATUS, INT_ENABLE, reserved      (0xFFFFFF70..7C)
//   32..39 SPI0-1              reserved (not yet implemented)
//   40     IRQ_SOURCE  RO      bit0 GPIO, bit1 UART0, bit2 UART1, bit3 UART2, bit4 UART3
//   41..47 reserved (future interrupt-controller expansion)
//   48..52 CLINT (msip, mtimecmp lo/hi, mtime lo/hi)       (0xFFFFFFC0..D0)
//   53..63 reserved
//
// Interrupts: each peripheral computes its own irq line from its own
// enable/pending state (GPIO_INT_* / UARTn_INT_ENABLE); TopLayer just ORs
// them onto the CPU's irq_external input alongside the genuine external pin.
// IRQ_SOURCE lets the trap handler tell which peripheral group fired without
// polling every device; the exact cause within that peripheral (which GPIO
// pin, RX vs TX) still comes from that peripheral's own registers.
//
// Instruction fetch addresses BRAM's unified Mem directly and never reaches
// MMIO; it now shares the same backing storage as load/store (see BRAM.v),
// so program-space constants are reachable by ordinary loads too.
module TopLayer #(
    parameter CLKS_PER_BIT = 16,
    parameter BOOTLOADER   = 1   // 1 = preload BRAM with the UART bootloader
                                 // at address 0 (see the boot_preload generate
                                 // block below). Off by default so existing
                                 // testbenches that load their own program
                                 // into BRAM are unaffected; a Verilator/C++
                                 // top level should instantiate this with
                                 // BOOTLOADER=1 so the compiled model boots
                                 // ready to receive a program over UART0
                                 // without any C++-side memory poking.
) (
    input  wire        clk,
    input  wire        rst,
    input  wire        irq_external,
    input  wire [31:0] gpio_in,
    output wire [31:0] gpio_out,
    input  wire [3:0]  uart_rx,
    output wire [3:0]  uart_tx
);

    localparam CLINT_MSIP      = 6'd48;
    localparam CLINT_MTIMECMPL = 6'd49;
    localparam CLINT_MTIMECMPH = 6'd50;
    localparam CLINT_MTIMEL    = 6'd51;
    localparam CLINT_MTIMEH    = 6'd52;
    localparam IRQ_SOURCE_SLOT = 6'd40;

    wire [15:0] mem_fetch_addr;
    wire [31:0] mem_read_addr;
    wire [31:0] mem_write_addr;
    wire [31:0] mem_data_in;
    wire [2:0]  mem_read_mode;
    wire [2:0]  mem_write_mode;
    wire [31:0] mem_data_out;
    wire [31:0] mem_instruction;

    wire timer_int;
    wire soft_int;

    // ---- interrupt aggregation (computed below, wired in here) ----
    wire gpio_irq;
    wire uart_irq0, uart_irq1, uart_irq2, uart_irq3;
    wire cpu_irq_external = irq_external | gpio_irq |
                             uart_irq0 | uart_irq1 | uart_irq2 | uart_irq3;

    CPU cpu (
        .clk(clk), .rst(rst),
        .irq_external(cpu_irq_external),
        .timer_int(timer_int), .soft_int(soft_int),
        .mem_fetch_addr(mem_fetch_addr),
        .mem_read_addr(mem_read_addr),
        .mem_write_addr(mem_write_addr),
        .mem_data_in(mem_data_in),
        .mem_read_mode(mem_read_mode),
        .mem_write_mode(mem_write_mode),
        .mem_data_out(mem_data_out),
        .mem_instruction(mem_instruction)
    );

    // ---- address decode ----
    wire read_is_mmio  = (mem_read_addr[31:8]  == 24'hFFFFFF);
    wire write_is_mmio = (mem_write_addr[31:8] == 24'hFFFFFF);
    wire [5:0] mmio_read_slot  = mem_read_addr[7:2];
    wire [5:0] mmio_write_slot = mem_write_addr[7:2];
    wire mmio_write_en = write_is_mmio && (mem_write_mode != 3'b111);
    wire mmio_read_en  = read_is_mmio  && (mem_read_mode  != 3'b111);

    wire [2:0] bram_write_mode = write_is_mmio ? 3'b111 : mem_write_mode;

    // ---- RAM ----
    wire [31:0] bram_data_out;
    BRAM bram (
        .clk(clk),
        .write_addr(mem_write_addr[15:0]),
        .read_addr(mem_read_addr[15:0]),
        .fetch_addr(mem_fetch_addr),
        .data_in(mem_data_in),
        .data_out(bram_data_out),
        .instruction_out(mem_instruction),
        .write_mode(bram_write_mode),
        .read_mode(mem_read_mode)
    );

    // ---- UART bootloader preload (BOOTLOADER=1 only) ----
    // Writes the boot words directly into bram.Mem at elaboration time (an
    // `initial` block, same mechanism FPGA tools use to give BRAM its power-on
    // contents). Protocol it implements: host sends a 4-byte little-endian
    // WORD count over UART0, then that many 32-bit words as 4 little-endian
    // bytes each; the loader stores them at PROG_BASE=0x1000 and jumps there.
    // See BootTb.v for a from-scratch simulation proof this actually runs.
    generate
        if (BOOTLOADER) begin : boot_preload
            integer bi;
            reg [31:0] boot_words [0:32];
            initial begin
                // Own the whole array's initial state ourselves (rather than
                // relying on a testbench-side zero-init loop racing this
                // `initial` block at time 0) so BOOTLOADER=1 is deterministic
                // on its own.
                for (bi = 0; bi < 65536; bi = bi + 1) bram.Mem[bi] = 8'h00;

                boot_words[ 0] = 32'hf4000093; // addi x1,x0,-192   UBASE = UART0 base
                boot_words[ 1] = 32'h00000113; // addi x2,x0,0      LEN = 0
                boot_words[ 2] = 32'h00000213; // addi x4,x0,0      CNT = byte-in-word counter
                boot_words[ 3] = 32'h0040a483; // LEN_BYTE: lw x9,4(x1)  STATUS
                boot_words[ 4] = 32'h0044f493; // andi x9,x9,4      RX_VALID bit
                boot_words[ 5] = 32'hfe048ce3; // beq x9,x0,LEN_BYTE
                boot_words[ 6] = 32'h0000a303; // lw x6,0(x1)       received byte
                boot_words[ 7] = 32'h00321393; // slli x7,x4,3
                boot_words[ 8] = 32'h00731433; // sll x8,x6,x7
                boot_words[ 9] = 32'h00816133; // or x2,x2,x8       LEN |= x8
                boot_words[10] = 32'h00120213; // addi x4,x4,1
                boot_words[11] = 32'h00400493; // addi x9,x0,4
                boot_words[12] = 32'hfc921ee3; // bne x4,x9,LEN_BYTE
                boot_words[13] = 32'h000011b7; // lui x3,0x1        DST = PROG_BASE = 0x1000
                boot_words[14] = 32'h04010263; // beq x2,x0,RUN     zero-length guard
                boot_words[15] = 32'h00000293; // WORD_LOOP: addi x5,x0,0  WORD = 0
                boot_words[16] = 32'h00000213; // addi x4,x0,0
                boot_words[17] = 32'h0040a483; // BYTE_LOOP: lw x9,4(x1)  STATUS
                boot_words[18] = 32'h0044f493; // andi x9,x9,4
                boot_words[19] = 32'hfe048ce3; // beq x9,x0,BYTE_LOOP
                boot_words[20] = 32'h0000a303; // lw x6,0(x1)
                boot_words[21] = 32'h00321393; // slli x7,x4,3
                boot_words[22] = 32'h00731433; // sll x8,x6,x7
                boot_words[23] = 32'h0082e2b3; // or x5,x5,x8       WORD |= x8
                boot_words[24] = 32'h00120213; // addi x4,x4,1
                boot_words[25] = 32'h00400493; // addi x9,x0,4
                boot_words[26] = 32'hfc921ee3; // bne x4,x9,BYTE_LOOP
                boot_words[27] = 32'h0051a023; // sw x5,0(x3)       store instruction word
                boot_words[28] = 32'h00418193; // addi x3,x3,4      DST += 4
                boot_words[29] = 32'hfff10113; // addi x2,x2,-1     LEN--
                boot_words[30] = 32'hfc0112e3; // bne x2,x0,WORD_LOOP
                boot_words[31] = 32'h000011b7; // RUN: lui x3,0x1   reload PROG_BASE
                boot_words[32] = 32'h00018067; // jalr x0,0(x3)     jump to the loaded program
                for (bi = 0; bi < 33; bi = bi + 1) begin
                    bram.Mem[bi*4+0] = boot_words[bi][7:0];
                    bram.Mem[bi*4+1] = boot_words[bi][15:8];
                    bram.Mem[bi*4+2] = boot_words[bi][23:16];
                    bram.Mem[bi*4+3] = boot_words[bi][31:24];
                end
            end
        end
    endgenerate

    // ---- GPIO bank: slots 0..8 ----
    wire [3:0]  gpio_waddr = mmio_write_slot[3:0];
    wire        gpio_we    = mmio_write_en && (mmio_write_slot <= 6'd8);
    wire [3:0]  gpio_raddr = mmio_read_slot[3:0];
    wire [31:0] gpio_rdata;
    GPIO #(.WIDTH(32)) gpio_bank (
        .clk(clk), .rst(rst),
        .pin_in(gpio_in),
        .pin_out(gpio_out),
        .waddr(gpio_waddr), .we(gpio_we), .wdata(mem_data_in),
        .raddr(gpio_raddr), .rdata(gpio_rdata),
        .irq(gpio_irq)
    );

    // ---- UART x4: slots 16..31 (base = 16 + 4*i; +0 DATA, +1 STATUS, +2 INT_ENABLE) ----
    wire [1:0] uart_reg_sel = mmio_read_slot[1:0];
    wire [31:0] uart_rdata0, uart_rdata1, uart_rdata2, uart_rdata3;
    UART #(.CLKS_PER_BIT(CLKS_PER_BIT)) uart0 (.clk(clk), .rst(rst), .rx(uart_rx[0]), .tx(uart_tx[0]),
        .wr_en(mmio_write_en && (mmio_write_slot == 6'd16)),
        .wr_data(mem_data_in[7:0]),
        .rd_data_en(mmio_read_en && (mmio_read_slot == 6'd16)),
        .ier_wr_en(mmio_write_en && (mmio_write_slot == 6'd18)),
        .ier_wr_data(mem_data_in[2:0]),
        .reg_sel(uart_reg_sel), .rdata(uart_rdata0), .irq(uart_irq0));
    UART #(.CLKS_PER_BIT(CLKS_PER_BIT)) uart1 (.clk(clk), .rst(rst), .rx(uart_rx[1]), .tx(uart_tx[1]),
        .wr_en(mmio_write_en && (mmio_write_slot == 6'd20)),
        .wr_data(mem_data_in[7:0]),
        .rd_data_en(mmio_read_en && (mmio_read_slot == 6'd20)),
        .ier_wr_en(mmio_write_en && (mmio_write_slot == 6'd22)),
        .ier_wr_data(mem_data_in[2:0]),
        .reg_sel(uart_reg_sel), .rdata(uart_rdata1), .irq(uart_irq1));
    UART #(.CLKS_PER_BIT(CLKS_PER_BIT)) uart2 (.clk(clk), .rst(rst), .rx(uart_rx[2]), .tx(uart_tx[2]),
        .wr_en(mmio_write_en && (mmio_write_slot == 6'd24)),
        .wr_data(mem_data_in[7:0]),
        .rd_data_en(mmio_read_en && (mmio_read_slot == 6'd24)),
        .ier_wr_en(mmio_write_en && (mmio_write_slot == 6'd26)),
        .ier_wr_data(mem_data_in[2:0]),
        .reg_sel(uart_reg_sel), .rdata(uart_rdata2), .irq(uart_irq2));
    UART #(.CLKS_PER_BIT(CLKS_PER_BIT)) uart3 (.clk(clk), .rst(rst), .rx(uart_rx[3]), .tx(uart_tx[3]),
        .wr_en(mmio_write_en && (mmio_write_slot == 6'd28)),
        .wr_data(mem_data_in[7:0]),
        .rd_data_en(mmio_read_en && (mmio_read_slot == 6'd28)),
        .ier_wr_en(mmio_write_en && (mmio_write_slot == 6'd30)),
        .ier_wr_data(mem_data_in[2:0]),
        .reg_sel(uart_reg_sel), .rdata(uart_rdata3), .irq(uart_irq3));

    // ---- IRQ_SOURCE: which peripheral group has a live interrupt ----
    wire [31:0] irq_source_word = {27'b0, uart_irq3, uart_irq2, uart_irq1, uart_irq0, gpio_irq};

    // ---- CLINT: memory-mapped timer + software interrupt ----
    reg [63:0] mtime;
    reg [63:0] mtimecmp;
    reg        msip;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            mtime <= 64'b0; mtimecmp <= 64'hFFFFFFFFFFFFFFFF; msip <= 1'b0;
        end else begin
            mtime <= mtime + 1;
            if (mmio_write_en) begin
                case (mmio_write_slot)
                    CLINT_MTIMECMPL: mtimecmp[31:0]  <= mem_data_in;
                    CLINT_MTIMECMPH: mtimecmp[63:32] <= mem_data_in;
                    CLINT_MTIMEL:    mtime[31:0]      <= mem_data_in;
                    CLINT_MTIMEH:    mtime[63:32]     <= mem_data_in;
                    CLINT_MSIP:      msip             <= mem_data_in[0];
                    default: ;
                endcase
            end
        end
    end
    assign timer_int = (mtime >= mtimecmp);
    assign soft_int  = msip;

    // ---- MMIO read data (combinational) ----
    reg [31:0] mmio_read_data;
    always @(*) begin
        if (mmio_read_slot <= 6'd8) begin
            mmio_read_data = gpio_rdata;
        end else if (mmio_read_slot >= 6'd16 && mmio_read_slot <= 6'd31) begin
            case (mmio_read_slot[5:2])
                4'd4:    mmio_read_data = uart_rdata0;
                4'd5:    mmio_read_data = uart_rdata1;
                4'd6:    mmio_read_data = uart_rdata2;
                4'd7:    mmio_read_data = uart_rdata3;
                default: mmio_read_data = 32'b0;
            endcase
        end else if (mmio_read_slot == IRQ_SOURCE_SLOT) begin
            mmio_read_data = irq_source_word;
        end else begin
            case (mmio_read_slot)
                CLINT_MSIP:      mmio_read_data = {31'b0, msip};
                CLINT_MTIMECMPL: mmio_read_data = mtimecmp[31:0];
                CLINT_MTIMECMPH: mmio_read_data = mtimecmp[63:32];
                CLINT_MTIMEL:    mmio_read_data = mtime[31:0];
                CLINT_MTIMEH:    mmio_read_data = mtime[63:32];
                default:         mmio_read_data = 32'b0;
            endcase
        end
    end

    // ---- registered read-source select (loads are registered K -> K+1) ----
    reg        read_was_mmio;
    reg [31:0] mmio_read_data_q;
    always @(posedge clk) begin
        read_was_mmio    <= read_is_mmio;
        mmio_read_data_q <= mmio_read_data;
    end
    assign mem_data_out = read_was_mmio ? mmio_read_data_q : bram_data_out;

endmodule
