

module Registry (
    input wire clk,
    input wire rst,
    input wire [4:0] rs1_addr,
    input wire [4:0] rs2_addr,
    input wire [4:0] rd_addr,
    input wire [31:0] rd_data,
    input wire reg_write_enable,
    
    output reg [31:0] rs1_data,
    output reg [31:0] rs2_data
);

    reg [31:0] registers [31:0];

    always @(*) begin
        rs1_data = registers[rs1_addr];
        rs2_data = registers[rs2_addr];
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin : rst_loop
            integer i;
            for (i = 0; i < 32; i = i + 1) begin
                registers[i] <= 32'b0;
            end
        end else if (reg_write_enable && rd_addr != 5'b00000) begin
            registers[rd_addr] <= rd_data;
        end
    end
endmodule