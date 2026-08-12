// Single-pin GPIO controller.
// Two physical wires: pin_in (from the outside world) and pin_out (to it).
// Two latches: in_latch samples the incoming pin, out_latch holds the value
// the CPU wrote (which drives pin_out).
//
// Bus side (one MMIO slot per pin):
//   write_en/write_bit : CPU store updates out_latch
//   read_bit           : current in_latch value returned on a CPU load
module GPIO (
    input  wire clk,
    input  wire rst,

    input  wire pin_in,      // physical input bit
    output wire pin_out,     // physical output bit

    input  wire write_en,    // bus: store targets this pin this cycle
    input  wire write_bit,   // bus: value to latch as output
    output wire read_bit     // bus: latched input value
);

    reg in_latch;
    reg out_latch;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            in_latch  <= 1'b0;
            out_latch <= 1'b0;
        end else begin
            in_latch <= pin_in;
            if (write_en) begin
                out_latch <= write_bit;
            end
        end
    end

    assign pin_out  = out_latch;
    assign read_bit = in_latch;

endmodule