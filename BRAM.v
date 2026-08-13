// Unified instruction+data memory, three independent synchronous ports into
// one backing array (write / data-read / fetch). Previously InstructionMem
// and DataMem were two separate 64KB arrays -- a strict Harvard split that
// made anything placed in "program space" (e.g. .rodata constants a linker
// would normally put next to .text) unreachable by ordinary load
// instructions, since lw/lb only ever addressed DataMem. Sharing one array
// means an address is the same byte whether it's reached via fetch_addr or
// via read_addr/write_addr, so a normal linker script can place .text and
// .rodata/.data in the same 64KB space and loads work as expected. This
// halves total combined code+data capacity versus the old two-array split
// (64KB shared instead of 64KB+64KB) -- widen the address ports if that
// becomes a real constraint.
module BRAM (
    input wire clk,
    input wire [15:0] write_addr,
    input wire [15:0] read_addr,
    input wire [15:0] fetch_addr,

    input wire [31:0] data_in,
    input wire [2:0] write_mode, //000 - SB, 001 - SH, 010 - SW
    input wire [2:0] read_mode, //000 - LB, 001 - LH, 010 - LW, 100 - LBU, 101 - LHU

    output reg [31:0] data_out,
    output reg [31:0] instruction_out
);

    reg [7:0] Mem [2**16-1:0];


    always @(posedge clk) begin
        if(write_mode == 3'b000) begin //SB
            Mem[write_addr] <= data_in[7:0];
        end else if (write_mode == 3'b001) begin //SH
            Mem[write_addr] <= data_in[7:0];
            Mem[write_addr + 1] <= data_in[15:8];
        end else if (write_mode == 3'b010) begin //SW
            Mem[write_addr] <= data_in[7:0];
            Mem[write_addr + 1] <= data_in[15:8];
            Mem[write_addr + 2] <= data_in[23:16];
            Mem[write_addr + 3] <= data_in[31:24];
        end
    end

    always @(posedge clk) begin

        if (read_mode == 3'b000) begin // LB: SignExtend(Mem8)
            data_out <= {{24{Mem[read_addr][7]}}, Mem[read_addr]};

        end else if (read_mode == 3'b001) begin // LH: SignExtend(Mem16)
            data_out <= {{16{Mem[read_addr + 1][7]}}, Mem[read_addr + 1], Mem[read_addr]};

        end else if (read_mode == 3'b010) begin // LW: SignExtend(Mem32)
            data_out <= {Mem[read_addr + 3], Mem[read_addr + 2], Mem[read_addr + 1], Mem[read_addr]};

        end else if (read_mode == 3'b100) begin // LBU: ZeroExtend(Mem8)
            data_out <= {24'b0, Mem[read_addr]};

        end else if (read_mode == 3'b101) begin // LHU: ZeroExtend(Mem16)
            data_out <= {16'b0, Mem[read_addr + 1], Mem[read_addr]};

        end else begin
            data_out <= 32'b0;
        end

        instruction_out <= {Mem[fetch_addr + 3], Mem[fetch_addr + 2], Mem[fetch_addr + 1], Mem[fetch_addr]};
    end

endmodule
