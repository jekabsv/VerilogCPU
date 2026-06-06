module BRAM (
    input wire clk,
    input wire [15:0] write_addr,
    input wire [15:0] read_addr,
    input wire [15:0] fetch_addr,

    input wire [31:0] data_in,
    input wire [2:0] write_mode, //000 - SB, 001 - SH, 010 - SW
    input wire [2:0] read_mode; //000 - LB, 001 - LH, 010 - LW, 100 - LBU, 101 - LHU
    
    output reg [31:0] data_out,
    output reg [31:0] instruction_out
);

    reg [7:0] InstructionMem [2**16-1:0];
    reg [7:0] DataMem [2**16-1:0];


    always @(posedge clk) begin
        if(write_mode == 3'b000) begin //SB
            DataMem[write_addr] <= data_in[7:0];
        end else if (write_mode == 3'b001) begin //SH
            DataMem[write_addr] <= data_in[7:0];
            DataMem[write_addr + 1] <= data_in[15:8];
        end else if (write_mode == 3'b010) begin //SW
            DataMem[write_addr] <= data_in[7:0];
            DataMem[write_addr + 1] <= data_in[15:8];
            DataMem[write_addr + 2] <= data_in[23:16];
            DataMem[write_addr + 3] <= data_in[31:24];
        end
    end

    always @(posedge clk) begin

        if (load_mode == 3'b000) begin // LB: SignExtend(Mem8)
            data_out = {{24{DataMem[read_addr][7]}}, DataMem[read_addr]};
        
        end else if (load_mode == 3'b001) begin // LH: SignExtend(Mem16)
            data_out = {{16{DataMem[read_addr + 1][7]}}, DataMem[read_addr + 1], DataMem[read_addr]};
            
        end else if (load_mode == 3'b010) begin // LW: SignExtend(Mem32)
            data_out = {DataMem[read_addr + 3], DataMem[read_addr + 2], DataMem[read_addr + 1], DataMem[read_addr]};
            
        end else if (load_mode == 3'b100) begin // LBU: ZeroExtend(Mem8)
            data_out = {24'b0, DataMem[read_addr]};
            
        end else if (load_mode == 3'b101) begin // LHU: ZeroExtend(Mem16)
            data_out = {16'b0, DataMem[read_addr + 1], DataMem[read_addr]};
            
        end else begin
            data_out = 32'b0;
        end
        
        instruction_out <= {InstructionMem[fetch_addr + 3], InstructionMem[fetch_addr + 2], InstructionMem[fetch_addr + 1], InstructionMem[fetch_addr]};
    end

endmodule