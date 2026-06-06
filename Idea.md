# NOVA CPU



## General Info

    Made for FreeRTOS
    
    No Privilage modes
    32bit Risc-V architecture.
    64-Bit Machine Timer mtime / mtimecmp
    UART
    Harvard architecture
    Data Forwarding implemented
    3 stage pipeline:
        Fetch
        Decode/execute
        Mem/Writeback
    Static Not-Taken branch prediction

### RISCV extensions

    RV32 I, Ziscr


## Registry

    In total 32 Registers.

    R0 - constant 0 register, writes will be ignored
    R1-R31 - General purpose registers

## CSR registers

    mtime

64-bit counter that increments continuously at a stable frequency.

    mtimecmp

64-bit register where the OS writes the next target time.

    mstatus

Machine Status, 0x300: Tracks the global interrupt state.

    mie

Machine Interrupt Enable, 0x304: Used to enable the timer interrupt

    mip

Machine Interrupt Pending, 0x344: Read by the OS to see what interrupts are waiting.

    mtvec

Machine Trap Vector Base Address, 0x305: Holds the PC jump address for the trap/interrupt handler.

    mepc

Machine Exception Program Counter, 0x341: Automatically saves the address of the instruction that was interrupted, allowing mret to return to the correct task.

    mcause

Machine Trap Cause, 0x342: Tells the interrupt handler why the trap happened

    mscratch

Machine Scratch, 0x340: A temporary data storage register.

    misa

Reports what extensions my CPU supports (just I and Ziscr for now)

    mtval

Machine Trap Value, 0x343: Faulting address or instruction opcode.

    cycle (0xC00)
    cycleh (0xC80)

Counts how many clock cycles have elapsed since the CPU reset.

    time (0xC01)
    timeh (0xC81)

Current value of the 64-bit hardware mtime.

    instret (0xC02)
    instreth (0xC82)

Counts how many instructions have been retired/executed.

## ISA types
    R-type funct7[31:25], rs2[24:20], rs1[19:15], funct3[14:12], rd[11:7], op[6:0]
    I-type imm(11:0)[31:20], rs1[19:15], funct3[14:12], rd[11:7], op[6:0]
    S-type imm(11:5)[31:25], rs2[24:20], rs1[19:15], funct3[14:12], imm(4:0)[11:7], op[6:0]
    B-type imm(12|10:5)[31:25], rs2[24:20], rs1[19:15], funct3[14:12], imm(4:1|11)[11:7], op[6:0]
    U-type imm(31:12)[31:12], rd[11:7], op[6:0]
    J-type imm(20|10:1|11|19:12)[31:12], rd[11:7], op[6:0]

## Privilaged instructions (just for clarifications, in reality no privilaged mode)

    MRET 0011000 | 00010 | 00000 | 000 | 00000 | 1110011
    

## RV32I Instructions


### U-type:


    LUI imm[31:12], rd[11:7], 0110111
    imm << 12 -> rd

---

    AUIPC imm[31:12], rd[11:7], 0010111
    PC + (imm << 12) -> rd

### J-type, B-type:
    JAL imm[20|10:1|11|19:12], rd[11:7], 1101111
    PC + 4 -> rd; 
    PC + imm -> PC

---

    JALR imm[11:0], rs1[19:15], 000, rd[11:7], 1100111
    PC + 4 -> rd;
    (rs1 + imm) & ~1 -> PC

---

    BEQ imm[12|10:5], rs2[24:20], rs1[19:15], 000, imm[4:1|11], 1100011
    if (rs1 == rs2) 
        PC + imm -> PC

---

    BNE imm[12|10:5], rs2[24:20], rs1[19:15], 001, imm[4:1|11], 1100011
    if (rs1 != rs2) 
        PC + imm -> PC

---

    BLT imm[12|10:5], rs2[24:20], rs1[19:15], 100, imm[4:1|11], 1100011
    if (rs1 < rs2, signed) 
        PC + imm -> PC

---

    BGE imm[12|10:5], rs2[24:20], rs1[19:15], 101, imm[4:1|11], 1100011
    if (rs1 >= rs2, signed) 
        PC + imm -> PC

---

    BLTU imm[12|10:5], rs2[24:20], rs1[19:15], 110, imm[4:1|11], 1100011
    if (rs1 < rs2, unsigned) 
        PC + imm -> PC

---

    BGEU imm[12|10:5], rs2[24:20], rs1[19:15], 111, imm[4:1|11], 1100011
    if (rs1 >= rs2, unsigned) 
        PC + imm -> PC

### I-type Load instructions:
    LB imm[11:0], rs1[19:15], 000, rd[11:7], 0000011
    SignExtend(Mem8[rs1 + imm]) -> rd

---

    LH imm[11:0], rs1[19:15], 001, rd[11:7], 0000011
    SignExtend(Mem16[rs1 + imm]) -> rd

---

    LW imm[11:0], rs1[19:15], 010, rd[11:7], 0000011
    SignExtend(Mem32[rs1 + imm]) -> rd

---

    LBU imm[11:0], rs1[19:15], 100, rd[11:7], 0000011
    ZeroExtend(Mem8[rs1 + imm]) -> rd

