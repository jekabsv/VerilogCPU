`timescale 1ns/1ps
`include "TopLayer.v"

// Independent UART checks (all UART0, DATA @ -128 / STATUS @ -124):
//   TX  : CPU transmits a byte; the testbench decodes the tx line in Verilog
//         and asserts the frame == what the program sent   (no RX involved)
//   RX  : the testbench bit-bangs a serial frame onto rx; the CPU polls
//         STATUS.RX_VALID, reads DATA, and it must equal the injected byte
//         (no TX involved)
//   LOOP: tx wired to rx; CPU sends and reads back            (integration)
//
// CLKS_PER_BIT is shrunk to 8 so a byte is fast to simulate. clk period 10ns
// => 1 bit = 80ns.
module UART_tb;
    localparam CPB   = 8;
    localparam BITNS = CPB*10;      // ns per serial bit

    reg clk=0, rst=1;
    integer i, k;
    always #5 clk=~clk;

    // ---- three independent systems ----
    reg  rx_drive = 1'b1;           // testbench-driven serial line into dut_rx
    wire [3:0] tx_of_tx;            // dut_tx transmit lines
    wire [3:0] tx_of_loop;

    TopLayer #(.CLKS_PER_BIT(CPB)) dut_tx (
        .clk(clk), .rst(rst), .irq_external(1'b0),
        .gpio_in(32'b0), .gpio_out(),
        .uart_rx(4'b1111), .uart_tx(tx_of_tx));

    TopLayer #(.CLKS_PER_BIT(CPB)) dut_rx (
        .clk(clk), .rst(rst), .irq_external(1'b0),
        .gpio_in(32'b0), .gpio_out(),
        .uart_rx({3'b111, rx_drive}), .uart_tx());

    TopLayer #(.CLKS_PER_BIT(CPB)) dut_loop (
        .clk(clk), .rst(rst), .irq_external(1'b0),
        .gpio_in(32'b0), .gpio_out(),
        .uart_rx({3'b111, tx_of_loop[0]}), .uart_tx(tx_of_loop));

    wire tx0 = tx_of_tx[0];

    // ---- programs ----
    reg [31:0] ptx  [0:3];
    reg [31:0] prx  [0:5];
    reg [31:0] plp  [0:7];

    task LT; input integer a; input [31:0] w; begin
        dut_tx.bram.InstructionMem[a*4+0]=w[7:0];   dut_tx.bram.InstructionMem[a*4+1]=w[15:8];
        dut_tx.bram.InstructionMem[a*4+2]=w[23:16]; dut_tx.bram.InstructionMem[a*4+3]=w[31:24]; end endtask
    task LR; input integer a; input [31:0] w; begin
        dut_rx.bram.InstructionMem[a*4+0]=w[7:0];   dut_rx.bram.InstructionMem[a*4+1]=w[15:8];
        dut_rx.bram.InstructionMem[a*4+2]=w[23:16]; dut_rx.bram.InstructionMem[a*4+3]=w[31:24]; end endtask
    task LL; input integer a; input [31:0] w; begin
        dut_loop.bram.InstructionMem[a*4+0]=w[7:0];   dut_loop.bram.InstructionMem[a*4+1]=w[15:8];
        dut_loop.bram.InstructionMem[a*4+2]=w[23:16]; dut_loop.bram.InstructionMem[a*4+3]=w[31:24]; end endtask

    // ---- testbench-side TX serial decoder (watches tx0) ----
    reg [7:0] tx_decoded; reg tx_done;
    initial begin
        tx_done = 0; tx_decoded = 8'h00;
        @(negedge tx0);                 // start bit edge
        #(BITNS + BITNS/2);             // center of data bit 0
        for (k=0; k<8; k=k+1) begin
            tx_decoded[k] = tx0;        // LSB first
            #(BITNS);
        end
        tx_done = 1;
    end

    // ---- testbench-side RX serial injector (drives rx_drive) ----
    localparam [7:0] RX_BYTE = 8'h3C;
    integer j;
    initial begin
        rx_drive = 1'b1;
        #300;                           // let reset settle
        rx_drive = 1'b0; #(BITNS);      // start bit
        for (j=0; j<8; j=j+1) begin
            rx_drive = RX_BYTE[j];      // LSB first
            #(BITNS);
        end
        rx_drive = 1'b1;                // stop / idle
    end

    integer errors = 0;
    initial begin
        for (i=0;i<65536;i=i+1) begin
            dut_tx.bram.DataMem[i]=8'h00; dut_rx.bram.DataMem[i]=8'h00; dut_loop.bram.DataMem[i]=8'h00;
        end
        // TX program: send 0x5A on UART0
        ptx[0]=32'hf8000293; ptx[1]=32'h05a00313; ptx[2]=32'h0062a023; ptx[3]=32'h0000006f;
        // RX program: poll STATUS.RX_VALID, read DATA -> x7
        prx[0]=32'hf8000293; prx[1]=32'h0042a083; prx[2]=32'h0040f093;
        prx[3]=32'hfe008ce3; prx[4]=32'h0002a383; prx[5]=32'h0000006f;
        // LOOP program: send 0x41, receive -> x7
        plp[0]=32'hf8000293; plp[1]=32'h04100313; plp[2]=32'h0062a023; plp[3]=32'h0042a083;
        plp[4]=32'h0040f093; plp[5]=32'hfe008ce3; plp[6]=32'h0002a383; plp[7]=32'h0000006f;
        for (i=0;i<4;i=i+1) LT(i,ptx[i]);
        for (i=0;i<6;i=i+1) LR(i,prx[i]);
        for (i=0;i<8;i=i+1) LL(i,plp[i]);

        #12 rst=0;
        #8000;

        $display("==== UART checks ====");
        // TX: byte transmitted by CPU, decoded off the wire by the testbench
        if (tx_done && tx_decoded===8'h5A)
            $display("  ok   TX  : CPU transmitted 0x5A, decoded 0x%02h off tx line", tx_decoded);
        else begin errors=errors+1;
            $display("  FAIL TX  : decoded 0x%02h (done=%0d) expected 0x5A", tx_decoded, tx_done); end

        // RX: byte injected on rx by the testbench, received by the CPU
        if (dut_rx.cpu.registry.registers[7]===32'h0000003C)
            $display("  ok   RX  : CPU received injected byte 0x3C (x7=0x%08h)", dut_rx.cpu.registry.registers[7]);
        else begin errors=errors+1;
            $display("  FAIL RX  : x7=0x%08h expected 0x0000003C", dut_rx.cpu.registry.registers[7]); end

        // LOOP: full round trip under program control
        if (dut_loop.cpu.registry.registers[7]===32'h00000041)
            $display("  ok   LOOP: CPU sent+received 0x41 (x7=0x%08h)", dut_loop.cpu.registry.registers[7]);
        else begin errors=errors+1;
            $display("  FAIL LOOP: x7=0x%08h expected 0x00000041", dut_loop.cpu.registry.registers[7]); end

        $display("====================");
        if (errors==0) $display("ALL UART TESTS PASSED (TX, RX, LOOP)");
        else $display("UART FAILED: %0d error(s)", errors);
        $finish;
    end
endmodule