`timescale 1ns/1ps
`include "TopLayer.v"

// Verifies the UART bootloader as it's actually meant to be used: instantiate
// TopLayer with BOOTLOADER=1 (no manual memory poking at all -- that's the
// point) and bit-bang a length-prefixed program over uart_rx[0], then check
// the loaded program actually ran after jumping to PROG_BASE = 0x1000.
//
// This is also the reference for driving TopLayer from a Verilator/C++
// harness: preload nothing yourself, just instantiate with BOOTLOADER=1 and
// drive uart_rx per send_byte's framing every eval() step.
module Boot_tb;
    localparam CPB = 8;
    localparam BITNS = CPB*10;

    reg clk=0, rst=1;
    reg rx_drive = 1'b1;
    always #5 clk=~clk;

    TopLayer #(.CLKS_PER_BIT(CPB), .BOOTLOADER(1)) dut (
        .clk(clk), .rst(rst), .irq_external(1'b0),
        .gpio_in(32'b0), .gpio_out(),
        .uart_rx({3'b111, rx_drive}), .uart_tx());

    // ---- send one byte, LSB first, 8N1 framing ----
    task send_byte; input [7:0] b; integer k; begin
        rx_drive = 1'b0; #(BITNS);            // start bit
        for (k=0; k<8; k=k+1) begin
            rx_drive = b[k];
            #(BITNS);
        end
        rx_drive = 1'b1; #(BITNS);            // stop bit
    end endtask

    task send_word32; input [31:0] w; begin
        send_byte(w[7:0]);
        send_byte(w[15:8]);
        send_byte(w[23:16]);
        send_byte(w[31:24]);
    end endtask

    integer errors = 0;
    initial begin
        #12 rst = 0;
        #300;                       // reset settle (BOOTLOADER preload already happened at t=0)

        send_word32(32'd2);         // length = 2 words
        send_word32(32'h05500093);  // addi x1,x0,0x55
        send_word32(32'h0000006f);  // jal x0,0 (spin)

        #2000;

        $display("PC=%08h", dut.cpu.PC);
        $display("x1=%08h", dut.cpu.registry.registers[1]);
        if (dut.cpu.registry.registers[1] !== 32'h00000055) begin
            errors = errors + 1;
            $display("FAIL: x1 = %08h expected 00000055 (loaded program did not run)", dut.cpu.registry.registers[1]);
        end else $display("ok: x1 = 55 -- loaded program executed");

        if (dut.cpu.PC < 32'h1000 || dut.cpu.PC > 32'h1010) begin
            errors = errors + 1;
            $display("FAIL: PC = %08h expected to be spinning near 0x1000", dut.cpu.PC);
        end else $display("ok: PC spinning at %08h (inside loaded program)", dut.cpu.PC);

        if (errors == 0) $display("BOOTLOADER TEST PASSED");
        else $display("BOOTLOADER TEST FAILED: %0d error(s)", errors);
        $finish;
    end
endmodule