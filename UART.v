// 8N1 UART with TX and RX FIFOs.
//
// Bus side (2 word slots per UART):
//   DATA   (offset 0): write pushes a byte to TX FIFO; read pops RX FIFO head
//   STATUS (offset 1): read-only flags
//                      bit0 TX_READY (TX FIFO not full)
//                      bit1 TX_EMPTY (TX FIFO empty and line idle)
//                      bit2 RX_VALID (RX FIFO not empty)
//                      bit3 RX_FULL  (RX FIFO full / possible overrun)
//
// Serial side: tx (output line), rx (input line), 8 data bits, 1 stop bit.
// CLKS_PER_BIT sets the baud rate = clk / CLKS_PER_BIT.
module UART #(
    parameter CLKS_PER_BIT = 16
) (
    input  wire        clk,
    input  wire        rst,

    input  wire        rx,          // serial in
    output wire        tx,          // serial out

    input  wire        wr_en,       // store strobe to DATA (push TX)
    input  wire [7:0]  wr_data,     // byte to transmit
    input  wire        rd_data_en,  // load strobe to DATA (pop RX)
    input  wire        rd_sel,      // 0: rdata=DATA(rx head), 1: rdata=STATUS
    output wire [31:0] rdata
);

    // ---------------- TX FIFO (depth 8) ----------------
    reg  [7:0] txbuf [0:7];
    reg  [2:0] tx_wr, tx_rd;
    reg  [3:0] tx_cnt;
    wire tx_full  = (tx_cnt == 4'd8);
    wire tx_empty = (tx_cnt == 4'd0);

    // ---------------- RX FIFO (depth 8) ----------------
    reg  [7:0] rxbuf [0:7];
    reg  [2:0] rx_wr, rx_rd;
    reg  [3:0] rx_cnt;
    wire rx_full  = (rx_cnt == 4'd8);
    wire rx_empty = (rx_cnt == 4'd0);

    // ---------------- TX shift FSM ----------------
    localparam TX_IDLE=2'd0, TX_START=2'd1, TX_DATA=2'd2, TX_STOP=2'd3;
    reg [1:0]  tx_state;
    reg [15:0] tx_baud;
    reg [2:0]  tx_bit;
    reg [7:0]  tx_shift;
    reg        tx_line;
    wire       tx_pop = (tx_state == TX_IDLE) && !tx_empty;

    // ---------------- RX shift FSM ----------------
    localparam RX_IDLE=2'd0, RX_START=2'd1, RX_DATA=2'd2, RX_STOP=2'd3;
    reg [1:0]  rx_state;
    reg [15:0] rx_baud;
    reg [2:0]  rx_bit;
    reg [7:0]  rx_shift;
    reg        rx_s1, rx_s2;                 // 2-flop synchronizer
    wire       rx_push = (rx_state == RX_STOP) && (rx_baud == CLKS_PER_BIT-1) && !rx_full;

    integer i;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            tx_wr <= 0; tx_rd <= 0; tx_cnt <= 0;
            rx_wr <= 0; rx_rd <= 0; rx_cnt <= 0;
            tx_state <= TX_IDLE; tx_baud <= 0; tx_bit <= 0; tx_shift <= 0; tx_line <= 1'b1;
            rx_state <= RX_IDLE; rx_baud <= 0; rx_bit <= 0; rx_shift <= 0;
            rx_s1 <= 1'b1; rx_s2 <= 1'b1;
        end else begin
            rx_s1 <= rx;
            rx_s2 <= rx_s1;

            // ---- TX FIFO push (bus) / pop (FSM) ----
            if (wr_en && !tx_full) begin
                txbuf[tx_wr] <= wr_data;
                tx_wr <= tx_wr + 3'd1;
            end
            if (wr_en && !tx_full && !tx_pop)      tx_cnt <= tx_cnt + 4'd1;
            else if (!(wr_en && !tx_full) && tx_pop) tx_cnt <= tx_cnt - 4'd1;

            // ---- TX FSM ----
            case (tx_state)
                TX_IDLE: begin
                    tx_line <= 1'b1;
                    tx_baud <= 0;
                    tx_bit  <= 0;
                    if (!tx_empty) begin
                        tx_shift <= txbuf[tx_rd];
                        tx_rd    <= tx_rd + 3'd1;
                        tx_state <= TX_START;
                    end
                end
                TX_START: begin
                    tx_line <= 1'b0;
                    if (tx_baud == CLKS_PER_BIT-1) begin
                        tx_baud  <= 0;
                        tx_state <= TX_DATA;
                    end else tx_baud <= tx_baud + 16'd1;
                end
                TX_DATA: begin
                    tx_line <= tx_shift[tx_bit];
                    if (tx_baud == CLKS_PER_BIT-1) begin
                        tx_baud <= 0;
                        if (tx_bit == 3'd7) tx_state <= TX_STOP;
                        else tx_bit <= tx_bit + 3'd1;
                    end else tx_baud <= tx_baud + 16'd1;
                end
                TX_STOP: begin
                    tx_line <= 1'b1;
                    if (tx_baud == CLKS_PER_BIT-1) begin
                        tx_baud  <= 0;
                        tx_state <= TX_IDLE;
                    end else tx_baud <= tx_baud + 16'd1;
                end
            endcase

            // ---- RX FSM ----
            case (rx_state)
                RX_IDLE: begin
                    rx_baud <= 0;
                    rx_bit  <= 0;
                    if (rx_s2 == 1'b0) rx_state <= RX_START;   // start bit
                end
                RX_START: begin
                    if (rx_baud == (CLKS_PER_BIT/2)-1) begin
                        rx_baud <= 0;
                        if (rx_s2 == 1'b0) rx_state <= RX_DATA; // valid start
                        else rx_state <= RX_IDLE;               // false start
                    end else rx_baud <= rx_baud + 16'd1;
                end
                RX_DATA: begin
                    if (rx_baud == CLKS_PER_BIT-1) begin
                        rx_baud <= 0;
                        rx_shift[rx_bit] <= rx_s2;
                        if (rx_bit == 3'd7) rx_state <= RX_STOP;
                        else rx_bit <= rx_bit + 3'd1;
                    end else rx_baud <= rx_baud + 16'd1;
                end
                RX_STOP: begin
                    if (rx_baud == CLKS_PER_BIT-1) begin
                        rx_baud  <= 0;
                        rx_state <= RX_IDLE;
                    end else rx_baud <= rx_baud + 16'd1;
                end
            endcase

            // ---- RX FIFO push (FSM) / pop (bus) ----
            if (rx_push) begin
                rxbuf[rx_wr] <= rx_shift;
                rx_wr <= rx_wr + 3'd1;
            end
            if (rx_push && !(rd_data_en && !rx_empty))      rx_cnt <= rx_cnt + 4'd1;
            else if (!rx_push && (rd_data_en && !rx_empty)) rx_cnt <= rx_cnt - 4'd1;
            if (rd_data_en && !rx_empty) rx_rd <= rx_rd + 3'd1;
        end
    end

    assign tx = tx_line;

    wire [7:0]  rx_head = rxbuf[rx_rd];
    wire [31:0] status  = {28'b0, rx_full, !rx_empty, (tx_empty && tx_state==TX_IDLE), !tx_full};
    assign rdata = rd_sel ? status : {24'b0, rx_head};

endmodule