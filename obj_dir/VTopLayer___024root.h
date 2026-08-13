// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTopLayer.h for the primary calling header

#ifndef VERILATED_VTOPLAYER___024ROOT_H_
#define VERILATED_VTOPLAYER___024ROOT_H_  // guard

#include "verilated.h"


class VTopLayer__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTopLayer___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        VL_IN8(irq_external,0,0);
        VL_IN8(uart_rx,3,0);
        VL_OUT8(uart_tx,3,0);
        CData/*0:0*/ TopLayer__DOT__uart_irq0;
        CData/*0:0*/ TopLayer__DOT__uart_irq1;
        CData/*0:0*/ TopLayer__DOT__uart_irq2;
        CData/*0:0*/ TopLayer__DOT__uart_irq3;
        CData/*0:0*/ TopLayer__DOT__mmio_write_en;
        CData/*2:0*/ TopLayer__DOT__bram_write_mode;
        CData/*0:0*/ TopLayer__DOT__gpio_we;
        CData/*0:0*/ TopLayer__DOT____Vcellinp__uart0__rd_data_en;
        CData/*0:0*/ TopLayer__DOT____Vcellinp__uart0__wr_en;
        CData/*0:0*/ TopLayer__DOT____Vcellinp__uart1__rd_data_en;
        CData/*0:0*/ TopLayer__DOT____Vcellinp__uart1__wr_en;
        CData/*0:0*/ TopLayer__DOT____Vcellinp__uart2__rd_data_en;
        CData/*0:0*/ TopLayer__DOT____Vcellinp__uart2__wr_en;
        CData/*0:0*/ TopLayer__DOT____Vcellinp__uart3__rd_data_en;
        CData/*0:0*/ TopLayer__DOT____Vcellinp__uart3__wr_en;
        CData/*0:0*/ TopLayer__DOT__msip;
        CData/*0:0*/ TopLayer__DOT__read_was_mmio;
        CData/*0:0*/ TopLayer__DOT__cpu__DOT__flush_d;
        CData/*6:0*/ TopLayer__DOT__cpu__DOT__opcode;
        CData/*2:0*/ TopLayer__DOT__cpu__DOT__funct3;
        CData/*4:0*/ TopLayer__DOT__cpu__DOT__rd_addr;
        CData/*0:0*/ TopLayer__DOT__cpu__DOT__wb_write_gpr;
        CData/*2:0*/ TopLayer__DOT__cpu__DOT__BRAM_load_mode;
        CData/*1:0*/ TopLayer__DOT__cpu__DOT__toWB_mode;
        CData/*4:0*/ TopLayer__DOT__cpu__DOT__toWB_rd_addr_Reg;
        CData/*1:0*/ TopLayer__DOT__cpu__DOT__toWB_mode_Reg;
        CData/*4:0*/ TopLayer__DOT__cpu__DOT__WB_rd_addr;
        CData/*0:0*/ TopLayer__DOT__cpu__DOT__WB_write_enable;
        CData/*0:0*/ TopLayer__DOT__cpu__DOT__branch_taken;
        CData/*0:0*/ TopLayer__DOT__cpu__DOT__take_trap;
        CData/*0:0*/ TopLayer__DOT__cpu__DOT__take_mret;
        CData/*0:0*/ TopLayer__DOT__cpu__DOT__irq_ext;
        CData/*0:0*/ TopLayer__DOT__cpu__DOT__irq_soft;
        CData/*0:0*/ TopLayer__DOT__cpu__DOT__irq_ready;
        CData/*0:0*/ TopLayer__DOT__cpu__DOT____VdfgRegularize_h0c4dd555_2_3;
        CData/*2:0*/ TopLayer__DOT__uart0__DOT__ier;
        CData/*2:0*/ TopLayer__DOT__uart0__DOT__tx_wr;
        CData/*2:0*/ TopLayer__DOT__uart0__DOT__tx_rd;
        CData/*3:0*/ TopLayer__DOT__uart0__DOT__tx_cnt;
        CData/*0:0*/ TopLayer__DOT__uart0__DOT__tx_full;
        CData/*2:0*/ TopLayer__DOT__uart0__DOT__rx_wr;
        CData/*2:0*/ TopLayer__DOT__uart0__DOT__rx_rd;
        CData/*3:0*/ TopLayer__DOT__uart0__DOT__rx_cnt;
        CData/*0:0*/ TopLayer__DOT__uart0__DOT__rx_empty;
        CData/*1:0*/ TopLayer__DOT__uart0__DOT__tx_state;
        CData/*2:0*/ TopLayer__DOT__uart0__DOT__tx_bit;
        CData/*7:0*/ TopLayer__DOT__uart0__DOT__tx_shift;
        CData/*0:0*/ TopLayer__DOT__uart0__DOT__tx_line;
        CData/*0:0*/ TopLayer__DOT__uart0__DOT__tx_pop;
        CData/*1:0*/ TopLayer__DOT__uart0__DOT__rx_state;
        CData/*2:0*/ TopLayer__DOT__uart0__DOT__rx_bit;
        CData/*7:0*/ TopLayer__DOT__uart0__DOT__rx_shift;
        CData/*0:0*/ TopLayer__DOT__uart0__DOT__rx_s1;
        CData/*0:0*/ TopLayer__DOT__uart0__DOT__rx_s2;
        CData/*0:0*/ TopLayer__DOT__uart0__DOT__rx_push;
        CData/*0:0*/ TopLayer__DOT__uart0__DOT__tx_idle_empty;
        CData/*2:0*/ TopLayer__DOT__uart1__DOT__ier;
        CData/*2:0*/ TopLayer__DOT__uart1__DOT__tx_wr;
        CData/*2:0*/ TopLayer__DOT__uart1__DOT__tx_rd;
    };
    struct {
        CData/*3:0*/ TopLayer__DOT__uart1__DOT__tx_cnt;
        CData/*0:0*/ TopLayer__DOT__uart1__DOT__tx_full;
        CData/*2:0*/ TopLayer__DOT__uart1__DOT__rx_wr;
        CData/*2:0*/ TopLayer__DOT__uart1__DOT__rx_rd;
        CData/*3:0*/ TopLayer__DOT__uart1__DOT__rx_cnt;
        CData/*0:0*/ TopLayer__DOT__uart1__DOT__rx_empty;
        CData/*1:0*/ TopLayer__DOT__uart1__DOT__tx_state;
        CData/*2:0*/ TopLayer__DOT__uart1__DOT__tx_bit;
        CData/*7:0*/ TopLayer__DOT__uart1__DOT__tx_shift;
        CData/*0:0*/ TopLayer__DOT__uart1__DOT__tx_line;
        CData/*0:0*/ TopLayer__DOT__uart1__DOT__tx_pop;
        CData/*1:0*/ TopLayer__DOT__uart1__DOT__rx_state;
        CData/*2:0*/ TopLayer__DOT__uart1__DOT__rx_bit;
        CData/*7:0*/ TopLayer__DOT__uart1__DOT__rx_shift;
        CData/*0:0*/ TopLayer__DOT__uart1__DOT__rx_s1;
        CData/*0:0*/ TopLayer__DOT__uart1__DOT__rx_s2;
        CData/*0:0*/ TopLayer__DOT__uart1__DOT__rx_push;
        CData/*0:0*/ TopLayer__DOT__uart1__DOT__tx_idle_empty;
        CData/*2:0*/ TopLayer__DOT__uart2__DOT__ier;
        CData/*2:0*/ TopLayer__DOT__uart2__DOT__tx_wr;
        CData/*2:0*/ TopLayer__DOT__uart2__DOT__tx_rd;
        CData/*3:0*/ TopLayer__DOT__uart2__DOT__tx_cnt;
        CData/*0:0*/ TopLayer__DOT__uart2__DOT__tx_full;
        CData/*2:0*/ TopLayer__DOT__uart2__DOT__rx_wr;
        CData/*2:0*/ TopLayer__DOT__uart2__DOT__rx_rd;
        CData/*3:0*/ TopLayer__DOT__uart2__DOT__rx_cnt;
        CData/*0:0*/ TopLayer__DOT__uart2__DOT__rx_empty;
        CData/*1:0*/ TopLayer__DOT__uart2__DOT__tx_state;
        CData/*2:0*/ TopLayer__DOT__uart2__DOT__tx_bit;
        CData/*7:0*/ TopLayer__DOT__uart2__DOT__tx_shift;
        CData/*0:0*/ TopLayer__DOT__uart2__DOT__tx_line;
        CData/*0:0*/ TopLayer__DOT__uart2__DOT__tx_pop;
        CData/*1:0*/ TopLayer__DOT__uart2__DOT__rx_state;
        CData/*2:0*/ TopLayer__DOT__uart2__DOT__rx_bit;
        CData/*7:0*/ TopLayer__DOT__uart2__DOT__rx_shift;
        CData/*0:0*/ TopLayer__DOT__uart2__DOT__rx_s1;
        CData/*0:0*/ TopLayer__DOT__uart2__DOT__rx_s2;
        CData/*0:0*/ TopLayer__DOT__uart2__DOT__rx_push;
        CData/*0:0*/ TopLayer__DOT__uart2__DOT__tx_idle_empty;
        CData/*2:0*/ TopLayer__DOT__uart3__DOT__ier;
        CData/*2:0*/ TopLayer__DOT__uart3__DOT__tx_wr;
        CData/*2:0*/ TopLayer__DOT__uart3__DOT__tx_rd;
        CData/*3:0*/ TopLayer__DOT__uart3__DOT__tx_cnt;
        CData/*0:0*/ TopLayer__DOT__uart3__DOT__tx_full;
        CData/*2:0*/ TopLayer__DOT__uart3__DOT__rx_wr;
        CData/*2:0*/ TopLayer__DOT__uart3__DOT__rx_rd;
        CData/*3:0*/ TopLayer__DOT__uart3__DOT__rx_cnt;
        CData/*0:0*/ TopLayer__DOT__uart3__DOT__rx_empty;
        CData/*1:0*/ TopLayer__DOT__uart3__DOT__tx_state;
        CData/*2:0*/ TopLayer__DOT__uart3__DOT__tx_bit;
        CData/*7:0*/ TopLayer__DOT__uart3__DOT__tx_shift;
        CData/*0:0*/ TopLayer__DOT__uart3__DOT__tx_line;
        CData/*0:0*/ TopLayer__DOT__uart3__DOT__tx_pop;
        CData/*1:0*/ TopLayer__DOT__uart3__DOT__rx_state;
        CData/*2:0*/ TopLayer__DOT__uart3__DOT__rx_bit;
        CData/*7:0*/ TopLayer__DOT__uart3__DOT__rx_shift;
        CData/*0:0*/ TopLayer__DOT__uart3__DOT__rx_s1;
        CData/*0:0*/ TopLayer__DOT__uart3__DOT__rx_s2;
        CData/*0:0*/ TopLayer__DOT__uart3__DOT__rx_push;
        CData/*0:0*/ TopLayer__DOT__uart3__DOT__tx_idle_empty;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    };
    struct {
        CData/*0:0*/ __VactContinue;
        SData/*11:0*/ TopLayer__DOT__cpu__DOT__csr_addr;
        SData/*11:0*/ TopLayer__DOT__cpu__DOT__toWB_csr_addr_Reg;
        SData/*15:0*/ TopLayer__DOT__uart0__DOT__tx_baud;
        SData/*15:0*/ TopLayer__DOT__uart0__DOT__rx_baud;
        SData/*15:0*/ TopLayer__DOT__uart1__DOT__tx_baud;
        SData/*15:0*/ TopLayer__DOT__uart1__DOT__rx_baud;
        SData/*15:0*/ TopLayer__DOT__uart2__DOT__tx_baud;
        SData/*15:0*/ TopLayer__DOT__uart2__DOT__rx_baud;
        SData/*15:0*/ TopLayer__DOT__uart3__DOT__tx_baud;
        SData/*15:0*/ TopLayer__DOT__uart3__DOT__rx_baud;
        VL_IN(gpio_in,31,0);
        VL_OUT(gpio_out,31,0);
        IData/*31:0*/ TopLayer__DOT__mem_data_out;
        IData/*31:0*/ TopLayer__DOT__mem_instruction;
        IData/*31:0*/ TopLayer__DOT__bram_data_out;
        IData/*31:0*/ TopLayer__DOT__mmio_read_data;
        IData/*31:0*/ TopLayer__DOT__mmio_read_data_q;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__mstatus;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__mie;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__mip;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__mtvec;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__mepc;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__mcause;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__mtval;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__mscratch;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__PC;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__PC_decode;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__next_PC;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__BRAMInstruction;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__imm_i;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__rs1_data_fwd;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__BRAM_read_addr;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__BRAM_write_addr;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__BRAM_data_in;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__EX_result;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__EX_csr_result;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__toWB_Result_Reg;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__toWB_csr_data_Reg;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__WB_rd_data;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__trap_cause;
        IData/*31:0*/ TopLayer__DOT__cpu__DOT__trap_tval;
        IData/*31:0*/ TopLayer__DOT__gpio_bank__DOT__data_out;
        IData/*31:0*/ TopLayer__DOT__gpio_bank__DOT__dir;
        IData/*31:0*/ TopLayer__DOT__gpio_bank__DOT__int_enable;
        IData/*31:0*/ TopLayer__DOT__gpio_bank__DOT__int_rise_en;
        IData/*31:0*/ TopLayer__DOT__gpio_bank__DOT__int_fall_en;
        IData/*31:0*/ TopLayer__DOT__gpio_bank__DOT__int_pending;
        IData/*31:0*/ TopLayer__DOT__gpio_bank__DOT__sync0;
        IData/*31:0*/ TopLayer__DOT__gpio_bank__DOT__sync1;
        IData/*31:0*/ TopLayer__DOT__gpio_bank__DOT__sync1_d;
        IData/*31:0*/ TopLayer__DOT__gpio_bank__DOT__write_mask;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ TopLayer__DOT__mtime;
        QData/*63:0*/ TopLayer__DOT__mtimecmp;
        QData/*63:0*/ TopLayer__DOT__cpu__DOT__cycle;
        QData/*63:0*/ TopLayer__DOT__cpu__DOT__instret;
        VlUnpacked<IData/*31:0*/, 33> TopLayer__DOT__boot_preload__DOT__boot_words;
        VlUnpacked<IData/*31:0*/, 32> TopLayer__DOT__cpu__DOT__registry__DOT__registers;
        VlUnpacked<CData/*7:0*/, 65536> TopLayer__DOT__bram__DOT__Mem;
        VlUnpacked<CData/*7:0*/, 8> TopLayer__DOT__uart0__DOT__txbuf;
        VlUnpacked<CData/*7:0*/, 8> TopLayer__DOT__uart0__DOT__rxbuf;
        VlUnpacked<CData/*7:0*/, 8> TopLayer__DOT__uart1__DOT__txbuf;
        VlUnpacked<CData/*7:0*/, 8> TopLayer__DOT__uart1__DOT__rxbuf;
    };
    struct {
        VlUnpacked<CData/*7:0*/, 8> TopLayer__DOT__uart2__DOT__txbuf;
        VlUnpacked<CData/*7:0*/, 8> TopLayer__DOT__uart2__DOT__rxbuf;
        VlUnpacked<CData/*7:0*/, 8> TopLayer__DOT__uart3__DOT__txbuf;
        VlUnpacked<CData/*7:0*/, 8> TopLayer__DOT__uart3__DOT__rxbuf;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    VTopLayer__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTopLayer___024root(VTopLayer__Syms* symsp, const char* v__name);
    ~VTopLayer___024root();
    VL_UNCOPYABLE(VTopLayer___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
