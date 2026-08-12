// GPIO bank: WIDTH parallel pins behind one banked register file.
// Each pin has an independent input wire (pin_in) and output wire
// (pin_out) -- there is no electrical tri-state; DIR only gates whether
// writes to DATA_OUT/SET/CLR take effect on that bit.
//
// Inputs are double-flopped (sync0/sync1) before use, both for the
// DATA_IN readback and for edge detection, since pin_in may be fully
// asynchronous to clk.
//
// Bus side (word slots, see TopLayer's MMIO map):
//   0 DATA_IN      RO      synchronized input, one bit per pin
//   1 DATA_OUT     RW      output latch (readback of what's driven)
//   2 DIR          RW      1 = pin's writes take effect, 0 = ignored
//   3 SET          WO      write-1-to-set bits in DATA_OUT (masked by DIR)
//   4 CLR          WO      write-1-to-clear bits in DATA_OUT (masked by DIR)
//   5 INT_ENABLE   RW      1 = pin armed to raise irq
//   6 INT_RISE_EN  RW      1 = rising edge arms the interrupt
//   7 INT_FALL_EN  RW      1 = falling edge arms the interrupt
//   8 INT_PENDING  RW1C    edge-latched; write 1 to clear
module GPIO #(
    parameter WIDTH = 32
) (
    input  wire             clk,
    input  wire             rst,

    input  wire [WIDTH-1:0] pin_in,
    output wire [WIDTH-1:0] pin_out,

    input  wire [3:0]       waddr,
    input  wire             we,
    input  wire [WIDTH-1:0] wdata,

    input  wire [3:0]       raddr,
    output reg  [31:0]      rdata,

    output wire             irq
);

    localparam SLOT_DATA_IN     = 4'd0;
    localparam SLOT_DATA_OUT    = 4'd1;
    localparam SLOT_DIR         = 4'd2;
    localparam SLOT_SET         = 4'd3;
    localparam SLOT_CLR         = 4'd4;
    localparam SLOT_INT_ENABLE  = 4'd5;
    localparam SLOT_INT_RISE_EN = 4'd6;
    localparam SLOT_INT_FALL_EN = 4'd7;
    localparam SLOT_INT_PENDING = 4'd8;

    reg [WIDTH-1:0] data_out;
    reg [WIDTH-1:0] dir;
    reg [WIDTH-1:0] int_enable;
    reg [WIDTH-1:0] int_rise_en;
    reg [WIDTH-1:0] int_fall_en;
    reg [WIDTH-1:0] int_pending;

    // ---- input synchronizer + edge detect ----
    reg [WIDTH-1:0] sync0, sync1, sync1_d;
    wire [WIDTH-1:0] rising_edge  = sync1 & ~sync1_d;
    wire [WIDTH-1:0] falling_edge = ~sync1 & sync1_d;
    wire [WIDTH-1:0] edge_fire    = int_enable &
                                     ((int_rise_en & rising_edge) | (int_fall_en & falling_edge));

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            sync0  <= {WIDTH{1'b0}};
            sync1  <= {WIDTH{1'b0}};
            sync1_d <= {WIDTH{1'b0}};
        end else begin
            sync0   <= pin_in;
            sync1   <= sync0;
            sync1_d <= sync1;
        end
    end

    // ---- register writes ----
    wire [WIDTH-1:0] write_mask = wdata & dir;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            data_out    <= {WIDTH{1'b0}};
            dir         <= {WIDTH{1'b0}};
            int_enable  <= {WIDTH{1'b0}};
            int_rise_en <= {WIDTH{1'b0}};
            int_fall_en <= {WIDTH{1'b0}};
        end else if (we) begin
            case (waddr)
                SLOT_DATA_OUT:    data_out <= (data_out & ~dir) | write_mask;
                SLOT_DIR:         dir <= wdata;
                SLOT_SET:         data_out <= data_out | write_mask;
                SLOT_CLR:         data_out <= data_out & ~write_mask;
                SLOT_INT_ENABLE:  int_enable  <= wdata;
                SLOT_INT_RISE_EN: int_rise_en <= wdata;
                SLOT_INT_FALL_EN: int_fall_en <= wdata;
                default: ;
            endcase
        end
    end

    // ---- INT_PENDING: edge-set, write-1-to-clear (set wins same cycle) ----
    wire [WIDTH-1:0] pending_clear = (we && (waddr == SLOT_INT_PENDING)) ? wdata : {WIDTH{1'b0}};

    always @(posedge clk or posedge rst) begin
        if (rst) int_pending <= {WIDTH{1'b0}};
        else     int_pending <= (int_pending & ~pending_clear) | edge_fire;
    end

    always @(*) begin
        case (raddr)
            SLOT_DATA_IN:     rdata = sync1;
            SLOT_DATA_OUT:    rdata = data_out;
            SLOT_DIR:         rdata = dir;
            SLOT_INT_ENABLE:  rdata = int_enable;
            SLOT_INT_RISE_EN: rdata = int_rise_en;
            SLOT_INT_FALL_EN: rdata = int_fall_en;
            SLOT_INT_PENDING: rdata = int_pending;
            default:          rdata = 32'b0; // SET/CLR read as 0 (write-only)
        endcase
    end

    assign pin_out = data_out;
    assign irq     = |int_pending;

endmodule
