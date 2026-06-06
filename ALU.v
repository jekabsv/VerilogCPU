

module ALU (
    input wire [3:0]  alu_control, // {Instruction[30], funct3}
    input wire [31:0] operand_a, // rs1
    input wire [31:0] operand_b, // rs2  or immediate
    
    output reg [31:0] alu_result
);

    wire signed [31:0] signed_a = operand_a;
    wire signed [31:0] signed_b = operand_b;

    always @(*) begin
        case (alu_control)
            4'b0_000: alu_result = operand_a + operand_b;
            
            4'b0_001: alu_result = operand_a << operand_b[4:0];
            
            4'b0_010: 
            if(signed_a < signed_b) 
                alu_result = 32'h1; 
            else 
                alu_result = 32'h0;
            
            4'b0_011:
            if(operand_a < operand_b) 
                alu_result = 32'h1; 
            else 
                alu_result = 32'h0;
            
            4'b0_100: alu_result = operand_a ^ operand_b;
            
            4'b0_101: alu_result = operand_a >> operand_b[4:0];
            
            4'b0_110: alu_result = operand_a | operand_b;
            
            4'b0_111: alu_result = operand_a & operand_b;
            
            4'b1_000: alu_result = operand_a - operand_b;
            
            4'b1_101: alu_result = signed_a >>> operand_b[4:0];
            
            default:  alu_result = 32'b0;
        endcase
    end

endmodule