---

    LHU imm[11:0], rs1[19:15], 101, rd[11:7], 0000011
    ZeroExtend(Mem16[rs1 + imm]) -> rd

### S-type:
    SB imm[11:5], rs2[24:20], rs1[19:15], 000, imm[4:0], 0100011
    rs2[7:0] -> Mem8[rs1 + imm]
---

    SH imm[11:5], rs2[24:20], rs1[19:15], 001, imm[4:0], 0100011
    rs2[15:0] -> Mem16[rs1 + imm]
---

    SW imm[11:5], rs2[24:20], rs1[19:15], 010, imm[4:0], 0100011
    rs2[31:0] -> Mem32[rs1 + imm]

### I-type Arithmetic:
    ADDI imm[11:0], rs1[19:15], 000, rd[11:7], 0010011
    rs1 + imm -> rd
---

    SLTI imm[11:0], rs1[19:15], 010, rd[11:7], 0010011
    if (rs1 < imm, signed) 
        1 -> rd else 0 -> rd
---

    SLTIU imm[11:0], rs1[19:15], 011, rd[11:7], 0010011
    if (rs1 < imm, unsigned) 
        1 -> rd else 0 -> rd
---

    XORI imm[11:0], rs1[19:15], 100, rd[11:7], 0010011
    rs1 ^ imm -> rd
---

    ORI imm[11:0], rs1[19:15], 110, rd[11:7], 0010011
    rs1 | imm -> rd
---

    ANDI imm[11:0], rs1[19:15], 111, rd[11:7], 0010011
    rs1 & imm -> rd
---

    SLLI 0000000, shamt[24:20], rs1[19:15], 001, rd[11:7], 0010011
    rs1 << shamt -> rd
---

    SRLI 0000000, shamt[24:20], rs1[19:15], 101, rd[11:7], 0010011
    rs1 >> shamt logical -> rd
---

    SRAI 0100000, shamt[24:20], rs1[19:15], 101, rd[11:7], 0010011
    rs1 >> shamt arithmetic -> rd

### R-type:
    ADD 0000000, rs2[24:20], rs1[19:15], 000, rd[11:7], 0110011
    rs1 + rs2 -> rd
---

    SUB 0100000, rs2[24:20], rs1[19:15], 000, rd[11:7], 0110011
    rs1 - rs2 -> rd
---

    SLL 0000000, rs2[24:20], rs1[19:15], 001, rd[11:7], 0110011
    rs1 << rs2[4:0] -> rd
---

    SLT 0000000, rs2[24:20], rs1[19:15], 010, rd[11:7], 0110011
    if (rs1 < rs2, signed) 
        1 -> rd 
    else 0 -> rd
---

    SLTU 0000000, rs2[24:20], rs1[19:15], 011, rd[11:7], 0110011
    if (rs1 < rs2, unsigned) 
    1 -> rd
    else 0 -> rd
---

    XOR 0000000, rs2[24:20], rs1[19:15], 100, rd[11:7], 0110011
    rs1 ^ rs2 -> rd
---

    SRL 0000000, rs2[24:20], rs1[19:15], 101, rd[11:7], 0110011
    rs1 >> rs2[4:0] logical -> rd
---

    SRA 0100000, rs2[24:20], rs1[19:15], 101, rd[11:7], 0110011
    rs1 >> rs2[4:0] arithmetic -> rd
---

    OR 0000000, rs2[24:20], rs1[19:15], 110, rd[11:7], 0110011
    rs1 | rs2 -> rd
---

    AND 0000000, rs2[24:20], rs1[19:15], 111, rd[11:7], 0110011
    rs1 & rs2 -> rd

### System Instructions:
    FENCE fm[31:28], pred[27:24], succ[23:20], rs1[19:15], 000, rd[11:7], 0001111
    Memory Fence (Orders memory access)
---

    FENCE.TSO 1000, 0011, 0011, 00000, 000, 00000, 0001111

---

    PAUSE 0000, 0001, 0000, 00000, 000, 00000, 0001111

---

    ECALL 000000000000, 00000, 000, 00000, 1110011
    Syscall
---

    EBREAK 000000000001, 00000, 000, 00000, 1110011
    Breakpoint

## RV32Ziscr instructions

    CSRRW csr[31:20], rs1[19:15], 001, rd[11:7], 1110111
    CSR -> rd; rs1 -> CSR

---

    CSRRS csr[31:20], rs1[19:15], 010, rd[11:7], 1110111
    CSR -> rd; 
    CSR | rs1 -> CSR

---

    CSRRC csr[31:20], rs1[19:15], 011, rd[11:7], 1110111
    CSR -> rd;
    CSR & ~rs1 -> CSR

---

    CSRRWI csr[31:20], uimm[19:15], 101, rd[11:7], 1110111
    CSR -> rd;
    ZeroExtend(uimm) -> CSR

---

    CSRRSI csr[31:20], uimm[19:15], 110, rd[11:7], 1110111
    CSR -> rd;
    CSR | ZeroExtend(uimm) -> CSR

---

    CSRRCI csr[31:20], uimm[19:15], 111, rd[11:7], 1110111
    CSR -> rd;
    CSR & ~ZeroExtend(uimm) -> CSR
