`timescale 1ns / 1ps


module CPU (
    input wire clk,
    input wire rst
);

    //CSRs:
    reg [31:0] mstatus;
    reg [31:0] mie;
    reg [31:0] mip;
    reg [31:0] mtvec;
    reg [31:0] mepc;
    reg [31:0] mcause;
    reg [31:0] mtval;
    reg [31:0] mscratch;

    wire [31:0] misa = 32'h40000100;

    reg [63:0] cycle;
    reg [63:0] instret;
    reg [63:0] mtime;
    reg [63:0] mtimecmp;


    //Registers
    reg [31:0] BRAMInstruction;
    reg [31:0] PC;

    //Inter-stage registers (EX -> WB)
    reg [31:0] toWB_Result_Reg;
    reg [31:0] toWB_csr_data_Reg;
    reg [11:0] toWB_csr_addr_Reg;
    reg [4:0]  toWB_rd_addr_Reg;
    reg [4:0]  toWB_rs2_addr_Reg;
    reg [1:0]  toWB_mode_Reg;   // 00=GPR, 01=CSR, 10=Load, 11=Store
    reg [15:0] toWB_mem_addr_Reg;
    reg [31:0] toWB_rs2_data_Reg;
    reg [2:0]  toWB_store_mode_Reg;
    reg [2:0]  toWB_load_mode_Reg;

    //EX combinational outputs
    reg [31:0] EX_result;
    reg [31:0] EX_csr_result;
    reg [1:0]  toWB_mode;
    reg [15:0] EX_mem_addr;
    reg [2:0]  EX_store_mode;
    reg [2:0]  EX_load_mode;

    wire [31:0] BRAMInstructionWire;

    wire [6:0] opcode = BRAMInstruction[6:0];
    wire [2:0] funct3 = BRAMInstruction[14:12];
    wire [6:0] funct7 = BRAMInstruction[31:25];

    wire [4:0] rs1_addr = BRAMInstruction[19:15];
    wire [4:0] rs2_addr = BRAMInstruction[24:20];
    wire [4:0] rd_addr  = BRAMInstruction[11:7];
    wire [31:0] rs1_data;
    wire [31:0] rs2_data;

    wire [4:0] shamt = BRAMInstruction[24:20];
    reg  [4:0] alu_control;

    reg [4:0]  operand_a_addr;
    reg [4:0]  operand_b_addr;
    reg [31:0] operand_a;
    reg [31:0] operand_b;
    wire [31:0] alu_result;

    wire flush;
    wire stallFromWB;
    wire stallFromEX;

    // BRAM control — driven combinationally for EX, latched for WB
    reg [15:0] BRAM_read_addr;
    reg [31:0] BRAM_data_in;
    reg [2:0]  BRAM_store_mode;
    reg [2:0]  BRAM_load_mode;
    reg [15:0] BRAM_write_addr_reg;

    wire [15:0] BRAM_write_addr = BRAM_write_addr_reg;
    wire [31:0] BRAM_data_out;

    // WB outputs to registry
    reg [4:0]  WB_rd_addr;
    reg [31:0] WB_rd_data;
    reg        WB_write_enable;

    BRAM bram (
        .clk(clk),
        .write_addr(BRAM_write_addr),
        .read_addr(BRAM_read_addr),
        .fetch_addr(PC),
        .data_in(BRAM_data_in),
        .data_out(BRAM_data_out),
        .instruction_out(BRAMInstructionWire),
        .write_mode(BRAM_store_mode),
        .read_mode(BRAM_load_mode)
    );

    always @(posedge clk) begin
        if (flush)
            BRAMInstruction <= 32'b0;
        else
            BRAMInstruction <= BRAMInstructionWire;
    end

    Registry registry (
        .clk(clk),
        .rst(rst),
        .rs1_addr(operand_a_addr),
        .rs2_addr(operand_b_addr),
        .rd_addr(WB_rd_addr),
        .rd_data(WB_rd_data),
        .reg_write_enable(WB_write_enable),
        .rs1_data(rs1_data),
        .rs2_data(rs2_data)
    );

    ALU alu (
        .alu_control(alu_control),
        .operand_a(operand_a),
        .operand_b(operand_b),
        .alu_result(alu_result)
    );


    wire [31:0] imm_i = {{20{BRAMInstruction[31]}}, BRAMInstruction[31:20]};
    wire [31:0] imm_s = {{20{BRAMInstruction[31]}}, BRAMInstruction[31:25], BRAMInstruction[11:7]};
    wire [31:0] imm_b = {{19{BRAMInstruction[31]}}, BRAMInstruction[31], BRAMInstruction[7], BRAMInstruction[30:25], BRAMInstruction[11:8], 1'b0};
    wire [31:0] imm_u = {BRAMInstruction[31:12], 12'b0};   // already shifted into [31:12]
    wire [31:0] imm_j = {{11{BRAMInstruction[31]}}, BRAMInstruction[31], BRAMInstruction[19:12], BRAMInstruction[20], BRAMInstruction[30:21], 1'b0};
    wire [11:0] csr_addr = BRAMInstruction[31:20];
    wire [31:0] uimm = {27'b0, BRAMInstruction[19:15]};    // zero-extended 5-bit immediate

    reg [31:0] next_PC;

    // Branch condition — evaluated combinationally from register file reads
    reg branch_taken;
    always @(*) begin
        case (funct3)
            3'b000: branch_taken = (rs1_data == rs2_data);                        // BEQ
            3'b001: branch_taken = (rs1_data != rs2_data);                        // BNE
            3'b100: branch_taken = ($signed(rs1_data) < $signed(rs2_data));       // BLT
            3'b101: branch_taken = ($signed(rs1_data) >= $signed(rs2_data));      // BGE
            3'b110: branch_taken = (rs1_data < rs2_data);                         // BLTU
            3'b111: branch_taken = (rs1_data >= rs2_data);                        // BGEU
            default: branch_taken = 1'b0;
        endcase
    end

    // CSR helpers — combinational read/write wrappers
    task automatic GetCSR;
        input  [11:0] addr;
        output reg [31:0] value;
        case (addr)
            12'h300: value = mstatus;
            12'h304: value = mie;
            12'h344: value = mip;
            12'h305: value = mtvec;
            12'h341: value = mepc;
            12'h342: value = mcause;
            12'h343: value = mtval;
            12'h340: value = mscratch;
            12'hC00: value = cycle[31:0];
            12'hC80: value = cycle[63:32];
            12'hC01: value = mtime[31:0];
            12'hC81: value = mtime[63:32];
            12'hC02: value = instret[31:0];
            12'hC82: value = instret[63:32];
            default: value = 32'b0;
        endcase
    endtask

    task automatic SetCSR;
        input [11:0] addr;
        input [31:0] value;
        case (addr)
            12'h300: mstatus  <= value;
            12'h304: mie      <= value;
            12'h344: mip      <= value;
            12'h305: mtvec    <= value;
            12'h341: mepc     <= value;
            12'h342: mcause   <= value;
            12'h343: mtval    <= value;
            12'h340: mscratch <= value;
            // cycle/time/instret are read-only; silently ignore writes
        endcase
    endtask


    // -------------------------------------------------------------------------
    // ID/EX stage — fully combinational
    // -------------------------------------------------------------------------
    always @(*) begin
        // Defaults
        operand_a_addr = rs1_addr;
        operand_b_addr = rs2_addr;
        operand_a      = rs1_data;
        operand_b      = rs2_data;
        alu_control    = 5'b0_000;
        next_PC        = PC + 4;
        EX_result      = 32'b0;
        EX_csr_result  = 32'b0;
        toWB_mode      = 2'b00;      // default: write GPR
        EX_mem_addr    = 16'b0;
        EX_store_mode  = 3'b111;     // disabled
        EX_load_mode   = 3'b111;     // disabled

        case (opcode)

            // ------------------------------------------------------------------
            7'b0110111: begin // LUI
                // imm_u already is {imm[31:12], 12'b0} — no additional shift
                EX_result  = imm_u;
                toWB_mode  = 2'b00;   // GPR write
            end

            // ------------------------------------------------------------------
            7'b0010111: begin // AUIPC
                operand_a   = PC;
                operand_b   = imm_u;  // imm_u already shifted
                alu_control = 5'b0_000;
                EX_result   = alu_result;
                toWB_mode   = 2'b00;
            end

            // ------------------------------------------------------------------
            7'b1101111: begin // JAL
                operand_a   = PC;
                operand_b   = imm_j;
                alu_control = 5'b0_000;
                next_PC     = alu_result;
                EX_result   = PC + 4;
                toWB_mode   = 2'b00;
            end

            // ------------------------------------------------------------------
            7'b1100111: begin // JALR
                operand_a   = rs1_data;
                operand_b   = imm_i;
                alu_control = 5'b0_000;
                next_PC     = alu_result & ~32'd1;
                EX_result   = PC + 4;
                toWB_mode   = 2'b00;
            end

            // ------------------------------------------------------------------
            7'b1100011: begin // Branch (BEQ/BNE/BLT/BGE/BLTU/BGEU)
                if (branch_taken)
                    next_PC = PC + imm_b;
                toWB_mode = 2'b00;   // no writeback
                // rd_addr is always x0 for branches in practice; write_enable
                // will be suppressed by WB when rd==0
            end

            // ------------------------------------------------------------------
            7'b0000011: begin // Load
                operand_a   = rs1_data;
                operand_b   = imm_i;
                alu_control = 5'b0_000;
                EX_result   = alu_result;
                EX_mem_addr = alu_result[15:0];
                EX_load_mode  = funct3;
                EX_store_mode = 3'b111;
                toWB_mode   = 2'b10;
            end

            // ------------------------------------------------------------------
            7'b0100011: begin // Store
                operand_a   = rs1_data;
                operand_b   = imm_s;
                alu_control = 5'b0_000;
                EX_result   = alu_result;
                EX_mem_addr   = alu_result[15:0];
                EX_store_mode = funct3;
                EX_load_mode  = 3'b111;
                toWB_mode   = 2'b11;
            end

            // ------------------------------------------------------------------
            7'b0010011: begin // I-type ALU (ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI)
                operand_a   = rs1_data;
                operand_b   = imm_i;
                alu_control = {BRAMInstruction[30], funct3};
                EX_result   = alu_result;
                toWB_mode   = 2'b00;
            end

            // ------------------------------------------------------------------
            7'b0110011: begin // R-type ALU (ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND)
                operand_a   = rs1_data;
                operand_b   = rs2_data;
                alu_control = {BRAMInstruction[30], funct3};
                EX_result   = alu_result;
                toWB_mode   = 2'b00;
            end

            // ------------------------------------------------------------------
            7'b0001111: begin // FENCE / FENCE.TSO / PAUSE — treated as NOP
                EX_result = 32'b0;
                toWB_mode = 2'b00;
            end

            // ------------------------------------------------------------------
            7'b1110011: begin // ECALL / EBREAK / MRET — no writeback for now
                EX_result = 32'b0;
                toWB_mode = 2'b00;
            end

            // ------------------------------------------------------------------
            // CSR instructions (opcode 1110111 per NOVA ISA spec)
            7'b1110111: begin
                toWB_mode = 2'b01;   // CSR path: old CSR -> rd, new value -> CSR

                case (funct3)
                    3'b001: begin // CSRRW  — rd = CSR; CSR = rs1
                        GetCSR(csr_addr, EX_result);
                        EX_csr_result = rs1_data;
                    end
                    3'b010: begin // CSRRS  — rd = CSR; CSR = CSR | rs1
                        GetCSR(csr_addr, EX_result);
                        operand_a   = EX_result;
                        operand_b   = rs1_data;
                        alu_control = 5'b0_110;   // OR
                        EX_csr_result = alu_result;
                    end
                    3'b011: begin // CSRRC  — rd = CSR; CSR = CSR & ~rs1
                        GetCSR(csr_addr, EX_result);
                        operand_a   = EX_result;
                        operand_b   = ~rs1_data;
                        alu_control = 5'b0_111;   // AND
                        EX_csr_result = alu_result;
                    end
                    3'b101: begin // CSRRWI — rd = CSR; CSR = uimm
                        GetCSR(csr_addr, EX_result);
                        EX_csr_result = uimm;
                    end
                    3'b110: begin // CSRRSI — rd = CSR; CSR = CSR | uimm
                        GetCSR(csr_addr, EX_result);
                        operand_a   = EX_result;
                        operand_b   = uimm;
                        alu_control = 5'b0_110;   // OR
                        EX_csr_result = alu_result;
                    end
                    3'b111: begin // CSRRCI — rd = CSR; CSR = CSR & ~uimm
                        GetCSR(csr_addr, EX_result);
                        operand_a   = EX_result;
                        operand_b   = ~uimm;
                        alu_control = 5'b0_111;   // AND
                        EX_csr_result = alu_result;
                    end
                    default: begin
                        EX_result     = 32'b0;
                        EX_csr_result = 32'b0;
                    end
                endcase
            end

            // ------------------------------------------------------------------
            7'b0000000: begin // NOP (all-zero word)
                EX_result = 32'b0;
                toWB_mode = 2'b00;
            end

            default: begin
                EX_result = 32'b0;
                toWB_mode = 2'b00;
            end

        endcase
    end


    // -------------------------------------------------------------------------
    // EX/WB pipeline registers — clocked
    // -------------------------------------------------------------------------
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            PC                  <= 32'b0;
            cycle               <= 64'b0;
            instret             <= 64'b0;
            mtime               <= 64'b0;
            mtimecmp            <= 64'hFFFFFFFFFFFFFFFF;
            toWB_Result_Reg     <= 32'b0;
            toWB_rd_addr_Reg    <= 5'b0;
            toWB_rs2_addr_Reg   <= 5'b0;
            toWB_csr_addr_Reg   <= 12'b0;
            toWB_csr_data_Reg   <= 32'b0;
            toWB_mode_Reg       <= 2'b00;
            toWB_mem_addr_Reg   <= 16'b0;
            toWB_rs2_data_Reg   <= 32'b0;
            toWB_store_mode_Reg <= 3'b111;
            toWB_load_mode_Reg  <= 3'b111;
        end else begin
            PC                  <= next_PC;
            cycle               <= cycle + 1;
            mtime               <= mtime + 1;

            toWB_Result_Reg     <= EX_result;
            toWB_rd_addr_Reg    <= rd_addr;
            toWB_rs2_addr_Reg   <= rs2_addr;
            toWB_csr_addr_Reg   <= csr_addr;
            toWB_csr_data_Reg   <= EX_csr_result;
            toWB_mode_Reg       <= toWB_mode;
            toWB_mem_addr_Reg   <= EX_mem_addr;
            toWB_rs2_data_Reg   <= rs2_data;
            toWB_store_mode_Reg <= EX_store_mode;
            toWB_load_mode_Reg  <= EX_load_mode;
        end
    end


    // -------------------------------------------------------------------------
    // MEM/WB stage — combinational
    // -------------------------------------------------------------------------
    //
    // BRAM read_addr and load_mode come from the latched EX values so BRAM
    // sees a stable address during this stage.  write_addr/data/store_mode
    // are driven here for the store path.
    // -------------------------------------------------------------------------
    always @(*) begin
        // BRAM defaults — override below as needed
        BRAM_read_addr      = toWB_mem_addr_Reg;
        BRAM_load_mode      = toWB_load_mode_Reg;
        BRAM_store_mode     = 3'b111;          // disabled unless store
        BRAM_data_in        = 32'b0;
        BRAM_write_addr_reg = 16'b0;

        WB_rd_addr      = toWB_rd_addr_Reg;
        WB_rd_data      = 32'b0;
        WB_write_enable = 1'b0;

        case (toWB_mode_Reg)

            2'b00: begin // GPR write-back
                WB_rd_data      = toWB_Result_Reg;
                // x0 is hard-wired to 0; suppress write so the registry
                // never modifies slot 0 (Registry should also guard this,
                // but being explicit here avoids relying on that)
                WB_write_enable = (toWB_rd_addr_Reg != 5'b0);
            end

            2'b01: begin // CSR write-back
                // EX_result holds the old CSR value -> goes to rd
                // EX_csr_result holds the new value  -> goes to the CSR
                // SetCSR is called in the clocked block below because CSR
                // registers are sequential state.
                WB_rd_data      = toWB_Result_Reg;
                WB_write_enable = (toWB_rd_addr_Reg != 5'b0);
            end

            2'b10: begin // Load — BRAM output -> rd
                WB_rd_data      = BRAM_data_out;
                WB_write_enable = (toWB_rd_addr_Reg != 5'b0);
                // BRAM_read_addr and BRAM_load_mode already set from defaults
            end

            2'b11: begin // Store — write rs2 to BRAM
                BRAM_write_addr_reg = toWB_mem_addr_Reg;
                BRAM_store_mode     = toWB_store_mode_Reg;
                BRAM_data_in        = toWB_rs2_data_Reg;
                WB_write_enable     = 1'b0;
            end

        endcase
    end

    // CSR sequential write and instret update happen on the clock edge
    always @(posedge clk) begin
        if (!rst) begin
            if (toWB_mode_Reg == 2'b01)
                SetCSR(toWB_csr_addr_Reg, toWB_csr_data_Reg);

            // Count every retired instruction (anything that was not a bubble)
            if (toWB_mode_Reg != 2'b00 || toWB_rd_addr_Reg != 5'b0 ||
                toWB_Result_Reg != 32'b0)
                instret <= instret + 1;
        end
    end


endmodule