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

    //Inter-stage
    reg [31:0] toWB_Result_Reg;
    reg [31:0] EX_result;

    reg [4:0] toWB_rd_addr_Reg;
    reg [4:0] toWB_rs2_addr_Reg;
    reg [11:0] toWB_csr_addr_Reg;
    reg [31:0] toWB_csr_data_Reg;
    reg [31:0] EX_csr_result;

    reg [1:0] toWB_mode_Reg; //00 - GPR, 01 - CSR, 10 - Load, 11 - Store
    reg [1:0] toWB_mode;

    wire [2:0] BRAM_load_mode;
    wire [2:0] BRAM_store_mode;


    wire [31:0] BRAMInstructionWire;

    wire [6:0] opcode = BRAMInstruction[6:0];
    wire [2:0] funct3 = BRAMInstruction[14:12];
    wire [6:0] funct7 = BRAMInstruction[31:25];

    wire [4:0] rs1_addr = BRAMInstruction[19:15];
    wire [4:0] rs2_addr = BRAMInstruction[24:20];
    wire [4:0] rd_addr = BRAMInstruction[11:7];
    wire [31:0] rs1_data;
    wire [31:0] rs2_data;

    wire [4:0] shamt = BRAMInstruction[24:20];
    reg [4:0] alu_control;

    reg [4:0] operand_a_addr;
    reg [4:0] operand_b_addr;
    reg [31:0] operand_a;
    reg [31:0] operand_b;
    wire [31:0] alu_result;


    wire flush;
    wire stallFromWB; //should propagate, meaning if this is set then "stallFromEX" also is set
    wire stallFromEX;


    wire [15:0] BRAM_write_addr;
    reg [15:0] BRAM_read_addr;

    reg [31:0] BRAM_data_in;

    wire [31:0] BRAM_data_out;


    reg [4:0] WB_rd_addr;
    reg [31:0] WB_rd_data;
    reg WB_write_enable;

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
        if(flush) begin
            BRAMInstruction <= 32'b0;
        end else begin
            BRAMInstruction <= BRAMInstructionWire;
        end
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
    wire [31:0] imm_u = {BRAMInstruction[31:12], 12'b0};
    wire [31:0] imm_j = {{11{BRAMInstruction[31]}}, BRAMInstruction[31], BRAMInstruction[19:12], BRAMInstruction[20], BRAMInstruction[30:21], 1'b0};
    wire [31:0] csr_addr = BRAMInstruction[31:20];
    wire [31:0] uimm = BRAMInstruction[19:15];

    reg [31:0] next_PC;


    reg branch_taken;
    always @(*) begin
        case (funct3)
            3'b000: branch_taken = (rs1_data == rs2_data);
            3'b001: branch_taken = (rs1_data != rs2_data);
            3'b100: branch_taken = ($signed(rs1_data) < $signed(rs2_data));
            3'b101: branch_taken = ($signed(rs1_data) >= $signed(rs2_data));
            3'b110: branch_taken = (rs1_data < rs2_data);
            3'b111: branch_taken = (rs1_data >= rs2_data);
            default: branch_taken = 1'b0;
        endcase
    end

    task SetCSR;
    input [11:0] addr;
    input [31:0] value;
        case (addr)
            12'h300: mstatus <= value;
            12'h304: mie <= value;
            12'h344: mip <= value;
            12'h305: mtvec <= value;
            12'h341: mepc <= value;
            12'h342: mcause <= value;
            12'h343: mtval <= value;
            12'h340: mscratch <= value;
        endcase
    endtask

    task GetCSR;
    input [11:0] addr;
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
            default: value = 32'b0;
        endcase
    endtask

    //ID/EX logic

    always @(*) begin
        operand_a_addr = rs1_addr;
        operand_b_addr = rs2_addr;
        next_PC = PC + 4;
        toWB_mode = 2'b00;
        BRAM_store_mode = 3'b111;
        BRAM_load_mode = 3'b111;


        case (opcode)
            7'b0110111: begin //LUI
                operand_a = imm_u;
                operand_b = 2'd12;
                alu_control = 4'b0_001;
                EX_result = alu_result;
                toWB_mode = 2'b01;
            end
            7'b0010111: begin //AUIPC
                operand_a = PC;
                operand_b = (imm_u << 12);
                alu_control = 4'b0_000;
                EX_result = alu_result;
            end
            7'b1101111: begin //JAL
                operand_a = PC;
                operand_b = imm_j;
                alu_control = 4'b0_000;
                next_PC = alu_result;

                EX_result = PC + 4;
            end
            7'b1100111: begin //JALR
                operand_a = rs1_data;
                operand_b = imm_i;
                alu_control = 4'b0_000;
                next_PC = alu_result & ~1;

                EX_result = PC + 4;
            end
            7'b1100011: begin //Branch
                if (branch_taken) begin
                    next_PC = PC + imm_b;
                end
            end
            7'b0000011: begin //Load
                operand_a = rs1_data;
                operand_b = imm_i;
                alu_control = 4'b0_000;
                EX_result = alu_result;
                toWB_mode = 2'b10;

                BRAM_read_addr = alu_result[15:0];
                BRAM_load_mode = funct3;
                BRAM_store_mode = 3'b111;
            end
            7'b0100011: begin //Store
                operand_a = rs1_data;
                operand_b = imm_s;
                alu_control = 4'b0_000;
                EX_result = alu_result;
                toWB_mode = 2'b11;

                BRAM_read_addr = alu_result[15:0];
                BRAM_load_mode = 3'b111;
                BRAM_store_mode = funct3;
                BRAM_data_in = rs2_data;
            end
            7'b0010011: begin //Immediate ALU
                operand_a = rs1_data;
                operand_b = imm_i;
                alu_control = {BRAMInstruction[30], funct3};
                EX_result = alu_result;
            end
            7'b0110011: begin //Register ALU
                operand_a = rs1_data;
                operand_b = rs2_data;
                alu_control = {BRAMInstruction[30], funct3};
                EX_result = alu_result;
            end
            7'b0001111: begin //FENCE
                operand_a = 32'b0;
                operand_b = 32'b0;
                alu_control = 4'b0_000;
            end
             7'b1110011: begin //ECALL/EBREAK
                operand_a = 32'b0;
                operand_b = 32'b0;
                alu_control = 4'b0_000;
            end
            7'b1110111: begin //CSR
                toWB_mode = 2'b01;
                if(funct3 == 3'b001) begin //CSRRW
                    GetCSR(csr_addr, EX_result);
                    EX_csr_result = rs1_data;
                end else if (funct3 == 3'b010) begin //CSRRS
                    GetCSR(csr_addr, EX_result);
                    operand_a = EX_result;
                    operand_b = rs1_data;
                    alu_control = 4'b0_110; //OR
                    EX_csr_result = alu_result;
                end else if (funct3 == 3'b011) begin //CSRRC
                    GetCSR(csr_addr, EX_result);
                    operand_a = EX_result;
                    operand_b = ~rs1_data;
                    alu_control = 4'b0_111; //AND
                    EX_csr_result = alu_result;
                end else if (funct3 == 3'b101) begin //CSRRWI
                    EX_result = csr_addr;
                    EX_csr_result = uimm;
                end else if (funct3 == 3'b110) begin //CSRRSI
                    GetCSR(csr_addr, EX_result);
                    operand_a = EX_result;
                    operand_b = uimm;
                    alu_control = 4'b0_110; //OR
                    EX_csr_result = alu_result;
                end else if (funct3 == 3'b111) begin //CSRRCI
                    GetCSR(csr_addr, EX_result);
                    operand_a = EX_result;
                    operand_b = ~uimm;
                    alu_control = 4'b0_111; 
                    EX_csr_result = alu_result;
                end
            end
            7'b0000000: begin //NOP
                operand_a = 32'b0;
                operand_b = 32'b0;
                alu_control = 4'b0_000;
                EX_result = 32'b0;
            end
            default: begin
                operand_a_addr = 5'b00000;
                operand_b_addr = 5'b00000;
                alu_control = 4'b0_000;
                EX_result = 32'b0;
            end
        endcase
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            PC <= 32'b0;
            cycle <= 64'b0;
            instret <= 64'b0;
            mtime <= 64'b0;
            mtimecmp <= 64'hFFFFFFFFFFFFFFFF;
        end else begin
            PC <= next_PC;
            cycle <= cycle + 1;
            mtime <= mtime + 1;
            toWB_Result_Reg <= EX_result;
            toWB_rd_addr_Reg <= rd_addr;
            toWB_csr_addr_Reg <= csr_addr;
            toWB_csr_data_Reg <= EX_csr_result;
            toWB_mode_Reg <= toWB_mode;
        end
    end

    //MEM/WB logic 
    always @(*) begin
        if (toWB_mode_Reg == 2'b00) begin //GPR
            WB_rd_addr = toWB_rd_addr_Reg;
            WB_rd_data = toWB_Result_Reg;
            WB_write_enable = 1'b1;
        end else if (toWB_mode_Reg == 2'b01) begin //CSR
            SetCSR(toWB_csr_addr_Reg[11:0], toWB_csr_data_Reg);
            WB_rd_addr = toWB_rd_addr_Reg;
            WB_rd_data = toWB_Result_Reg;
            WB_write_enable = 1'b1;
        end else if (toWB_mode_Reg == 2'b10) begin //Load
            WB_rd_data = BRAM_data_out;
            WB_rd_addr = toWB_rd_addr_Reg;
            WB_write_enable = 1'b1;
        end else if (toWB_mode_Reg == 2'b11) begin //Store
            //Write rs2_data to BRAM_data_in and set BRAM_write_enable
        end
    end


endmodule