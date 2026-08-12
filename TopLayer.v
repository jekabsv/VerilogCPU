`include "CPU.v"
`include "BRAM.v"
`include "GPIO.v"
`include "UART.v"

// TopLayer: CPU + RAM (BRAM) + MMIO (GPIO bank, 4x UART, CLINT) rerouting.
//
// Address map (load/store effective address is full 32-bit from the CPU):
//   0x00000000 .. 0x0000FFFF   RAM  (BRAM DataMem, indexed by addr[15:0])
//   0xFFFFFF00 .. 0xFFFFFFFF   MMIO (top 256 bytes = 64 word slots)
//
// MMIO slot = addr[7:2] (0..63):
//   0..31  GPIO pin 0..31       ({31'b0,in_latch} read; bit0 -> out_latch)
//   32..39 UART0..3 (2 each)    even=DATA, odd=STATUS  (0xFFFFFF80..9C)
//   40..41 SPI0..1              reserved (not yet implemented)
//   48..52 CLINT (msip, mtimecmp lo/hi, mtime lo/hi)   (0xFFFFFFC0..D0)
//   others reserved
//
// Instruction fetch uses BRAM.InstructionMem only and never reaches MMIO.
module TopLayer #(
    parameter CLKS_PER_BIT = 16
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

    CPU cpu (
        .clk(clk), .rst(rst),
        .irq_external(irq_external),
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

    // ---- GPIO bank: one controller per pin, slots 0..31 ----
    wire [31:0] gpio_out_bits;
    wire [31:0] gpio_read_bits;
    genvar gi;
    generate
        for (gi = 0; gi < 32; gi = gi + 1) begin : gpio_bank
            GPIO gpio_pin (
                .clk(clk), .rst(rst),
                .pin_in(gpio_in[gi]),
                .pin_out(gpio_out_bits[gi]),
                .write_en(mmio_write_en && (mmio_write_slot == gi)),
                .write_bit(mem_data_in[0]),
                .read_bit(gpio_read_bits[gi])
            );
        end
    endgenerate
    assign gpio_out = gpio_out_bits;

    // ---- UART x4: slots 32..39 (base = 32 + 2*i; even=DATA, odd=STATUS) ----
    // uart index = slot[2:1], reg_sel (0=DATA,1=STATUS) = slot[0].
    wire [31:0] uart_rdata0, uart_rdata1, uart_rdata2, uart_rdata3;
    UART #(.CLKS_PER_BIT(CLKS_PER_BIT)) uart0 (.clk(clk), .rst(rst), .rx(uart_rx[0]), .tx(uart_tx[0]),
        .wr_en(mmio_write_en && (mmio_write_slot == 6'd32)),
        .wr_data(mem_data_in[7:0]),
        .rd_data_en(mmio_read_en && (mmio_read_slot == 6'd32)),
        .rd_sel(mmio_read_slot == 6'd33), .rdata(uart_rdata0));
    UART #(.CLKS_PER_BIT(CLKS_PER_BIT)) uart1 (.clk(clk), .rst(rst), .rx(uart_rx[1]), .tx(uart_tx[1]),
        .wr_en(mmio_write_en && (mmio_write_slot == 6'd34)),
        .wr_data(mem_data_in[7:0]),
        .rd_data_en(mmio_read_en && (mmio_read_slot == 6'd34)),
        .rd_sel(mmio_read_slot == 6'd35), .rdata(uart_rdata1));
    UART #(.CLKS_PER_BIT(CLKS_PER_BIT)) uart2 (.clk(clk), .rst(rst), .rx(uart_rx[2]), .tx(uart_tx[2]),
        .wr_en(mmio_write_en && (mmio_write_slot == 6'd36)),
        .wr_data(mem_data_in[7:0]),
        .rd_data_en(mmio_read_en && (mmio_read_slot == 6'd36)),
        .rd_sel(mmio_read_slot == 6'd37), .rdata(uart_rdata2));
    UART #(.CLKS_PER_BIT(CLKS_PER_BIT)) uart3 (.clk(clk), .rst(rst), .rx(uart_rx[3]), .tx(uart_tx[3]),
        .wr_en(mmio_write_en && (mmio_write_slot == 6'd38)),
        .wr_data(mem_data_in[7:0]),
        .rd_data_en(mmio_read_en && (mmio_read_slot == 6'd38)),
        .rd_sel(mmio_read_slot == 6'd39), .rdata(uart_rdata3));

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
        if (mmio_read_slot < 6'd32) begin
            mmio_read_data = {31'b0, gpio_read_bits[mmio_read_slot[4:0]]};
        end else if (mmio_read_slot <= 6'd39) begin
            case (mmio_read_slot[2:1])
                2'd0: mmio_read_data = uart_rdata0;
                2'd1: mmio_read_data = uart_rdata1;
                2'd2: mmio_read_data = uart_rdata2;
                2'd3: mmio_read_data = uart_rdata3;
            endcase
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