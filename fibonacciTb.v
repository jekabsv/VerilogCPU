`timescale 1ns / 1ps

`include "CPU.v"

// Self-checking testbench for the NOVA CPU (RV32I + Zicsr): iterative Fibonacci.
// The program computes F(0..15) with a tight loop and stores each value as a
// word at 0x100 + i*4. The loop carries its state in registers with back-to-back
// true dependencies and NO hazard NOPs: in particular the loop branch reads the
// counter produced by the immediately preceding addi, so the program only runs
// correctly if GPR forwarding works. DataMem is zero-initialised.
//
//   x1 = a (prev)   x2 = b (curr)   x7 = next = a+b
//   x5 = i          x6 = N = 16     x10 = store pointer (0x100 + 4*i)
module Fibonacci_tb;
    reg clk = 0;
    reg rst = 1;
    integer errors = 0;
    integer i;

    CPU dut (.clk(clk), .rst(rst));
    always #5 clk = ~clk;

    localparam integer NWORDS = 15;
    reg [31:0] prog [0:NWORDS-1];

    task load_word; input integer idx; input [31:0] w; begin
        dut.bram.InstructionMem[idx*4+0] = w[7:0];
        dut.bram.InstructionMem[idx*4+1] = w[15:8];
        dut.bram.InstructionMem[idx*4+2] = w[23:16];
        dut.bram.InstructionMem[idx*4+3] = w[31:24];
    end endtask

    task ckreg; input [4:0] r; input [31:0] exp; begin
        if (dut.registry.registers[r] !== exp) begin
            errors = errors + 1;
            $display("  FAIL x%0d = %08h  expected %08h", r, dut.registry.registers[r], exp);
        end else $display("  ok   x%0d = %08h", r, exp);
    end endtask

    function [31:0] rdw; input [15:0] adr; begin
        rdw = {dut.bram.DataMem[adr+3], dut.bram.DataMem[adr+2], dut.bram.DataMem[adr+1], dut.bram.DataMem[adr]};
    end endfunction

    task ckword; input [15:0] adr; input [31:0] exp; input [255:0] nm; begin
        if (rdw(adr) !== exp) begin
            errors = errors + 1;
            $display("  FAIL %0s @ %04h = %08h  expected %08h", nm, adr, rdw(adr), exp);
        end else $display("  ok   %0s @ %04h = %08h", nm, adr, exp);
    end endtask

    initial begin
        for (i = 0; i < 65536; i = i + 1) dut.bram.DataMem[i] = 8'h00;

        prog[0] = 32'h00000013;   // 000: nop
        prog[1] = 32'h00000013;   // 004: nop
        prog[2] = 32'h00000093;   // 008: addi x1,x0,0     a = F0 = 0
        prog[3] = 32'h00100113;   // 00c: addi x2,x0,1     b = F1 = 1
        prog[4] = 32'h10000513;   // 010: addi x10,x0,256  ptr = 0x100
        prog[5] = 32'h00000293;   // 014: addi x5,x0,0     i = 0
        prog[6] = 32'h01000313;   // 018: addi x6,x0,16    N = 16
        prog[7] = 32'h00152023;   // 01c: sw  x1,0(x10)    store F(i) = a
        prog[8] = 32'h002083b3;   // 020: add x7,x1,x2     next = a + b
        prog[9] = 32'h00010093;   // 024: addi x1,x2,0     a = b
        prog[10] = 32'h00038113;   // 028: addi x2,x7,0     b = next
        prog[11] = 32'h00450513;   // 02c: addi x10,x10,4   ptr += 4
        prog[12] = 32'h00128293;   // 030: addi x5,x5,1     i++
        prog[13] = 32'hfe6294e3;   // 034: bne x5,x6,loop   (x5 fwd from prev addi) while i != N
        prog[14] = 32'h0000006f;   // 038: jal x0,0         halt / spin

        for (i = 0; i < NWORDS; i = i + 1) load_word(i, prog[i]);

        #12 rst = 0;
        #2500 ;

        $display("==== memory checks (F0..F15) ====");
        ckword(16'h0100, 32'h00000000, "F(0)");
        ckword(16'h0104, 32'h00000001, "F(1)");
        ckword(16'h0108, 32'h00000001, "F(2)");
        ckword(16'h010c, 32'h00000002, "F(3)");
        ckword(16'h0110, 32'h00000003, "F(4)");
        ckword(16'h0114, 32'h00000005, "F(5)");
        ckword(16'h0118, 32'h00000008, "F(6)");
        ckword(16'h011c, 32'h0000000d, "F(7)");
        ckword(16'h0120, 32'h00000015, "F(8)");
        ckword(16'h0124, 32'h00000022, "F(9)");
        ckword(16'h0128, 32'h00000037, "F(10)");
        ckword(16'h012c, 32'h00000059, "F(11)");
        ckword(16'h0130, 32'h00000090, "F(12)");
        ckword(16'h0134, 32'h000000e9, "F(13)");
        ckword(16'h0138, 32'h00000179, "F(14)");
        ckword(16'h013c, 32'h00000262, "F(15)");

        $display("==== register checks ====");
        ckreg(5'd1,  32'h000003db);
        ckreg(5'd2,  32'h0000063d);
        ckreg(5'd5,  32'h00000010);
        ckreg(5'd6,  32'h00000010);
        ckreg(5'd10, 32'h00000140);

        $display("========================");
        if (errors == 0) $display("ALL TESTS PASSED (%0d mem, %0d reg)", 16, 5);
        else $display("FAILED: %0d error(s)", errors);
        $finish;
    end
endmodule