`timescale 1ns / 1ps

`include "TopLayer.v"

// Self-checking testbench for the NOVA CPU (RV32I + Zicsr + traps).
// Base program (prog[0..226]) is unchanged. The old spin at prog[227] is
// replaced by a trap/interrupt test driver (prog[227..255]) and a shared trap
// handler (prog[256..268]).
//
// Trap section (all traps go through mtvec, handler logs {mcause,mtval} to
// DataMem starting at 1024 and advances an 8-byte cursor in x7):
//   - ECALL   -> mcause 11, mtval 0
//   - EBREAK  -> mcause 3,  mtval = PC of the EBREAK
//   - illegal -> mcause 2,  mtval = instruction word (0x0000000b)
//   - timer   -> mcause 0x80000007 (armed via mtimecmp=0, mie.MTIE, mstatus.MIE)
//   - external-> mcause 0x8000000b (driven on the new irq_external input)
// The handler advances mepc past exceptions and disables mie on interrupts so
// nothing re-fires. Only x1/x6/x7 are used by the trap code, so none of the
// base-program register checks are disturbed.
module CPU_tb;
    reg clk = 0;
    reg rst = 1;
    reg irq_external = 0;
    integer errors = 0;
    integer i;

    reg  [31:0] gpio_in_r;
    wire [31:0] gpio_out_w;
    TopLayer dut (.clk(clk), .rst(rst), .irq_external(irq_external),
                  .gpio_in(gpio_in_r), .gpio_out(gpio_out_w),
                  .uart_rx(4'b1111), .uart_tx());
    always #5 clk = ~clk;

    localparam integer NWORDS = 286;
    reg [31:0] prog [0:NWORDS-1];

    task load_word; input integer idx; input [31:0] w; begin
        dut.bram.InstructionMem[idx*4+0] = w[7:0];
        dut.bram.InstructionMem[idx*4+1] = w[15:8];
        dut.bram.InstructionMem[idx*4+2] = w[23:16];
        dut.bram.InstructionMem[idx*4+3] = w[31:24];
    end endtask

    task ckreg; input [4:0] r; input [31:0] exp; begin
        if (dut.cpu.registry.registers[r] !== exp) begin
            errors = errors + 1;
            $display("  FAIL x%0d = %08h  expected %08h", r, dut.cpu.registry.registers[r], exp);
        end else $display("  ok   x%0d = %08h", r, exp);
    end endtask

    task ckmem; input [15:0] adr; input [7:0] exp; begin
        if (dut.bram.DataMem[adr] !== exp) begin
            errors = errors + 1;
            $display("  FAIL mem[%04h] = %02h  expected %02h", adr, dut.bram.DataMem[adr], exp);
        end
    end endtask

    function [31:0] rdw; input [15:0] adr; begin
        rdw = {dut.bram.DataMem[adr+3], dut.bram.DataMem[adr+2], dut.bram.DataMem[adr+1], dut.bram.DataMem[adr]};
    end endfunction

    task ckfw; input [15:0] adr; input [31:0] exp; input [255:0] nm; begin
        if (rdw(adr) !== exp) begin
            errors = errors + 1;
            $display("  FAIL %0s = %08h  expected %08h", nm, rdw(adr), exp);
        end else $display("  ok   %0s = %08h", nm, exp);
    end endtask

    task cklog; input [15:0] adr; input [31:0] exp; input [255:0] nm; begin
        if (rdw(adr) !== exp) begin
            errors = errors + 1;
            $display("  FAIL %0s = %08h  expected %08h", nm, rdw(adr), exp);
        end else $display("  ok   %0s = %08h", nm, exp);
    end endtask

    initial begin
        for (i = 0; i < 65536; i = i + 1) dut.bram.DataMem[i] = 8'h00;
        for (i = 0; i < NWORDS; i = i + 1) prog[i] = 32'h00000013;
        gpio_in_r = 32'b0; gpio_in_r[3] = 1'b1; gpio_in_r[7] = 1'b1;

        prog[0] = 32'h00000013;   // 000: nop
        prog[1] = 32'h00000013;   // 004: nop
        prog[2] = 32'h00000013;   // 008: nop
        prog[3] = 32'h00000013;   // 00c: nop
        prog[4] = 32'h00c00093;   // 010: addi x1,x0,12
        prog[5] = 32'h00500113;   // 014: addi x2,x0,5
        prog[6] = 32'hfec00313;   // 018: addi x6,x0,-20
        prog[7] = 32'h10000193;   // 01c: addi x3,x0,256
        prog[8] = 32'h00000013;   // 020: nop
        prog[9] = 32'h00000013;   // 024: nop
        prog[10] = 32'h00308413;   // 028: addi x8,x1,3
        prog[11] = 32'h00032493;   // 02c: slti x9,x6,0
        prog[12] = 32'h0640b513;   // 030: sltiu x10,x1,100
        prog[13] = 32'h00f0c593;   // 034: xori x11,x1,15
        prog[14] = 32'h0010e613;   // 038: ori x12,x1,1
        prog[15] = 32'h0060f693;   // 03c: andi x13,x1,6
        prog[16] = 32'h00409713;   // 040: slli x14,x1,4
        prog[17] = 32'h0020d793;   // 044: srli x15,x1,2
        prog[18] = 32'h40235813;   // 048: srai x16,x6,2
        prog[19] = 32'h002088b3;   // 04c: add x17,x1,x2
        prog[20] = 32'h40208933;   // 050: sub x18,x1,x2
        prog[21] = 32'h002099b3;   // 054: sll x19,x1,x2
        prog[22] = 32'h00232a33;   // 058: slt x20,x6,x2
        prog[23] = 32'h0020bab3;   // 05c: sltu x21,x1,x2
        prog[24] = 32'h0020cb33;   // 060: xor x22,x1,x2
        prog[25] = 32'h0020dbb3;   // 064: srl x23,x1,x2
        prog[26] = 32'h40235c33;   // 068: sra x24,x6,x2
        prog[27] = 32'h0020ecb3;   // 06c: or x25,x1,x2
        prog[28] = 32'h0020fd33;   // 070: and x26,x1,x2
        prog[29] = 32'habcdedb7;   // 074: lui x27,0xabcde
        prog[30] = 32'h00001e17;   // 078: auipc x28,0x1
        prog[31] = 32'h07f00093;   // 07c: addi x1,x0,127
        prog[32] = 32'hfff00113;   // 080: addi x2,x0,-1
        prog[33] = 32'h00000013;   // 084: nop
        prog[34] = 32'h00000013;   // 088: nop
        prog[35] = 32'h00218823;   // 08c: sb x2,16(x3)
        prog[36] = 32'h001188a3;   // 090: sb x1,17(x3)
        prog[37] = 32'h00218923;   // 094: sb x2,18(x3)
        prog[38] = 32'h001189a3;   // 098: sb x1,19(x3)
        prog[39] = 32'h00000013;   // 09c: nop
        prog[40] = 32'h00000013;   // 0a0: nop
        prog[41] = 32'h0101ae83;   // 0a4: lw x29,16(x3)
        prog[42] = 32'h01018f03;   // 0a8: lb x30,16(x3)
        prog[43] = 32'h0101cf83;   // 0ac: lbu x31,16(x3)
        prog[44] = 32'h01019203;   // 0b0: lh x4,16(x3)
        prog[45] = 32'h0101d283;   // 0b4: lhu x5,16(x3)
        prog[46] = 32'h00119a23;   // 0b8: sh x1,20(x3)
        prog[47] = 32'h0081ac23;   // 0bc: sw x8,24(x3)
        prog[48] = 32'h3402d0f3;   // 0c0: csrrwi x1,0x340,5
        prog[49] = 32'h00000013;   // 0c4: nop
        prog[50] = 32'h00000013;   // 0c8: nop
        prog[51] = 32'h0211a823;   // 0cc: sw x1,48(x3)
        prog[52] = 32'h340160f3;   // 0d0: csrrsi x1,0x340,2
        prog[53] = 32'h00000013;   // 0d4: nop
        prog[54] = 32'h00000013;   // 0d8: nop
        prog[55] = 32'h0211aa23;   // 0dc: sw x1,52(x3)
        prog[56] = 32'h3400f0f3;   // 0e0: csrrci x1,0x340,1
        prog[57] = 32'h00000013;   // 0e4: nop
        prog[58] = 32'h00000013;   // 0e8: nop
        prog[59] = 32'h0211ac23;   // 0ec: sw x1,56(x3)
        prog[60] = 32'h03000393;   // 0f0: addi x7,x0,48
        prog[61] = 32'h00000013;   // 0f4: nop
        prog[62] = 32'h00000013;   // 0f8: nop
        prog[63] = 32'h340390f3;   // 0fc: csrrw x1,0x340,x7
        prog[64] = 32'h00000013;   // 100: nop
        prog[65] = 32'h00000013;   // 104: nop
        prog[66] = 32'h0211ae23;   // 108: sw x1,60(x3)
        prog[67] = 32'h00f00393;   // 10c: addi x7,x0,15
        prog[68] = 32'h00000013;   // 110: nop
        prog[69] = 32'h00000013;   // 114: nop
        prog[70] = 32'h3403a0f3;   // 118: csrrs x1,0x340,x7
        prog[71] = 32'h00000013;   // 11c: nop
        prog[72] = 32'h00000013;   // 120: nop
        prog[73] = 32'h0411a023;   // 124: sw x1,64(x3)
        prog[74] = 32'h00100393;   // 128: addi x7,x0,1
        prog[75] = 32'h00000013;   // 12c: nop
        prog[76] = 32'h00000013;   // 130: nop
        prog[77] = 32'h3403b0f3;   // 134: csrrc x1,0x340,x7
        prog[78] = 32'h00000013;   // 138: nop
        prog[79] = 32'h00000013;   // 13c: nop
        prog[80] = 32'h0411a223;   // 140: sw x1,68(x3)
        prog[81] = 32'h0000000f;   // 144: fence
        prog[82] = 32'h01100313;   // 148: addi x6,x0,17
        prog[83] = 32'h00000013;   // 14c: nop
        prog[84] = 32'h00000013;   // 150: nop
        prog[85] = 32'h00500093;   // 154: addi x1,x0,5
        prog[86] = 32'h00500113;   // 158: addi x2,x0,5
        prog[87] = 32'h00000013;   // 15c: nop
        prog[88] = 32'h00000013;   // 160: nop
        prog[89] = 32'h00208463;   // 164: beq x1,x2,BEQ_T
        prog[90] = 32'h06618023;   // 168: sb x6,96(x3)
        prog[91] = 32'h06618223;   // 16c: sb x6,100(x3)
        prog[92] = 32'h00500093;   // 170: addi x1,x0,5
        prog[93] = 32'h00600113;   // 174: addi x2,x0,6
        prog[94] = 32'h00000013;   // 178: nop
        prog[95] = 32'h00000013;   // 17c: nop
        prog[96] = 32'h00209463;   // 180: bne x1,x2,BNE_T
        prog[97] = 32'h06618423;   // 184: sb x6,104(x3)
        prog[98] = 32'h06618623;   // 188: sb x6,108(x3)
        prog[99] = 32'hfff00093;   // 18c: addi x1,x0,-1
        prog[100] = 32'h00100113;   // 190: addi x2,x0,1
        prog[101] = 32'h00000013;   // 194: nop
        prog[102] = 32'h00000013;   // 198: nop
        prog[103] = 32'h0020c463;   // 19c: blt x1,x2,BLT_T
        prog[104] = 32'h06618823;   // 1a0: sb x6,112(x3)
        prog[105] = 32'h06618a23;   // 1a4: sb x6,116(x3)
        prog[106] = 32'h00100093;   // 1a8: addi x1,x0,1
        prog[107] = 32'hfff00113;   // 1ac: addi x2,x0,-1
        prog[108] = 32'h00000013;   // 1b0: nop
        prog[109] = 32'h00000013;   // 1b4: nop
        prog[110] = 32'h0020d463;   // 1b8: bge x1,x2,BGE_T
        prog[111] = 32'h06618c23;   // 1bc: sb x6,120(x3)
        prog[112] = 32'h06618e23;   // 1c0: sb x6,124(x3)
        prog[113] = 32'h00100093;   // 1c4: addi x1,x0,1
        prog[114] = 32'h00200113;   // 1c8: addi x2,x0,2
        prog[115] = 32'h00000013;   // 1cc: nop
        prog[116] = 32'h00000013;   // 1d0: nop
        prog[117] = 32'h0020e463;   // 1d4: bltu x1,x2,BLTU_T
        prog[118] = 32'h08618023;   // 1d8: sb x6,128(x3)
        prog[119] = 32'h08618223;   // 1dc: sb x6,132(x3)
        prog[120] = 32'h00200093;   // 1e0: addi x1,x0,2
        prog[121] = 32'h00100113;   // 1e4: addi x2,x0,1
        prog[122] = 32'h00000013;   // 1e8: nop
        prog[123] = 32'h00000013;   // 1ec: nop
        prog[124] = 32'h0020f463;   // 1f0: bgeu x1,x2,BGEU_T
        prog[125] = 32'h08618423;   // 1f4: sb x6,136(x3)
        prog[126] = 32'h08618623;   // 1f8: sb x6,140(x3)
        prog[127] = 32'h00500093;   // 1fc: addi x1,x0,5
        prog[128] = 32'h00900113;   // 200: addi x2,x0,9
        prog[129] = 32'h00000013;   // 204: nop
        prog[130] = 32'h00000013;   // 208: nop
        prog[131] = 32'h00208463;   // 20c: beq x1,x2,BEQ_NT_SKIP
        prog[132] = 32'h08618823;   // 210: sb x6,144(x3)
        prog[133] = 32'h08618a23;   // 214: sb x6,148(x3)
        prog[134] = 32'h008000ef;   // 218: jal x1,JAL_TGT
        prog[135] = 32'h0a618023;   // 21c: sb x6,160(x3)
        prog[136] = 32'h00000013;   // 220: nop
        prog[137] = 32'h00000013;   // 224: nop
        prog[138] = 32'h0a11a223;   // 228: sw x1,164(x3)
        prog[139] = 32'h0a618423;   // 22c: sb x6,168(x3)
        prog[140] = 32'h24400393;   // 230: addi x7,x0,580
        prog[141] = 32'h00000013;   // 234: nop
        prog[142] = 32'h00000013;   // 238: nop
        prog[143] = 32'h00038167;   // 23c: jalr x2,0(x7)
        prog[144] = 32'h0a618823;   // 240: sb x6,176(x3)
        prog[145] = 32'h00000013;   // 244: nop
        prog[146] = 32'h00000013;   // 248: nop
        prog[147] = 32'h0a21aa23;   // 24c: sw x2,180(x3)
        prog[148] = 32'h0a618c23;   // 250: sb x6,184(x3)
        prog[149] = 32'h00a00093;   // 254: addi x1,x0,10
        prog[150] = 32'h00508113;   // 258: addi x2,x1,5
        prog[151] = 32'h00000013;   // 25c: nop
        prog[152] = 32'h00000013;   // 260: nop
        prog[153] = 32'h0c21a023;   // 264: sw x2,192(x3)
        prog[154] = 32'h06400093;   // 268: addi x1,x0,100
        prog[155] = 32'h40100133;   // 26c: sub x2,x0,x1
        prog[156] = 32'h00000013;   // 270: nop
        prog[157] = 32'h00000013;   // 274: nop
        prog[158] = 32'h0c21a223;   // 278: sw x2,196(x3)
        prog[159] = 32'h00700093;   // 27c: addi x1,x0,7
        prog[160] = 32'h00108133;   // 280: add x2,x1,x1
        prog[161] = 32'h00000013;   // 284: nop
        prog[162] = 32'h00000013;   // 288: nop
        prog[163] = 32'h0c21a423;   // 28c: sw x2,200(x3)
        prog[164] = 32'h00100093;   // 290: addi x1,x0,1
        prog[165] = 32'h00108093;   // 294: addi x1,x1,1
        prog[166] = 32'h00108093;   // 298: addi x1,x1,1
        prog[167] = 32'h00108093;   // 29c: addi x1,x1,1
        prog[168] = 32'h00000013;   // 2a0: nop
        prog[169] = 32'h00000013;   // 2a4: nop
        prog[170] = 32'h0c11a623;   // 2a8: sw x1,204(x3)
        prog[171] = 32'h07700093;   // 2ac: addi x1,x0,0x77
        prog[172] = 32'h03300113;   // 2b0: addi x2,x0,0x33
        prog[173] = 32'h0e21a023;   // 2b4: sw x2,224(x3)
        prog[174] = 32'h00000013;   // 2b8: nop
        prog[175] = 32'h00000013;   // 2bc: nop
        prog[176] = 32'h00000013;   // 2c0: nop
        prog[177] = 32'h0e01a083;   // 2c4: lw x1,224(x3)
        prog[178] = 32'h00008113;   // 2c8: addi x2,x1,0
        prog[179] = 32'h00000013;   // 2cc: nop
        prog[180] = 32'h00000013;   // 2d0: nop
        prog[181] = 32'h0c21a823;   // 2d4: sw x2,208(x3)
        prog[182] = 32'h06300013;   // 2d8: addi x0,x0,99
        prog[183] = 32'h00000113;   // 2dc: addi x2,x0,0
        prog[184] = 32'h00000013;   // 2e0: nop
        prog[185] = 32'h00000013;   // 2e4: nop
        prog[186] = 32'h0c21aa23;   // 2e8: sw x2,212(x3)
        prog[187] = 32'h04200093;   // 2ec: addi x1,x0,0x42
        prog[188] = 32'h0c11ac23;   // 2f0: sw x1,216(x3)
        prog[189] = 32'h00000013;   // 2f4: nop
        prog[190] = 32'h00000013;   // 2f8: nop
        prog[191] = 32'h03700093;   // 2fc: addi x1,x0,55
        prog[192] = 32'h00000013;   // 300: nop
        prog[193] = 32'h00000013;   // 304: nop
        prog[194] = 32'h03700113;   // 308: addi x2,x0,55
        prog[195] = 32'h00208663;   // 30c: beq x1,x2,+12
        prog[196] = 32'h0bb00093;   // 310: addi x1,x0,0xBB
        prog[197] = 32'h0080006f;   // 314: jal x0,+8
        prog[198] = 32'h0aa00093;   // 318: addi x1,x0,0xAA
        prog[199] = 32'h00000013;   // 31c: nop
        prog[200] = 32'h00000013;   // 320: nop
        prog[201] = 32'h0c11ae23;   // 324: sw x1,220(x3)
        prog[202] = 32'h06400093;   // 328: addi x1,x0,100
        prog[203] = 32'h00000013;   // 32c: nop
        prog[204] = 32'h00000013;   // 330: nop
        prog[205] = 32'h05a00113;   // 334: addi x2,x0,0x5A
        prog[206] = 32'h00000013;   // 338: nop
        prog[207] = 32'h00000013;   // 33c: nop
        prog[208] = 32'h10000093;   // 340: addi x1,x0,256
        prog[209] = 32'h0e208223;   // 344: sb x2,228(x1)
        prog[210] = 32'h35c00393;   // 348: addi x7,x0,POISON
        prog[211] = 32'h00000013;   // 34c: nop
        prog[212] = 32'h00000013;   // 350: nop
        prog[213] = 32'h37000393;   // 354: addi x7,x0,GOOD
        prog[214] = 32'h00038067;   // 358: jalr x0,0(x7)
        prog[215] = 32'h0bd00093;   // 35c: addi x1,x0,0xBD
        prog[216] = 32'h00000013;   // 360: nop
        prog[217] = 32'h00000013;   // 364: nop
        prog[218] = 32'h0e11a423;   // 368: sw x1,232(x3)
        prog[219] = 32'h0000006f;   // 36c: jal x0,0
        prog[220] = 32'h06c00093;   // 370: addi x1,x0,0x6C
        prog[221] = 32'h00000013;   // 374: nop
        prog[222] = 32'h00000013;   // 378: nop
        prog[223] = 32'h0e11a423;   // 37c: sw x1,232(x3)
        prog[224] = 32'h3000d0f3;   // 380: csrrwi x1,0x300,1
        prog[225] = 32'h30002173;   // 384: csrrs x2,0x300,x0
        prog[226] = 32'h0e21a823;   // 388: sw x2,240(x3)

        // ===== trap / interrupt test section (timer armed via memory-mapped CLINT) =====
        prog[227] = 32'h40400093;   // addi x1,x0,0x404 (mtvec=handler)
        prog[228] = 32'h30509073;   // csrrw x0,mtvec,x1
        prog[229] = 32'h40000393;   // addi x7,x0,1024 log base
        prog[230] = 32'h00000073;   // ECALL
        prog[231] = 32'h00000013;   // nop
        prog[232] = 32'h00000013;   // nop
        prog[233] = 32'h00100073;   // EBREAK @0x3a4
        prog[234] = 32'h00000013;   // nop
        prog[235] = 32'h00000013;   // nop
        prog[236] = 32'h0000000b;   // illegal 0x0000000b
        prog[237] = 32'h00000013;   // nop
        prog[238] = 32'h00000013;   // nop
        prog[239] = 32'hfc400093;   // addi x1,x0,-60  x1=0xFFFFFFC4 CLINT mtimecmp lo
        prog[240] = 32'h0000a023;   // sw x0,0(x1)  mtimecmp lo=0
        prog[241] = 32'h0000a223;   // sw x0,4(x1)  mtimecmp hi=0
        prog[242] = 32'h08000093;   // addi x1,x0,0x80
        prog[243] = 32'h30409073;   // csrrw x0,mie,x1  MTIE
        prog[244] = 32'h30046073;   // csrrsi x0,mstatus,8  MIE
        prog[245] = 32'h00000013;   // nop (timer fires)
        prog[246] = 32'h00000013;   // nop
        prog[247] = 32'h00000013;   // nop
        prog[248] = 32'h00000013;   // nop
        prog[249] = 32'h00100093;   // addi x1,x0,1
        prog[250] = 32'h00b09093;   // slli x1,x1,11  x1=0x800
        prog[251] = 32'h30409073;   // csrrw x0,mie,x1  MEIE
        prog[252] = 32'h00000013;   // nop (external fires)
        prog[253] = 32'h00000013;   // nop
        prog[254] = 32'h00000013;   // nop
        prog[255] = 32'h00000013;   // nop
        prog[256] = 32'h0380006f;   // jal x0,+56  (skip handler -> GPIO section)
        prog[257] = 32'h342020f3;   // H: csrrs x1,mcause,x0
        prog[258] = 32'h0013a023;   // sw x1,0(x7)
        prog[259] = 32'h343020f3;   // csrrs x1,mtval,x0
        prog[260] = 32'h0013a223;   // sw x1,4(x7)
        prog[261] = 32'h00838393;   // addi x7,x7,8
        prog[262] = 32'h342020f3;   // csrrs x1,mcause,x0
        prog[263] = 32'h0000ca63;   // blt x1,x0,INT
        prog[264] = 32'h34102373;   // csrrs x6,mepc,x0
        prog[265] = 32'h00430313;   // addi x6,x6,4
        prog[266] = 32'h34131073;   // csrrw x0,mepc,x6
        prog[267] = 32'h0080006f;   // jal x0,DONE
        prog[268] = 32'h30401073;   // INT: csrrw x0,mie,x0
        prog[269] = 32'h30200073;   // DONE: MRET
        // ===== GPIO test: pins driven by instructions =====
        // outputs: set pins 0,5,31 high via SW ; inputs: pin7(=1) loop-accumulated x5 + pin3(=1)
        prog[270] = 32'hf0000393;   // addi x7,x0,-256   slot0 base 0xFFFFFF00
        prog[271] = 32'h00100093;   // addi x1,x0,1
        prog[272] = 32'h0013a023;   // sw x1,0(x7)       pin0=1
        prog[273] = 32'h0013aa23;   // sw x1,20(x7)      pin5=1
        prog[274] = 32'h0613ae23;   // sw x1,124(x7)     pin31=1
        prog[275] = 32'hf1c00393;   // addi x7,x0,-228   slot7 addr (pin7)
        prog[276] = 32'h00000313;   // addi x6,x0,0      accum=0
        prog[277] = 32'h00500193;   // addi x3,x0,5      count=5
        prog[278] = 32'h0003a083;   // loop: lw x1,0(x7) x1=pin7
        prog[279] = 32'h00130333;   // add x6,x6,x1      accum+=pin7
        prog[280] = 32'hfff18193;   // addi x3,x3,-1
        prog[281] = 32'hfe019ae3;   // bne x3,x0,loop
        prog[282] = 32'hf0c00393;   // addi x7,x0,-244   slot3 addr (pin3)
        prog[283] = 32'h0003a083;   // lw x1,0(x7)       x1=pin3
        prog[284] = 32'h00130333;   // add x6,x6,x1      accum=6
        prog[285] = 32'h0000006f;   // jal x0,0          spin

        for (i = 0; i < NWORDS; i = i + 1) load_word(i, prog[i]);

        #12 rst = 0;
        irq_external = 1;          // peripheral asserts; only taken once mie.MEIE set
        #9000 ;

        $display("==== register checks ====");
        ckreg(5'd4, 32'h00007fff);
        ckreg(5'd5, 32'h00007fff);
        ckreg(5'd8, 32'h0000000f);
        ckreg(5'd9, 32'h00000001);
        ckreg(5'd10, 32'h00000001);
        ckreg(5'd11, 32'h00000003);
        ckreg(5'd12, 32'h0000000d);
        ckreg(5'd13, 32'h00000004);
        ckreg(5'd14, 32'h000000c0);
        ckreg(5'd15, 32'h00000003);
        ckreg(5'd16, 32'hfffffffb);
        ckreg(5'd17, 32'h00000011);
        ckreg(5'd18, 32'h00000007);
        ckreg(5'd19, 32'h00000180);
        ckreg(5'd20, 32'h00000001);
        ckreg(5'd21, 32'h00000000);
        ckreg(5'd22, 32'h00000009);
        ckreg(5'd23, 32'h00000000);
        ckreg(5'd24, 32'hffffffff);
        ckreg(5'd25, 32'h0000000d);
        ckreg(5'd26, 32'h00000004);
        ckreg(5'd27, 32'habcde000);
        ckreg(5'd28, 32'h00001078);
        ckreg(5'd29, 32'h7fff7fff);
        ckreg(5'd2,  32'h00000001);
        ckreg(5'd30, 32'hffffffff);
        ckreg(5'd31, 32'h000000ff);
        $display("==== memory checks ====");
        ckmem(16'h0110, 8'hff);
        ckmem(16'h0111, 8'h7f);
        ckmem(16'h0112, 8'hff);
        ckmem(16'h0113, 8'h7f);
        ckmem(16'h0114, 8'h7f);
        ckmem(16'h0115, 8'h00);
        ckmem(16'h0118, 8'h0f);
        ckmem(16'h0119, 8'h00);
        ckmem(16'h011a, 8'h00);
        ckmem(16'h011b, 8'h00);
        ckmem(16'h0130, 8'h00);
        ckmem(16'h0134, 8'h05);
        ckmem(16'h0138, 8'h07);
        ckmem(16'h013c, 8'h06);
        ckmem(16'h0140, 8'h30);
        ckmem(16'h0144, 8'h3f);
        ckmem(16'h0160, 8'h00);
        ckmem(16'h0164, 8'h11);
        ckmem(16'h0168, 8'h00);
        ckmem(16'h016c, 8'h11);
        ckmem(16'h0170, 8'h00);
        ckmem(16'h0174, 8'h11);
        ckmem(16'h0178, 8'h00);
        ckmem(16'h017c, 8'h11);
        ckmem(16'h0180, 8'h00);
        ckmem(16'h0184, 8'h11);
        ckmem(16'h0188, 8'h00);
        ckmem(16'h018c, 8'h11);
        ckmem(16'h0190, 8'h11);
        ckmem(16'h0194, 8'h11);
        ckmem(16'h01a0, 8'h00);
        ckmem(16'h01a4, 8'h1c);
        ckmem(16'h01a5, 8'h02);
        ckmem(16'h01a6, 8'h00);
        ckmem(16'h01a7, 8'h00);
        ckmem(16'h01a8, 8'h11);
        ckmem(16'h01b0, 8'h00);
        ckmem(16'h01b4, 8'h40);
        ckmem(16'h01b5, 8'h02);
        ckmem(16'h01b6, 8'h00);
        ckmem(16'h01b7, 8'h00);
        ckmem(16'h01b8, 8'h11);
        $display("==== CSR check ====");
        if (dut.cpu.mscratch !== 32'h0000003e) begin
            errors=errors+1;
            $display("  FAIL mscratch = %08h  expected 0000003e", dut.cpu.mscratch);
        end
        else
            $display("  ok   mscratch = %08h", dut.cpu.mscratch);

        $display("==== forwarding checks ====");
        ckfw(16'h01c0, 32'h0000000f, "F1 rs1 forward     ");
        ckfw(16'h01c4, 32'hffffff9c, "F2 rs2 forward     ");
        ckfw(16'h01c8, 32'h0000000e, "F3 both operands   ");
        ckfw(16'h01cc, 32'h00000004, "F4 dependency chain");
        ckfw(16'h01d0, 32'h00000033, "F5 load-use forward");
        ckfw(16'h01d4, 32'h00000000, "F6 x0 not forwarded");
        ckfw(16'h01d8, 32'h00000042, "F7 store-data fwd  ");
        ckfw(16'h01dc, 32'h000000aa, "F8 branch-cond fwd ");
        if (dut.bram.DataMem[16'h01e4] !== 8'h5a) begin
            errors = errors + 1;
            $display("  FAIL F10 store-base fwd = %02h  expected 5a", dut.bram.DataMem[16'h01e4]);
        end else $display("  ok   F10 store-base fwd = 5a");
        ckfw(16'h01e8, 32'h0000006c, "F9 jalr-target fwd ");
        ckfw(16'h01f0, 32'h00000001, "F11 CSR forward    ");

        $display("==== trap / interrupt checks ====");
        cklog(16'd1024, 32'h0000000b, "T1 ecall  mcause   ");
        cklog(16'd1028, 32'h00000000, "T1 ecall  mtval    ");
        cklog(16'd1032, 32'h00000003, "T2 ebreak mcause   ");
        cklog(16'd1036, 32'h000003a4, "T2 ebreak mtval=PC ");
        cklog(16'd1040, 32'h00000002, "T3 illeg  mcause   ");
        cklog(16'd1044, 32'h0000000b, "T3 illeg  mtval    ");
        cklog(16'd1048, 32'h80000007, "T4 timer  mcause   ");
        cklog(16'd1052, 32'h00000000, "T4 timer  mtval    ");
        cklog(16'd1056, 32'h8000000b, "T5 extern mcause   ");
        cklog(16'd1060, 32'h00000000, "T5 extern mtval    ");
        if (dut.cpu.mcause !== 32'h8000000b) begin
            errors=errors+1;
            $display("  FAIL final mcause = %08h  expected 8000000b", dut.cpu.mcause);
        end else $display("  ok   final mcause = 8000000b");
        if (dut.cpu.mstatus[3] !== 1'b1) begin
            errors=errors+1;
            $display("  FAIL mstatus.MIE not restored");
        end else $display("  ok   mstatus.MIE restored");

        $display("==== GPIO checks ====");
        if (gpio_out_w !== 32'h80000021) begin errors=errors+1;
            $display("  FAIL gpio_out = %08h  expected 80000021", gpio_out_w); end
        else $display("  ok   gpio_out = 80000021 (pins 0,5,31 set by SW stores)");
        if (dut.cpu.registry.registers[6] !== 32'd6) begin errors=errors+1;
            $display("  FAIL x6 = %0d  expected 6", dut.cpu.registry.registers[6]); end
        else $display("  ok   x6 = 6 (pin7 read+incremented 5x in a loop, + pin3)");
        $display("========================");
        if (errors == 0) $display("ALL TESTS PASSED (26 reg, 42 mem, +CSR, 11 forward, 12 trap, 2 gpio)");
        else $display("FAILED: %0d error(s)", errors);
        $finish;
    end
endmodule