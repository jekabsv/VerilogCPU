`timescale 1ns / 1ps
`include "Registry.v"
`include "ALU.v"



//to Do:
//add I/O port in BRAM

module CPU (
    input wire clk,
    input wire rst,
    input wire irq_external,
    input wire timer_int,
    input wire soft_int,

    output wire [15:0] mem_fetch_addr,
    output wire [31:0] mem_read_addr,
    output wire [31:0] mem_write_addr,
    output wire [31:0] mem_data_in,
    output wire [2:0]  mem_read_mode,
    output wire [2:0]  mem_write_mode,
    input  wire [31:0] mem_data_out,
    input  wire [31:0] mem_instruction
);

    // =====================================================================
    // CSR state
    // =====================================================================
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


    // =====================================================================
    // Program counter
    //   PC        - address currently being fetched
    //   PC_decode - address of the instruction currently in Decode/Execute
    // =====================================================================
    reg [31:0] PC;
    reg [31:0] PC_decode;
    reg [31:0] next_PC;


    // =====================================================================
    // FETCH stage
    //   BRAM registers the fetch, so its output is the Fetch->Decode latch.
    //   flush_d turns the wrong-path instruction into a bubble.
    // =====================================================================
    wire [31:0] IF_instruction = mem_instruction;
    reg  flush_d;
    wire [31:0] BRAMInstruction = flush_d ? 32'b0 : IF_instruction;


    // =====================================================================
    // DECODE fields
    // =====================================================================
    wire [6:0] opcode = BRAMInstruction[6:0];
    wire [2:0] funct3 = BRAMInstruction[14:12];
    wire [6:0] funct7 = BRAMInstruction[31:25];

    wire [4:0] rs1_addr = BRAMInstruction[19:15];
    wire [4:0] rs2_addr = BRAMInstruction[24:20];
    wire [4:0] rd_addr  = BRAMInstruction[11:7];
    wire [4:0] shamt    = BRAMInstruction[24:20];

    wire [31:0] imm_i = {{20{BRAMInstruction[31]}}, BRAMInstruction[31:20]};
    wire [31:0] imm_s = {{20{BRAMInstruction[31]}}, BRAMInstruction[31:25], BRAMInstruction[11:7]};
    wire [31:0] imm_b = {{19{BRAMInstruction[31]}}, BRAMInstruction[31], BRAMInstruction[7], BRAMInstruction[30:25], BRAMInstruction[11:8], 1'b0};
    wire [31:0] imm_u = {BRAMInstruction[31:12], 12'b0};
    wire [31:0] imm_j = {{11{BRAMInstruction[31]}}, BRAMInstruction[31], BRAMInstruction[19:12], BRAMInstruction[20], BRAMInstruction[30:21], 1'b0};

    wire [11:0] csr_addr = BRAMInstruction[31:20];
    wire [31:0] uimm     = {27'b0, BRAMInstruction[19:15]};


    // =====================================================================
    // Register file wiring
    // =====================================================================
    reg  [4:0]  operand_a_addr;
    reg  [4:0]  operand_b_addr;
    wire [31:0] rs1_data;
    wire [31:0] rs2_data;

    wire [31:0] wb_forward_data;
    wire [31:0] rs1_data_fwd;
    wire [31:0] rs2_data_fwd;
    wire [31:0] csr_forward_data;
    wire        csr_forward;
    wire        wb_write_gpr;
    reg  [31:0] csr_read_value;


    // =====================================================================
    // ALU wiring
    // =====================================================================
    reg  [3:0]  alu_control;
    reg  [31:0] operand_a;
    reg  [31:0] operand_b;
    wire [31:0] alu_result;


    // =====================================================================
    // Data memory wiring
    // =====================================================================
    reg  [31:0] BRAM_read_addr;
    reg  [31:0] BRAM_write_addr;
    reg  [31:0] BRAM_data_in;
    wire [31:0] BRAM_data_out = mem_data_out;
    reg  [2:0]  BRAM_load_mode;
    reg  [2:0]  BRAM_store_mode;


    // =====================================================================
    // Execute results and Decode->Writeback pipeline registers
    //   toWB_mode: 00 - GPR, 01 - CSR, 10 - Load, 11 - none
    // =====================================================================
    reg  [31:0] EX_result;
    reg  [31:0] EX_csr_result;
    reg  [1:0]  toWB_mode;

    reg  [31:0] toWB_Result_Reg;
    reg  [4:0]  toWB_rd_addr_Reg;
    reg  [11:0] toWB_csr_addr_Reg;
    reg  [31:0] toWB_csr_data_Reg;
    reg  [1:0]  toWB_mode_Reg;


    // =====================================================================
    // Writeback wiring
    // =====================================================================
    reg  [4:0]  WB_rd_addr;
    reg  [31:0] WB_rd_data;
    reg         WB_write_enable;


    wire flush;
    reg  branch_taken;


    // =====================================================================
    // Trap / interrupt wiring
    //   valid_instr - a real (non-bubble) instruction is in Decode/Execute
    //   take_trap   - enter the trap handler this cycle (exception or IRQ)
    //   take_mret   - MRET redirect this cycle
    // =====================================================================
    wire valid_instr = (BRAMInstruction != 32'b0);

    reg  ecall_instr;
    reg  ebreak_instr;
    reg  illegal_instr;
    reg  mret_instr;
    reg  take_trap;
    reg  take_mret;
    reg  [31:0] trap_cause;
    reg  [31:0] trap_tval;

    wire irq_ext   = mstatus[3] & mie[11] & (mip[11] | irq_external);
    wire irq_soft  = mstatus[3] & mie[3]  & (mip[3]  | soft_int);
    wire irq_timer = mstatus[3] & mie[7]  & (mip[7]  | timer_int);
    wire irq_ready = irq_ext | irq_soft | irq_timer;


    // =====================================================================
    // Submodules
    // =====================================================================
    assign mem_fetch_addr = PC[15:0];
    assign mem_read_addr  = BRAM_read_addr;
    assign mem_write_addr = BRAM_write_addr;
    assign mem_data_in    = BRAM_data_in;
    assign mem_read_mode  = BRAM_load_mode;
    assign mem_write_mode = BRAM_store_mode;

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

    assign wb_write_gpr = (toWB_mode_Reg != 2'b11) && (toWB_rd_addr_Reg != 5'b00000);
    assign wb_forward_data = (toWB_mode_Reg == 2'b10) ? BRAM_data_out : toWB_Result_Reg;
    assign rs1_data_fwd = (wb_write_gpr && (toWB_rd_addr_Reg == rs1_addr) && (rs1_addr != 5'b00000)) ? wb_forward_data : rs1_data;
    assign rs2_data_fwd = (wb_write_gpr && (toWB_rd_addr_Reg == rs2_addr) && (rs2_addr != 5'b00000)) ? wb_forward_data : rs2_data;
    assign csr_forward = (toWB_mode_Reg == 2'b01) && (toWB_csr_addr_Reg == csr_addr);
    assign csr_forward_data = toWB_csr_data_Reg;

    wire [31:0] mepc_forwarded = (toWB_mode_Reg == 2'b01 && toWB_csr_addr_Reg == 12'h341) ? toWB_csr_data_Reg : mepc;

    ALU alu (
        .alu_control(alu_control),
        .operand_a(operand_a),
        .operand_b(operand_b),
        .alu_result(alu_result)
    );


    // =====================================================================
    // CSR access
    // =====================================================================
    function [31:0] GetCSR;
        input [11:0] addr;
        begin
            case (addr)
                12'h300: GetCSR = mstatus;
                12'h301: GetCSR = misa;
                12'h304: GetCSR = mie;
                12'h305: GetCSR = mtvec;
                12'h340: GetCSR = mscratch;
                12'h341: GetCSR = mepc;
                12'h342: GetCSR = mcause;
                12'h343: GetCSR = mtval;
                12'h344: GetCSR = mip;
                12'hC00: GetCSR = cycle[31:0];
                12'hC02: GetCSR = instret[31:0];
                12'hC80: GetCSR = cycle[63:32];
                12'hC82: GetCSR = instret[63:32];
                default: GetCSR = 32'b0;
            endcase
        end
    endfunction

    task SetCSR;
        input [11:0] addr;
        input [31:0] value;
        begin
            case (addr)
                12'h300: mstatus  <= value;
                12'h304: mie      <= value;
                12'h305: mtvec    <= value;
                12'h340: mscratch <= value;
                12'h341: mepc     <= value;
                12'h342: mcause   <= value;
                12'h343: mtval    <= value;
                12'h344: mip      <= value;
                default: ;
            endcase
        end
    endtask


    // =====================================================================
    // DECODE/EXECUTE - branch condition
    // =====================================================================
    always @(*) begin
        case (funct3)
            3'b000:  branch_taken = (rs1_data_fwd == rs2_data_fwd);
            3'b001:  branch_taken = (rs1_data_fwd != rs2_data_fwd);
            3'b100:  branch_taken = ($signed(rs1_data_fwd) <  $signed(rs2_data_fwd));
            3'b101:  branch_taken = ($signed(rs1_data_fwd) >= $signed(rs2_data_fwd));
            3'b110:  branch_taken = (rs1_data_fwd <  rs2_data_fwd);
            3'b111:  branch_taken = (rs1_data_fwd >= rs2_data_fwd);
            default: branch_taken = 1'b0;
        endcase
    end

    assign flush = take_trap ||
                   take_mret ||
                   (opcode == 7'b1101111) ||
                   (opcode == 7'b1100111) ||
                   (opcode == 7'b1100011 && branch_taken);


    // =====================================================================
    // Trap cause / trap value selection
    //   Interrupts have priority over synchronous exceptions.
    // =====================================================================
    always @(*) begin
        trap_cause = 32'b0;
        trap_tval  = 32'b0;

        if (irq_ready) begin
            if (irq_ext) begin
                trap_cause = 32'h8000000B;
            end else if (irq_soft) begin
                trap_cause = 32'h80000003;
            end else begin
                trap_cause = 32'h80000007;
            end
        end else if (ecall_instr) begin
            trap_cause = 32'd11;
        end else if (ebreak_instr) begin
            trap_cause = 32'd3;
            trap_tval  = PC_decode;
        end else begin
            trap_cause = 32'd2;
            trap_tval  = BRAMInstruction;
        end
    end


    // =====================================================================
    // DECODE/EXECUTE - main decode
    // =====================================================================
    always @(*) begin
        operand_a_addr  = rs1_addr;
        operand_b_addr  = rs2_addr;
        operand_a       = 32'b0;
        operand_b       = 32'b0;
        alu_control     = 4'b0000;
        EX_result       = 32'b0;
        EX_csr_result   = 32'b0;
        csr_read_value  = 32'b0;
        next_PC         = PC + 4;
        toWB_mode       = 2'b11;
        BRAM_read_addr  = 32'b0;
        BRAM_write_addr = 32'b0;
        BRAM_data_in    = 32'b0;
        BRAM_load_mode  = 3'b111;
        BRAM_store_mode = 3'b111;

        ecall_instr   = 1'b0;
        ebreak_instr  = 1'b0;
        illegal_instr = 1'b0;
        mret_instr    = 1'b0;
        take_trap     = 1'b0;
        take_mret     = 1'b0;

        case (opcode)
            7'b0110111: begin //LUI
                EX_result = imm_u;
                toWB_mode = 2'b00;
            end
            7'b0010111: begin //AUIPC
                EX_result = PC_decode + imm_u;
                toWB_mode = 2'b00;
            end
            7'b1101111: begin //JAL
                EX_result = PC_decode + 4;
                next_PC   = PC_decode + imm_j;
                toWB_mode = 2'b00;
            end
            7'b1100111: begin //JALR
                EX_result = PC_decode + 4;
                next_PC   = (rs1_data_fwd + imm_i) & ~32'd1;
                toWB_mode = 2'b00;
            end
            7'b1100011: begin //Branch
                if (branch_taken) begin
                    next_PC = PC_decode + imm_b;
                end
                toWB_mode = 2'b11;
            end
            7'b0000011: begin //Load
                operand_a      = rs1_data_fwd;
                operand_b      = imm_i;
                alu_control    = 4'b0000;
                BRAM_read_addr = alu_result;
                BRAM_load_mode = funct3;
                toWB_mode      = 2'b10;
            end
            7'b0100011: begin //Store
                operand_a       = rs1_data_fwd;
                operand_b       = imm_s;
                alu_control     = 4'b0000;
                BRAM_write_addr = alu_result;
                BRAM_data_in    = rs2_data_fwd;
                BRAM_store_mode = funct3;
                toWB_mode       = 2'b11;
            end
            7'b0010011: begin //Immediate ALU
                operand_a = rs1_data_fwd;
                operand_b = imm_i;
                if (funct3 == 3'b101) begin
                    alu_control = {BRAMInstruction[30], funct3};
                end else begin
                    alu_control = {1'b0, funct3};
                end
                EX_result = alu_result;
                toWB_mode = 2'b00;
            end
            7'b0110011: begin //Register ALU
                operand_a   = rs1_data_fwd;
                operand_b   = rs2_data_fwd;
                alu_control = {BRAMInstruction[30], funct3};
                EX_result   = alu_result;
                toWB_mode   = 2'b00;
            end
            7'b0001111: begin //FENCE
                toWB_mode = 2'b11;
            end
            7'b1110011: begin //SYSTEM
                if (funct3 == 3'b000) begin //ECALL / EBREAK / MRET
                    toWB_mode = 2'b11;
                    if (BRAMInstruction[31:20] == 12'h000) begin
                        ecall_instr = 1'b1;
                    end else if (BRAMInstruction[31:20] == 12'h001) begin
                        ebreak_instr = 1'b1;
                    end else if (BRAMInstruction[31:20] == 12'h302) begin
                        mret_instr = 1'b1;
                    end
                end else begin //CSR access
                    toWB_mode = 2'b01;
                    csr_read_value = GetCSR(csr_addr);
                    if (csr_forward) begin
                        csr_read_value = csr_forward_data;
                    end
                    EX_result = csr_read_value;
                    if (funct3 == 3'b001) begin //CSRRW
                        EX_csr_result = rs1_data_fwd;
                    end else if (funct3 == 3'b010) begin //CSRRS
                        EX_csr_result = csr_read_value | rs1_data_fwd;
                    end else if (funct3 == 3'b011) begin //CSRRC
                        EX_csr_result = csr_read_value & ~rs1_data_fwd;
                    end else if (funct3 == 3'b101) begin //CSRRWI
                        EX_csr_result = uimm;
                    end else if (funct3 == 3'b110) begin //CSRRSI
                        EX_csr_result = csr_read_value | uimm;
                    end else if (funct3 == 3'b111) begin //CSRRCI
                        EX_csr_result = csr_read_value & ~uimm;
                    end else begin
                        EX_csr_result = csr_read_value;
                    end
                end
            end
            default: begin
                toWB_mode     = 2'b11;
                illegal_instr = 1'b1;
            end
        endcase

        take_trap = valid_instr && (irq_ready || ecall_instr || ebreak_instr || illegal_instr);
        take_mret = valid_instr && mret_instr;

        if (take_trap) begin
            next_PC         = {mtvec[31:2], 2'b00};
            toWB_mode       = 2'b11;
            BRAM_load_mode  = 3'b111;
            BRAM_store_mode = 3'b111;
        end else if (take_mret) begin
            next_PC   = mepc_forwarded;
            toWB_mode = 2'b11;
        end
    end


    // =====================================================================
    // Fetch/PC advance and Decode->Writeback pipeline registers
    // =====================================================================
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            PC                <= 32'b0;
            PC_decode         <= 32'b0;
            flush_d           <= 1'b0;
            cycle             <= 64'b0;
            instret           <= 64'b0;
            toWB_Result_Reg   <= 32'b0;
            toWB_rd_addr_Reg  <= 5'b0;
            toWB_csr_addr_Reg <= 12'b0;
            toWB_csr_data_Reg <= 32'b0;
            toWB_mode_Reg     <= 2'b11;
        end else begin
            PC        <= next_PC;
            PC_decode <= PC;
            flush_d   <= flush;

            cycle <= cycle + 1;
            if (valid_instr && !take_trap) begin
                instret <= instret + 1;
            end

            toWB_Result_Reg   <= EX_result;
            toWB_rd_addr_Reg  <= rd_addr;
            toWB_csr_addr_Reg <= csr_addr;
            toWB_csr_data_Reg <= EX_csr_result;
            toWB_mode_Reg     <= toWB_mode;
        end
    end


    // =====================================================================
    // MEM/WRITEBACK - register file write source
    // =====================================================================
    always @(*) begin
        WB_rd_addr      = 5'b0;
        WB_rd_data      = 32'b0;
        WB_write_enable = 1'b0;

        if (toWB_mode_Reg == 2'b00) begin //GPR
            WB_rd_addr      = toWB_rd_addr_Reg;
            WB_rd_data      = toWB_Result_Reg;
            WB_write_enable = 1'b1;
        end else if (toWB_mode_Reg == 2'b01) begin //CSR
            WB_rd_addr      = toWB_rd_addr_Reg;
            WB_rd_data      = toWB_Result_Reg;
            WB_write_enable = 1'b1;
        end else if (toWB_mode_Reg == 2'b10) begin //Load
            WB_rd_addr      = toWB_rd_addr_Reg;
            WB_rd_data      = BRAM_data_out;
            WB_write_enable = 1'b1;
        end else begin //none
            WB_write_enable = 1'b0;
        end
    end


    // =====================================================================
    // CSR / trap commit
    //   - Writeback-stage CSR instruction writes (lowest priority)
    //   - Trap entry / MRET update mstatus (highest priority)
    // =====================================================================
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            mstatus  <= 32'b0;
            mie      <= 32'b0;
            mip      <= 32'b0;
            mtvec    <= 32'b0;
            mepc     <= 32'b0;
            mcause   <= 32'b0;
            mtval    <= 32'b0;
            mscratch <= 32'b0;
        end else begin
            if (toWB_mode_Reg == 2'b01) begin
                SetCSR(toWB_csr_addr_Reg, toWB_csr_data_Reg);
            end

            if (take_trap) begin
                mepc           <= PC_decode;
                mcause         <= trap_cause;
                mtval          <= trap_tval;
                mstatus[7]     <= mstatus[3];
                mstatus[3]     <= 1'b0;
                mstatus[12:11] <= 2'b11;
            end else if (take_mret) begin
                mstatus[3]     <= mstatus[7];
                mstatus[7]     <= 1'b1;
                mstatus[12:11] <= 2'b11;
            end
        end
    end

endmodule