// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTopLayer.h for the primary calling header

#include "VTopLayer__pch.h"
#include "VTopLayer___024root.h"

VL_ATTR_COLD void VTopLayer___024root___eval_static(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VTopLayer___024root___eval_initial(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
}

VL_ATTR_COLD void VTopLayer___024root___eval_final(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTopLayer___024root___dump_triggers__stl(VTopLayer___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VTopLayer___024root___eval_phase__stl(VTopLayer___024root* vlSelf);

VL_ATTR_COLD void VTopLayer___024root___eval_settle(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VTopLayer___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("TopLayer.v", 20, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VTopLayer___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTopLayer___024root___dump_triggers__stl(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___dump_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTopLayer___024root___stl_sequent__TOP__0(VTopLayer___024root* vlSelf);

VL_ATTR_COLD void VTopLayer___024root___eval_stl(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VTopLayer___024root___stl_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*0:0*/, 512> VTopLayer__ConstPool__TABLE_hf586ed68_0;

VL_ATTR_COLD void VTopLayer___024root___stl_sequent__TOP__0(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___stl_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ TopLayer__DOT__mmio_read_en;
    TopLayer__DOT__mmio_read_en = 0;
    CData/*4:0*/ TopLayer__DOT__cpu__DOT__rs1_addr;
    TopLayer__DOT__cpu__DOT__rs1_addr = 0;
    CData/*4:0*/ TopLayer__DOT__cpu__DOT__rs2_addr;
    TopLayer__DOT__cpu__DOT__rs2_addr = 0;
    IData/*31:0*/ TopLayer__DOT__cpu__DOT__imm_u;
    TopLayer__DOT__cpu__DOT__imm_u = 0;
    IData/*31:0*/ TopLayer__DOT__cpu__DOT__wb_forward_data;
    TopLayer__DOT__cpu__DOT__wb_forward_data = 0;
    IData/*31:0*/ TopLayer__DOT__cpu__DOT__rs2_data_fwd;
    TopLayer__DOT__cpu__DOT__rs2_data_fwd = 0;
    IData/*31:0*/ TopLayer__DOT__cpu__DOT__csr_read_value;
    TopLayer__DOT__cpu__DOT__csr_read_value = 0;
    CData/*3:0*/ TopLayer__DOT__cpu__DOT__alu_control;
    TopLayer__DOT__cpu__DOT__alu_control = 0;
    IData/*31:0*/ TopLayer__DOT__cpu__DOT__operand_a;
    TopLayer__DOT__cpu__DOT__operand_a = 0;
    IData/*31:0*/ TopLayer__DOT__cpu__DOT__operand_b;
    TopLayer__DOT__cpu__DOT__operand_b = 0;
    IData/*31:0*/ TopLayer__DOT__cpu__DOT__alu_result;
    TopLayer__DOT__cpu__DOT__alu_result = 0;
    CData/*2:0*/ TopLayer__DOT__cpu__DOT__BRAM_store_mode;
    TopLayer__DOT__cpu__DOT__BRAM_store_mode = 0;
    CData/*0:0*/ TopLayer__DOT__cpu__DOT__ecall_instr;
    TopLayer__DOT__cpu__DOT__ecall_instr = 0;
    CData/*0:0*/ TopLayer__DOT__cpu__DOT__ebreak_instr;
    TopLayer__DOT__cpu__DOT__ebreak_instr = 0;
    CData/*0:0*/ TopLayer__DOT__cpu__DOT__illegal_instr;
    TopLayer__DOT__cpu__DOT__illegal_instr = 0;
    CData/*0:0*/ TopLayer__DOT__cpu__DOT__mret_instr;
    TopLayer__DOT__cpu__DOT__mret_instr = 0;
    CData/*3:0*/ TopLayer__DOT__cpu__DOT____VdfgExtracted_h7dc3c957__0;
    TopLayer__DOT__cpu__DOT____VdfgExtracted_h7dc3c957__0 = 0;
    IData/*31:0*/ TopLayer__DOT__cpu__DOT____VdfgExtracted_h85b063e6__0;
    TopLayer__DOT__cpu__DOT____VdfgExtracted_h85b063e6__0 = 0;
    IData/*31:0*/ __Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__Vfuncout;
    __Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__Vfuncout = 0;
    SData/*11:0*/ __Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr;
    __Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr = 0;
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.TopLayer__DOT__cpu__DOT__WB_write_enable 
        = ((0U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg)) 
           || ((1U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg)) 
               || (2U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg))));
    vlSelfRef.TopLayer__DOT__uart0__DOT__tx_full = 
        (8U == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_cnt));
    vlSelfRef.TopLayer__DOT__uart0__DOT__rx_empty = 
        (0U == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_cnt));
    vlSelfRef.TopLayer__DOT__uart1__DOT__tx_full = 
        (8U == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_cnt));
    vlSelfRef.TopLayer__DOT__uart1__DOT__rx_empty = 
        (0U == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_cnt));
    vlSelfRef.TopLayer__DOT__uart2__DOT__tx_full = 
        (8U == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_cnt));
    vlSelfRef.TopLayer__DOT__uart2__DOT__rx_empty = 
        (0U == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_cnt));
    vlSelfRef.TopLayer__DOT__uart3__DOT__tx_full = 
        (8U == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_cnt));
    vlSelfRef.TopLayer__DOT__uart3__DOT__rx_empty = 
        (0U == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_cnt));
    vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_addr = 0U;
    vlSelfRef.TopLayer__DOT__uart0__DOT__tx_pop = (
                                                   (0U 
                                                    != (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_cnt)) 
                                                   & (0U 
                                                      == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_state)));
    vlSelfRef.TopLayer__DOT__uart1__DOT__tx_pop = (
                                                   (0U 
                                                    != (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_cnt)) 
                                                   & (0U 
                                                      == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_state)));
    vlSelfRef.TopLayer__DOT__uart2__DOT__tx_pop = (
                                                   (0U 
                                                    != (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_cnt)) 
                                                   & (0U 
                                                      == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_state)));
    vlSelfRef.TopLayer__DOT__uart3__DOT__tx_pop = (
                                                   (0U 
                                                    != (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_cnt)) 
                                                   & (0U 
                                                      == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_state)));
    vlSelfRef.TopLayer__DOT__uart0__DOT__rx_push = 
        ((3U == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_state)) 
         & ((8U != (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_cnt)) 
            & (0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_baud))));
    vlSelfRef.TopLayer__DOT__uart1__DOT__rx_push = 
        ((3U == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_state)) 
         & ((8U != (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_cnt)) 
            & (0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_baud))));
    vlSelfRef.TopLayer__DOT__uart2__DOT__rx_push = 
        ((3U == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_state)) 
         & ((8U != (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_cnt)) 
            & (0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_baud))));
    vlSelfRef.TopLayer__DOT__uart3__DOT__rx_push = 
        ((3U == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_state)) 
         & ((8U != (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_cnt)) 
            & (0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_baud))));
    vlSelfRef.uart_tx = ((((IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_line) 
                           << 3U) | ((IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_line) 
                                     << 2U)) | (((IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_line) 
                                                 << 1U) 
                                                | (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_line)));
    TopLayer__DOT__cpu__DOT__imm_u = (((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__flush_d)
                                        ? 0U : (vlSelfRef.TopLayer__DOT__mem_instruction 
                                                >> 0xcU)) 
                                      << 0xcU);
    vlSelfRef.gpio_out = (((((((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__31__KET____DOT__gpio_pin__DOT__out_latch) 
                               << 0x1fU) | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__30__KET____DOT__gpio_pin__DOT__out_latch) 
                                            << 0x1eU)) 
                             | (((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__29__KET____DOT__gpio_pin__DOT__out_latch) 
                                 << 0x1dU) | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__28__KET____DOT__gpio_pin__DOT__out_latch) 
                                              << 0x1cU))) 
                            | ((((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__27__KET____DOT__gpio_pin__DOT__out_latch) 
                                 << 0x1bU) | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__26__KET____DOT__gpio_pin__DOT__out_latch) 
                                              << 0x1aU)) 
                               | (((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__25__KET____DOT__gpio_pin__DOT__out_latch) 
                                   << 0x19U) | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__24__KET____DOT__gpio_pin__DOT__out_latch) 
                                                << 0x18U)))) 
                           | (((((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__23__KET____DOT__gpio_pin__DOT__out_latch) 
                                 << 0x17U) | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__22__KET____DOT__gpio_pin__DOT__out_latch) 
                                              << 0x16U)) 
                               | (((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__21__KET____DOT__gpio_pin__DOT__out_latch) 
                                   << 0x15U) | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__20__KET____DOT__gpio_pin__DOT__out_latch) 
                                                << 0x14U))) 
                              | ((((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__19__KET____DOT__gpio_pin__DOT__out_latch) 
                                   << 0x13U) | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__18__KET____DOT__gpio_pin__DOT__out_latch) 
                                                << 0x12U)) 
                                 | (((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__17__KET____DOT__gpio_pin__DOT__out_latch) 
                                     << 0x11U) | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__16__KET____DOT__gpio_pin__DOT__out_latch) 
                                                  << 0x10U))))) 
                          | ((((((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__15__KET____DOT__gpio_pin__DOT__out_latch) 
                                 << 0xfU) | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__14__KET____DOT__gpio_pin__DOT__out_latch) 
                                             << 0xeU)) 
                               | (((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__13__KET____DOT__gpio_pin__DOT__out_latch) 
                                   << 0xdU) | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__12__KET____DOT__gpio_pin__DOT__out_latch) 
                                               << 0xcU))) 
                              | ((((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__11__KET____DOT__gpio_pin__DOT__out_latch) 
                                   << 0xbU) | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__10__KET____DOT__gpio_pin__DOT__out_latch) 
                                               << 0xaU)) 
                                 | (((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__9__KET____DOT__gpio_pin__DOT__out_latch) 
                                     << 9U) | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__8__KET____DOT__gpio_pin__DOT__out_latch) 
                                               << 8U)))) 
                             | (((((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__7__KET____DOT__gpio_pin__DOT__out_latch) 
                                   << 7U) | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__6__KET____DOT__gpio_pin__DOT__out_latch) 
                                             << 6U)) 
                                 | (((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__5__KET____DOT__gpio_pin__DOT__out_latch) 
                                     << 5U) | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__4__KET____DOT__gpio_pin__DOT__out_latch) 
                                               << 4U))) 
                                | ((((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__3__KET____DOT__gpio_pin__DOT__out_latch) 
                                     << 3U) | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__2__KET____DOT__gpio_pin__DOT__out_latch) 
                                               << 2U)) 
                                   | (((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__1__KET____DOT__gpio_pin__DOT__out_latch) 
                                       << 1U) | (IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__0__KET____DOT__gpio_pin__DOT__out_latch))))));
    if (vlSelfRef.TopLayer__DOT__cpu__DOT__flush_d) {
        vlSelfRef.TopLayer__DOT__cpu__DOT__BRAMInstruction = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__rd_addr = 0U;
        TopLayer__DOT__cpu__DOT__rs2_addr = 0U;
        TopLayer__DOT__cpu__DOT__rs1_addr = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__csr_addr = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__funct3 = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__opcode = 0U;
    } else {
        vlSelfRef.TopLayer__DOT__cpu__DOT__BRAMInstruction 
            = vlSelfRef.TopLayer__DOT__mem_instruction;
        vlSelfRef.TopLayer__DOT__cpu__DOT__rd_addr 
            = (0x1fU & (vlSelfRef.TopLayer__DOT__mem_instruction 
                        >> 7U));
        TopLayer__DOT__cpu__DOT__rs2_addr = (0x1fU 
                                             & (vlSelfRef.TopLayer__DOT__mem_instruction 
                                                >> 0x14U));
        TopLayer__DOT__cpu__DOT__rs1_addr = (0x1fU 
                                             & (vlSelfRef.TopLayer__DOT__mem_instruction 
                                                >> 0xfU));
        vlSelfRef.TopLayer__DOT__cpu__DOT__csr_addr 
            = (vlSelfRef.TopLayer__DOT__mem_instruction 
               >> 0x14U);
        vlSelfRef.TopLayer__DOT__cpu__DOT__funct3 = 
            (7U & (vlSelfRef.TopLayer__DOT__mem_instruction 
                   >> 0xcU));
        vlSelfRef.TopLayer__DOT__cpu__DOT__opcode = 
            (0x7fU & vlSelfRef.TopLayer__DOT__mem_instruction);
    }
    vlSelfRef.TopLayer__DOT__cpu__DOT__irq_ext = (1U 
                                                  & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mstatus 
                                                      >> 3U) 
                                                     & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mie 
                                                         >> 0xbU) 
                                                        & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mip 
                                                            >> 0xbU) 
                                                           | (IData)(vlSelfRef.irq_external)))));
    vlSelfRef.TopLayer__DOT__cpu__DOT__irq_soft = (1U 
                                                   & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mstatus 
                                                       >> 3U) 
                                                      & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mie 
                                                          >> 3U) 
                                                         & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mip 
                                                             >> 3U) 
                                                            | (IData)(vlSelfRef.TopLayer__DOT__msip)))));
    vlSelfRef.TopLayer__DOT__cpu__DOT____VdfgRegularize_h0c4dd555_2_3 
        = ((~ (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__flush_d)) 
           & (vlSelfRef.TopLayer__DOT__mem_instruction 
              >> 0x1fU));
    vlSelfRef.TopLayer__DOT__cpu__DOT__wb_write_gpr 
        = ((3U != (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg)) 
           & (0U != (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_rd_addr_Reg)));
    vlSelfRef.TopLayer__DOT__mem_data_out = ((IData)(vlSelfRef.TopLayer__DOT__read_was_mmio)
                                              ? vlSelfRef.TopLayer__DOT__mmio_read_data_q
                                              : vlSelfRef.TopLayer__DOT__bram_data_out);
    vlSelfRef.TopLayer__DOT__cpu__DOT__irq_ready = 
        (1U & ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__irq_ext) 
               | ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__irq_soft) 
                  | ((vlSelfRef.TopLayer__DOT__cpu__DOT__mstatus 
                      >> 3U) & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mie 
                                 >> 7U) & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mip 
                                            >> 7U) 
                                           | (vlSelfRef.TopLayer__DOT__mtime 
                                              >= vlSelfRef.TopLayer__DOT__mtimecmp)))))));
    __Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr 
        = vlSelfRef.TopLayer__DOT__cpu__DOT__csr_addr;
    __Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__Vfuncout 
        = (((((((((0x300U == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr)) 
                  | (0x301U == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))) 
                 | (0x304U == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))) 
                | (0x305U == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))) 
               | (0x340U == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))) 
              | (0x341U == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))) 
             | (0x342U == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))) 
            | (0x343U == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr)))
            ? ((0x300U == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))
                ? vlSelfRef.TopLayer__DOT__cpu__DOT__mstatus
                : ((0x301U == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))
                    ? 0x40000100U : ((0x304U == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))
                                      ? vlSelfRef.TopLayer__DOT__cpu__DOT__mie
                                      : ((0x305U == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))
                                          ? vlSelfRef.TopLayer__DOT__cpu__DOT__mtvec
                                          : ((0x340U 
                                              == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))
                                              ? vlSelfRef.TopLayer__DOT__cpu__DOT__mscratch
                                              : ((0x341U 
                                                  == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))
                                                  ? vlSelfRef.TopLayer__DOT__cpu__DOT__mepc
                                                  : 
                                                 ((0x342U 
                                                   == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))
                                                   ? vlSelfRef.TopLayer__DOT__cpu__DOT__mcause
                                                   : vlSelfRef.TopLayer__DOT__cpu__DOT__mtval)))))))
            : ((0x344U == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))
                ? vlSelfRef.TopLayer__DOT__cpu__DOT__mip
                : ((0xc00U == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))
                    ? (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__cycle)
                    : ((0xc02U == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))
                        ? (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__instret)
                        : ((0xc80U == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))
                            ? (IData)((vlSelfRef.TopLayer__DOT__cpu__DOT__cycle 
                                       >> 0x20U)) : 
                           ((0xc82U == (IData)(__Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__addr))
                             ? (IData)((vlSelfRef.TopLayer__DOT__cpu__DOT__instret 
                                        >> 0x20U)) : 0U))))));
    TopLayer__DOT__cpu__DOT____VdfgExtracted_h85b063e6__0 
        = __Vfunc_TopLayer__DOT__cpu__DOT__GetCSR__1__Vfuncout;
    vlSelfRef.TopLayer__DOT__cpu__DOT__imm_i = (((- (IData)((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT____VdfgRegularize_h0c4dd555_2_3))) 
                                                 << 0xcU) 
                                                | (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__csr_addr));
    TopLayer__DOT__cpu__DOT____VdfgExtracted_h7dc3c957__0 
        = ((8U & (((~ (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__flush_d)) 
                   << 3U) & (vlSelfRef.TopLayer__DOT__mem_instruction 
                             >> 0x1bU))) | (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__funct3));
    vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_data = 0U;
    if ((0U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg))) {
        vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_addr 
            = vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_rd_addr_Reg;
        vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_data 
            = vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_Result_Reg;
    } else if ((1U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg))) {
        vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_addr 
            = vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_rd_addr_Reg;
        vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_data 
            = vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_Result_Reg;
    } else if ((2U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg))) {
        vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_addr 
            = vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_rd_addr_Reg;
        vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_data 
            = vlSelfRef.TopLayer__DOT__mem_data_out;
    }
    TopLayer__DOT__cpu__DOT__wb_forward_data = ((2U 
                                                 == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg))
                                                 ? vlSelfRef.TopLayer__DOT__mem_data_out
                                                 : vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_Result_Reg);
    TopLayer__DOT__cpu__DOT__alu_control = 0U;
    TopLayer__DOT__cpu__DOT__rs2_data_fwd = (((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__wb_write_gpr) 
                                              & (((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_rd_addr_Reg) 
                                                  == (IData)(TopLayer__DOT__cpu__DOT__rs2_addr)) 
                                                 & (0U 
                                                    != (IData)(TopLayer__DOT__cpu__DOT__rs2_addr))))
                                              ? TopLayer__DOT__cpu__DOT__wb_forward_data
                                              : vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers
                                             [TopLayer__DOT__cpu__DOT__rs2_addr]);
    vlSelfRef.TopLayer__DOT__cpu__DOT__rs1_data_fwd 
        = (((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__wb_write_gpr) 
            & (((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_rd_addr_Reg) 
                == (IData)(TopLayer__DOT__cpu__DOT__rs1_addr)) 
               & (0U != (IData)(TopLayer__DOT__cpu__DOT__rs1_addr))))
            ? TopLayer__DOT__cpu__DOT__wb_forward_data
            : vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers
           [TopLayer__DOT__cpu__DOT__rs1_addr]);
    vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in = 0U;
    TopLayer__DOT__cpu__DOT__operand_b = 0U;
    __Vtableidx1 = (((((vlSelfRef.TopLayer__DOT__cpu__DOT__rs1_data_fwd 
                        == TopLayer__DOT__cpu__DOT__rs2_data_fwd) 
                       << 8U) | (((vlSelfRef.TopLayer__DOT__cpu__DOT__rs1_data_fwd 
                                   != TopLayer__DOT__cpu__DOT__rs2_data_fwd) 
                                  << 7U) | (VL_LTS_III(32, vlSelfRef.TopLayer__DOT__cpu__DOT__rs1_data_fwd, TopLayer__DOT__cpu__DOT__rs2_data_fwd) 
                                            << 6U))) 
                     | ((VL_GTES_III(32, vlSelfRef.TopLayer__DOT__cpu__DOT__rs1_data_fwd, TopLayer__DOT__cpu__DOT__rs2_data_fwd) 
                         << 5U) | ((vlSelfRef.TopLayer__DOT__cpu__DOT__rs1_data_fwd 
                                    < TopLayer__DOT__cpu__DOT__rs2_data_fwd) 
                                   << 4U))) | (((vlSelfRef.TopLayer__DOT__cpu__DOT__rs1_data_fwd 
                                                 >= TopLayer__DOT__cpu__DOT__rs2_data_fwd) 
                                                << 3U) 
                                               | (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__funct3)));
    vlSelfRef.TopLayer__DOT__cpu__DOT__branch_taken 
        = VTopLayer__ConstPool__TABLE_hf586ed68_0[__Vtableidx1];
    TopLayer__DOT__cpu__DOT__operand_a = 0U;
    vlSelfRef.TopLayer__DOT__cpu__DOT__next_PC = ((IData)(4U) 
                                                  + vlSelfRef.TopLayer__DOT__cpu__DOT__PC);
    vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
    vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_load_mode = 7U;
    TopLayer__DOT__cpu__DOT__BRAM_store_mode = 7U;
    TopLayer__DOT__cpu__DOT__ecall_instr = 0U;
    TopLayer__DOT__cpu__DOT__ebreak_instr = 0U;
    TopLayer__DOT__cpu__DOT__illegal_instr = 0U;
    TopLayer__DOT__cpu__DOT__mret_instr = 0U;
    if ((0x40U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
        if ((0x20U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
            if ((0x10U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                if ((8U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                    TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
                } else if ((4U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                    TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
                } else if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                        if ((0U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__funct3))) {
                            vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                            if ((0U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__csr_addr))) {
                                TopLayer__DOT__cpu__DOT__ecall_instr = 1U;
                            } else if ((1U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__csr_addr))) {
                                TopLayer__DOT__cpu__DOT__ebreak_instr = 1U;
                            } else if ((0x302U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__csr_addr))) {
                                TopLayer__DOT__cpu__DOT__mret_instr = 1U;
                            }
                        } else {
                            vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 1U;
                        }
                    } else {
                        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                        TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
                    }
                } else {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                    TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
                }
            } else if ((8U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                if ((4U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                            vlSelfRef.TopLayer__DOT__cpu__DOT__next_PC 
                                = (vlSelfRef.TopLayer__DOT__cpu__DOT__PC_decode 
                                   + (((- (IData)((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT____VdfgRegularize_h0c4dd555_2_3))) 
                                       << 0x14U) | 
                                      (((((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__flush_d)
                                           ? 0U : (0xffU 
                                                   & (vlSelfRef.TopLayer__DOT__mem_instruction 
                                                      >> 0xcU))) 
                                         << 0xcU) | 
                                        (0x800U & (
                                                   ((~ (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__flush_d)) 
                                                    << 0xbU) 
                                                   & (vlSelfRef.TopLayer__DOT__mem_instruction 
                                                      >> 9U)))) 
                                       | (((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__flush_d)
                                            ? 0U : 
                                           (0x3ffU 
                                            & (vlSelfRef.TopLayer__DOT__mem_instruction 
                                               >> 0x15U))) 
                                          << 1U))));
                            vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 0U;
                        } else {
                            vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                            TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
                        }
                    } else {
                        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                        TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
                    }
                } else {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                    TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
                }
            } else if ((4U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                        vlSelfRef.TopLayer__DOT__cpu__DOT__next_PC 
                            = (0xfffffffeU & (vlSelfRef.TopLayer__DOT__cpu__DOT__rs1_data_fwd 
                                              + vlSelfRef.TopLayer__DOT__cpu__DOT__imm_i));
                        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 0U;
                    } else {
                        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                        TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
                    }
                } else {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                    TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
                }
            } else if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                    if (vlSelfRef.TopLayer__DOT__cpu__DOT__branch_taken) {
                        vlSelfRef.TopLayer__DOT__cpu__DOT__next_PC 
                            = (vlSelfRef.TopLayer__DOT__cpu__DOT__PC_decode 
                               + (((- (IData)((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT____VdfgRegularize_h0c4dd555_2_3))) 
                                   << 0xdU) | ((((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT____VdfgRegularize_h0c4dd555_2_3) 
                                                 << 0xcU) 
                                                | (0x800U 
                                                   & (((~ (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__flush_d)) 
                                                       << 0xbU) 
                                                      & (vlSelfRef.TopLayer__DOT__mem_instruction 
                                                         << 4U)))) 
                                               | ((((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__flush_d)
                                                     ? 0U
                                                     : 
                                                    (0x3fU 
                                                     & (vlSelfRef.TopLayer__DOT__mem_instruction 
                                                        >> 0x19U))) 
                                                   << 5U) 
                                                  | (((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__flush_d)
                                                       ? 0U
                                                       : 
                                                      (0xfU 
                                                       & (vlSelfRef.TopLayer__DOT__mem_instruction 
                                                          >> 8U))) 
                                                     << 1U)))));
                    }
                    vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                } else {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                    TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
                }
            } else {
                vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
            }
        } else {
            vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
            TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
        }
    } else if ((0x20U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
        if ((0x10U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
            if ((8U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
            } else if ((4U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 0U;
                    } else {
                        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                        TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
                    }
                } else {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                    TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
                }
            } else if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 0U;
                } else {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                    TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
                }
            } else {
                vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
            }
        } else if ((8U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
            vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
            TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
        } else if ((4U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
            vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
            TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
        } else if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
            if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                TopLayer__DOT__cpu__DOT__BRAM_store_mode 
                    = vlSelfRef.TopLayer__DOT__cpu__DOT__funct3;
                vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
            } else {
                vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
            }
        } else {
            vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
            TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
        }
    } else if ((0x10U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
        if ((8U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
            vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
            TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
        } else if ((4U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
            if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 0U;
                } else {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                    TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
                }
            } else {
                vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
            }
        } else if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
            if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 0U;
            } else {
                vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
            }
        } else {
            vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
            TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
        }
    } else if ((8U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
        if ((4U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
            if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                } else {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                    TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
                }
            } else {
                vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
                TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
            }
        } else {
            vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
            TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
        }
    } else if ((4U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
        TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
    } else if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
        if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
            vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_load_mode 
                = vlSelfRef.TopLayer__DOT__cpu__DOT__funct3;
            vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 2U;
        } else {
            vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
            TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
        }
    } else {
        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
        TopLayer__DOT__cpu__DOT__illegal_instr = 1U;
    }
    vlSelfRef.TopLayer__DOT__cpu__DOT__take_trap = 
        ((0U != vlSelfRef.TopLayer__DOT__cpu__DOT__BRAMInstruction) 
         & ((((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__irq_ready) 
              | (IData)(TopLayer__DOT__cpu__DOT__ecall_instr)) 
             | (IData)(TopLayer__DOT__cpu__DOT__ebreak_instr)) 
            | (IData)(TopLayer__DOT__cpu__DOT__illegal_instr)));
    vlSelfRef.TopLayer__DOT__cpu__DOT__take_mret = 
        ((0U != vlSelfRef.TopLayer__DOT__cpu__DOT__BRAMInstruction) 
         & (IData)(TopLayer__DOT__cpu__DOT__mret_instr));
    if (vlSelfRef.TopLayer__DOT__cpu__DOT__take_trap) {
        vlSelfRef.TopLayer__DOT__cpu__DOT__next_PC 
            = (0xfffffffcU & vlSelfRef.TopLayer__DOT__cpu__DOT__mtvec);
        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_load_mode = 7U;
        TopLayer__DOT__cpu__DOT__BRAM_store_mode = 7U;
    } else if (vlSelfRef.TopLayer__DOT__cpu__DOT__take_mret) {
        vlSelfRef.TopLayer__DOT__cpu__DOT__next_PC 
            = (((1U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg)) 
                & (0x341U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_csr_addr_Reg)))
                ? vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_csr_data_Reg
                : vlSelfRef.TopLayer__DOT__cpu__DOT__mepc);
        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode = 3U;
    }
    if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                  >> 6U)))) {
        if ((0x20U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
            if ((0x10U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                                TopLayer__DOT__cpu__DOT__alu_control 
                                    = TopLayer__DOT__cpu__DOT____VdfgExtracted_h7dc3c957__0;
                                TopLayer__DOT__cpu__DOT__operand_b 
                                    = TopLayer__DOT__cpu__DOT__rs2_data_fwd;
                                TopLayer__DOT__cpu__DOT__operand_a 
                                    = vlSelfRef.TopLayer__DOT__cpu__DOT__rs1_data_fwd;
                            }
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                                 >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                            TopLayer__DOT__cpu__DOT__alu_control = 0U;
                            TopLayer__DOT__cpu__DOT__operand_b 
                                = (((- (IData)((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT____VdfgRegularize_h0c4dd555_2_3))) 
                                    << 0xcU) | ((((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__flush_d)
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.TopLayer__DOT__mem_instruction 
                                                   >> 0x19U)) 
                                                 << 5U) 
                                                | (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__rd_addr)));
                            TopLayer__DOT__cpu__DOT__operand_a 
                                = vlSelfRef.TopLayer__DOT__cpu__DOT__rs1_data_fwd;
                        }
                    }
                }
            }
            if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                                vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in 
                                    = TopLayer__DOT__cpu__DOT__rs2_data_fwd;
                            }
                        }
                    }
                }
            }
        } else if ((0x10U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                            TopLayer__DOT__cpu__DOT__alu_control 
                                = ((5U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__funct3))
                                    ? (IData)(TopLayer__DOT__cpu__DOT____VdfgExtracted_h7dc3c957__0)
                                    : (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__funct3));
                            TopLayer__DOT__cpu__DOT__operand_b 
                                = vlSelfRef.TopLayer__DOT__cpu__DOT__imm_i;
                            TopLayer__DOT__cpu__DOT__operand_a 
                                = vlSelfRef.TopLayer__DOT__cpu__DOT__rs1_data_fwd;
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                             >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                        TopLayer__DOT__cpu__DOT__alu_control = 0U;
                        TopLayer__DOT__cpu__DOT__operand_b 
                            = vlSelfRef.TopLayer__DOT__cpu__DOT__imm_i;
                        TopLayer__DOT__cpu__DOT__operand_a 
                            = vlSelfRef.TopLayer__DOT__cpu__DOT__rs1_data_fwd;
                    }
                }
            }
        }
    }
    TopLayer__DOT__cpu__DOT__alu_result = ((8U & (IData)(TopLayer__DOT__cpu__DOT__alu_control))
                                            ? ((4U 
                                                & (IData)(TopLayer__DOT__cpu__DOT__alu_control))
                                                ? (
                                                   (2U 
                                                    & (IData)(TopLayer__DOT__cpu__DOT__alu_control))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(TopLayer__DOT__cpu__DOT__alu_control))
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, TopLayer__DOT__cpu__DOT__operand_a, 
                                                                   (0x1fU 
                                                                    & TopLayer__DOT__cpu__DOT__operand_b))
                                                     : 0U))
                                                : (
                                                   (2U 
                                                    & (IData)(TopLayer__DOT__cpu__DOT__alu_control))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(TopLayer__DOT__cpu__DOT__alu_control))
                                                     ? 0U
                                                     : 
                                                    (TopLayer__DOT__cpu__DOT__operand_a 
                                                     - TopLayer__DOT__cpu__DOT__operand_b))))
                                            : ((4U 
                                                & (IData)(TopLayer__DOT__cpu__DOT__alu_control))
                                                ? (
                                                   (2U 
                                                    & (IData)(TopLayer__DOT__cpu__DOT__alu_control))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(TopLayer__DOT__cpu__DOT__alu_control))
                                                     ? 
                                                    (TopLayer__DOT__cpu__DOT__operand_a 
                                                     & TopLayer__DOT__cpu__DOT__operand_b)
                                                     : 
                                                    (TopLayer__DOT__cpu__DOT__operand_a 
                                                     | TopLayer__DOT__cpu__DOT__operand_b))
                                                    : 
                                                   ((1U 
                                                     & (IData)(TopLayer__DOT__cpu__DOT__alu_control))
                                                     ? 
                                                    (TopLayer__DOT__cpu__DOT__operand_a 
                                                     >> 
                                                     (0x1fU 
                                                      & TopLayer__DOT__cpu__DOT__operand_b))
                                                     : 
                                                    (TopLayer__DOT__cpu__DOT__operand_a 
                                                     ^ TopLayer__DOT__cpu__DOT__operand_b)))
                                                : (
                                                   (2U 
                                                    & (IData)(TopLayer__DOT__cpu__DOT__alu_control))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(TopLayer__DOT__cpu__DOT__alu_control))
                                                     ? 
                                                    ((TopLayer__DOT__cpu__DOT__operand_a 
                                                      < TopLayer__DOT__cpu__DOT__operand_b)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    (VL_LTS_III(32, TopLayer__DOT__cpu__DOT__operand_a, TopLayer__DOT__cpu__DOT__operand_b)
                                                      ? 1U
                                                      : 0U))
                                                    : 
                                                   ((1U 
                                                     & (IData)(TopLayer__DOT__cpu__DOT__alu_control))
                                                     ? 
                                                    (TopLayer__DOT__cpu__DOT__operand_a 
                                                     << 
                                                     (0x1fU 
                                                      & TopLayer__DOT__cpu__DOT__operand_b))
                                                     : 
                                                    (TopLayer__DOT__cpu__DOT__operand_a 
                                                     + TopLayer__DOT__cpu__DOT__operand_b)))));
    vlSelfRef.TopLayer__DOT__cpu__DOT__trap_cause = 
        ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__irq_ready)
          ? ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__irq_ext)
              ? 0x8000000bU : ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__irq_soft)
                                ? 0x80000003U : 0x80000007U))
          : ((IData)(TopLayer__DOT__cpu__DOT__ecall_instr)
              ? 0xbU : ((IData)(TopLayer__DOT__cpu__DOT__ebreak_instr)
                         ? 3U : 2U)));
    vlSelfRef.TopLayer__DOT__cpu__DOT__trap_tval = 0U;
    if ((1U & (~ (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__irq_ready)))) {
        if ((1U & (~ (IData)(TopLayer__DOT__cpu__DOT__ecall_instr)))) {
            vlSelfRef.TopLayer__DOT__cpu__DOT__trap_tval 
                = ((IData)(TopLayer__DOT__cpu__DOT__ebreak_instr)
                    ? vlSelfRef.TopLayer__DOT__cpu__DOT__PC_decode
                    : vlSelfRef.TopLayer__DOT__cpu__DOT__BRAMInstruction);
        }
    }
    vlSelfRef.TopLayer__DOT__cpu__DOT__EX_result = 0U;
    vlSelfRef.TopLayer__DOT__cpu__DOT__EX_csr_result = 0U;
    TopLayer__DOT__cpu__DOT__csr_read_value = 0U;
    if ((0x40U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
        if ((0x20U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
            if ((0x10U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                                if ((0U != (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__funct3))) {
                                    TopLayer__DOT__cpu__DOT__csr_read_value 
                                        = TopLayer__DOT__cpu__DOT____VdfgExtracted_h85b063e6__0;
                                    if (((1U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg)) 
                                         & ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_csr_addr_Reg) 
                                            == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__csr_addr)))) {
                                        TopLayer__DOT__cpu__DOT__csr_read_value 
                                            = vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_csr_data_Reg;
                                    }
                                    vlSelfRef.TopLayer__DOT__cpu__DOT__EX_result 
                                        = TopLayer__DOT__cpu__DOT__csr_read_value;
                                    vlSelfRef.TopLayer__DOT__cpu__DOT__EX_csr_result 
                                        = ((1U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__funct3))
                                            ? vlSelfRef.TopLayer__DOT__cpu__DOT__rs1_data_fwd
                                            : ((2U 
                                                == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__funct3))
                                                ? (TopLayer__DOT__cpu__DOT__csr_read_value 
                                                   | vlSelfRef.TopLayer__DOT__cpu__DOT__rs1_data_fwd)
                                                : (
                                                   (3U 
                                                    == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__funct3))
                                                    ? 
                                                   (TopLayer__DOT__cpu__DOT__csr_read_value 
                                                    & (~ vlSelfRef.TopLayer__DOT__cpu__DOT__rs1_data_fwd))
                                                    : 
                                                   ((5U 
                                                     == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__funct3))
                                                     ? (IData)(TopLayer__DOT__cpu__DOT__rs1_addr)
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__funct3))
                                                      ? 
                                                     (TopLayer__DOT__cpu__DOT__csr_read_value 
                                                      | (IData)(TopLayer__DOT__cpu__DOT__rs1_addr))
                                                      : 
                                                     ((7U 
                                                       == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__funct3))
                                                       ? 
                                                      (TopLayer__DOT__cpu__DOT__csr_read_value 
                                                       & (~ (IData)(TopLayer__DOT__cpu__DOT__rs1_addr)))
                                                       : TopLayer__DOT__cpu__DOT__csr_read_value))))));
                                }
                            }
                        }
                    }
                }
            } else if ((8U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                if ((4U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                            vlSelfRef.TopLayer__DOT__cpu__DOT__EX_result 
                                = ((IData)(4U) + vlSelfRef.TopLayer__DOT__cpu__DOT__PC_decode);
                        }
                    }
                }
            } else if ((4U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                        vlSelfRef.TopLayer__DOT__cpu__DOT__EX_result 
                            = ((IData)(4U) + vlSelfRef.TopLayer__DOT__cpu__DOT__PC_decode);
                    }
                }
            }
        }
    } else if ((0x20U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
        if ((0x10U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                            vlSelfRef.TopLayer__DOT__cpu__DOT__EX_result 
                                = TopLayer__DOT__cpu__DOT__imm_u;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                        vlSelfRef.TopLayer__DOT__cpu__DOT__EX_result 
                            = TopLayer__DOT__cpu__DOT__alu_result;
                    }
                }
            }
        }
    } else if ((0x10U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
        if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                      >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                        vlSelfRef.TopLayer__DOT__cpu__DOT__EX_result 
                            = (vlSelfRef.TopLayer__DOT__cpu__DOT__PC_decode 
                               + TopLayer__DOT__cpu__DOT__imm_u);
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__EX_result 
                        = TopLayer__DOT__cpu__DOT__alu_result;
                }
            }
        }
    }
    vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr = 0U;
    vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                  >> 6U)))) {
        if ((0x20U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                                vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                                    = TopLayer__DOT__cpu__DOT__alu_result;
                            }
                        }
                    }
                }
            }
        }
        if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                      >> 5U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                                vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                    = TopLayer__DOT__cpu__DOT__alu_result;
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0xffffffU == (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                       >> 8U))) {
        vlSelfRef.TopLayer__DOT__bram_write_mode = 7U;
        vlSelfRef.TopLayer__DOT__mmio_write_en = (7U 
                                                  != (IData)(TopLayer__DOT__cpu__DOT__BRAM_store_mode));
    } else {
        vlSelfRef.TopLayer__DOT__bram_write_mode = TopLayer__DOT__cpu__DOT__BRAM_store_mode;
        vlSelfRef.TopLayer__DOT__mmio_write_en = 0U;
    }
    TopLayer__DOT__mmio_read_en = ((0xffffffU == (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                  >> 8U)) 
                                   & (7U != (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_load_mode)));
    vlSelfRef.TopLayer__DOT__mmio_read_data = ((0x20U 
                                                > (0x3fU 
                                                   & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                      >> 2U)))
                                                ? (1U 
                                                   & ((((((((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__31__KET____DOT__gpio_pin__DOT__in_latch) 
                                                            << 0x1fU) 
                                                           | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__30__KET____DOT__gpio_pin__DOT__in_latch) 
                                                              << 0x1eU)) 
                                                          | (((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__29__KET____DOT__gpio_pin__DOT__in_latch) 
                                                              << 0x1dU) 
                                                             | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__28__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                << 0x1cU))) 
                                                         | ((((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__27__KET____DOT__gpio_pin__DOT__in_latch) 
                                                              << 0x1bU) 
                                                             | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__26__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                << 0x1aU)) 
                                                            | (((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__25__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                << 0x19U) 
                                                               | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__24__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                  << 0x18U)))) 
                                                        | (((((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__23__KET____DOT__gpio_pin__DOT__in_latch) 
                                                              << 0x17U) 
                                                             | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__22__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                << 0x16U)) 
                                                            | (((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__21__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                << 0x15U) 
                                                               | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__20__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                  << 0x14U))) 
                                                           | ((((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__19__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                << 0x13U) 
                                                               | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__18__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                  << 0x12U)) 
                                                              | (((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__17__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                  << 0x11U) 
                                                                 | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__16__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                    << 0x10U))))) 
                                                       | ((((((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__15__KET____DOT__gpio_pin__DOT__in_latch) 
                                                              << 0xfU) 
                                                             | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__14__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                << 0xeU)) 
                                                            | (((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__13__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                << 0xdU) 
                                                               | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__12__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                  << 0xcU))) 
                                                           | ((((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__11__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                << 0xbU) 
                                                               | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__10__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                  << 0xaU)) 
                                                              | (((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__9__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                  << 9U) 
                                                                 | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__8__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                    << 8U)))) 
                                                          | (((((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__7__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                << 7U) 
                                                               | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__6__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                  << 6U)) 
                                                              | (((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__5__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                  << 5U) 
                                                                 | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__4__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                    << 4U))) 
                                                             | ((((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__3__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                  << 3U) 
                                                                 | ((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__2__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                    << 2U)) 
                                                                | (((IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__1__KET____DOT__gpio_pin__DOT__in_latch) 
                                                                    << 1U) 
                                                                   | (IData)(vlSelfRef.TopLayer__DOT__gpio_bank__BRA__0__KET____DOT__gpio_pin__DOT__in_latch)))))) 
                                                      >> 
                                                      (0x1fU 
                                                       & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                          >> 2U))))
                                                : (
                                                   (0x27U 
                                                    >= 
                                                    (0x3fU 
                                                     & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                        >> 2U)))
                                                    ? 
                                                   ((0x10U 
                                                     & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                     ? 
                                                    ((8U 
                                                      & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                      ? 
                                                     ((0x27U 
                                                       == 
                                                       (0x3fU 
                                                        & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                           >> 2U)))
                                                       ? 
                                                      ((((8U 
                                                          == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_cnt)) 
                                                         << 3U) 
                                                        | ((0U 
                                                            != (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_cnt)) 
                                                           << 2U)) 
                                                       | ((((0U 
                                                             == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_cnt)) 
                                                            & (0U 
                                                               == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_state))) 
                                                           << 1U) 
                                                          | (8U 
                                                             != (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_cnt))))
                                                       : 
                                                      vlSelfRef.TopLayer__DOT__uart3__DOT__rxbuf
                                                      [vlSelfRef.TopLayer__DOT__uart3__DOT__rx_rd])
                                                      : 
                                                     ((0x25U 
                                                       == 
                                                       (0x3fU 
                                                        & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                           >> 2U)))
                                                       ? 
                                                      ((((8U 
                                                          == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_cnt)) 
                                                         << 3U) 
                                                        | ((0U 
                                                            != (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_cnt)) 
                                                           << 2U)) 
                                                       | ((((0U 
                                                             == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_cnt)) 
                                                            & (0U 
                                                               == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_state))) 
                                                           << 1U) 
                                                          | (8U 
                                                             != (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_cnt))))
                                                       : 
                                                      vlSelfRef.TopLayer__DOT__uart2__DOT__rxbuf
                                                      [vlSelfRef.TopLayer__DOT__uart2__DOT__rx_rd]))
                                                     : 
                                                    ((8U 
                                                      & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                      ? 
                                                     ((0x23U 
                                                       == 
                                                       (0x3fU 
                                                        & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                           >> 2U)))
                                                       ? 
                                                      ((((8U 
                                                          == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_cnt)) 
                                                         << 3U) 
                                                        | ((0U 
                                                            != (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_cnt)) 
                                                           << 2U)) 
                                                       | ((((0U 
                                                             == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_cnt)) 
                                                            & (0U 
                                                               == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_state))) 
                                                           << 1U) 
                                                          | (8U 
                                                             != (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_cnt))))
                                                       : 
                                                      vlSelfRef.TopLayer__DOT__uart1__DOT__rxbuf
                                                      [vlSelfRef.TopLayer__DOT__uart1__DOT__rx_rd])
                                                      : 
                                                     ((0x21U 
                                                       == 
                                                       (0x3fU 
                                                        & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                           >> 2U)))
                                                       ? 
                                                      ((((8U 
                                                          == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_cnt)) 
                                                         << 3U) 
                                                        | ((0U 
                                                            != (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_cnt)) 
                                                           << 2U)) 
                                                       | ((((0U 
                                                             == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_cnt)) 
                                                            & (0U 
                                                               == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_state))) 
                                                           << 1U) 
                                                          | (8U 
                                                             != (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_cnt))))
                                                       : 
                                                      vlSelfRef.TopLayer__DOT__uart0__DOT__rxbuf
                                                      [vlSelfRef.TopLayer__DOT__uart0__DOT__rx_rd])))
                                                    : 
                                                   ((0x80U 
                                                     & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                     ? 
                                                    ((0x40U 
                                                      & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                      ? 
                                                     ((0x20U 
                                                       & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                       ? 0U
                                                       : 
                                                      ((0x10U 
                                                        & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                        ? 
                                                       ((8U 
                                                         & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                         ? 0U
                                                         : 
                                                        ((4U 
                                                          & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                          ? 0U
                                                          : (IData)(
                                                                    (vlSelfRef.TopLayer__DOT__mtime 
                                                                     >> 0x20U))))
                                                        : 
                                                       ((8U 
                                                         & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                         ? 
                                                        ((4U 
                                                          & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                          ? (IData)(vlSelfRef.TopLayer__DOT__mtime)
                                                          : (IData)(
                                                                    (vlSelfRef.TopLayer__DOT__mtimecmp 
                                                                     >> 0x20U)))
                                                         : 
                                                        ((4U 
                                                          & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                          ? (IData)(vlSelfRef.TopLayer__DOT__mtimecmp)
                                                          : (IData)(vlSelfRef.TopLayer__DOT__msip)))))
                                                      : 0U)
                                                     : 0U)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart0__wr_en 
        = ((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
           & (0x80U == (0xfcU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart1__wr_en 
        = ((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
           & (0x88U == (0xfcU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart2__wr_en 
        = ((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
           & (0x90U == (0xfcU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart3__wr_en 
        = ((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
           & (0x98U == (0xfcU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart0__rd_data_en 
        = ((IData)(TopLayer__DOT__mmio_read_en) & (0x80U 
                                                   == 
                                                   (0xfcU 
                                                    & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart1__rd_data_en 
        = ((IData)(TopLayer__DOT__mmio_read_en) & (0x88U 
                                                   == 
                                                   (0xfcU 
                                                    & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart2__rd_data_en 
        = ((IData)(TopLayer__DOT__mmio_read_en) & (0x90U 
                                                   == 
                                                   (0xfcU 
                                                    & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart3__rd_data_en 
        = ((IData)(TopLayer__DOT__mmio_read_en) & (0x98U 
                                                   == 
                                                   (0xfcU 
                                                    & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)));
}

VL_ATTR_COLD void VTopLayer___024root___eval_triggers__stl(VTopLayer___024root* vlSelf);

VL_ATTR_COLD bool VTopLayer___024root___eval_phase__stl(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VTopLayer___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VTopLayer___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTopLayer___024root___dump_triggers__ico(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___dump_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTopLayer___024root___dump_triggers__act(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTopLayer___024root___dump_triggers__nba(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTopLayer___024root___ctor_var_reset(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->irq_external = VL_RAND_RESET_I(1);
    vlSelf->gpio_in = VL_RAND_RESET_I(32);
    vlSelf->gpio_out = VL_RAND_RESET_I(32);
    vlSelf->uart_rx = VL_RAND_RESET_I(4);
    vlSelf->uart_tx = VL_RAND_RESET_I(4);
    vlSelf->TopLayer__DOT__mem_data_out = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__mem_instruction = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__mmio_write_en = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__bram_write_mode = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__bram_data_out = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT____Vcellinp__uart0__rd_data_en = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT____Vcellinp__uart0__wr_en = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT____Vcellinp__uart1__rd_data_en = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT____Vcellinp__uart1__wr_en = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT____Vcellinp__uart2__rd_data_en = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT____Vcellinp__uart2__wr_en = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT____Vcellinp__uart3__rd_data_en = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT____Vcellinp__uart3__wr_en = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__mtime = VL_RAND_RESET_Q(64);
    vlSelf->TopLayer__DOT__mtimecmp = VL_RAND_RESET_Q(64);
    vlSelf->TopLayer__DOT__msip = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__mmio_read_data = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__read_was_mmio = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__mmio_read_data_q = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__mstatus = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__mie = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__mip = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__mtvec = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__mepc = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__mcause = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__mtval = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__mscratch = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__cycle = VL_RAND_RESET_Q(64);
    vlSelf->TopLayer__DOT__cpu__DOT__instret = VL_RAND_RESET_Q(64);
    vlSelf->TopLayer__DOT__cpu__DOT__PC = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__PC_decode = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__next_PC = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__flush_d = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__cpu__DOT__BRAMInstruction = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__opcode = VL_RAND_RESET_I(7);
    vlSelf->TopLayer__DOT__cpu__DOT__funct3 = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__cpu__DOT__rd_addr = VL_RAND_RESET_I(5);
    vlSelf->TopLayer__DOT__cpu__DOT__imm_i = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__csr_addr = VL_RAND_RESET_I(12);
    vlSelf->TopLayer__DOT__cpu__DOT__rs1_data_fwd = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__wb_write_gpr = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__cpu__DOT__BRAM_read_addr = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__BRAM_write_addr = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__BRAM_data_in = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__BRAM_load_mode = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__cpu__DOT__EX_result = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__EX_csr_result = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__toWB_mode = VL_RAND_RESET_I(2);
    vlSelf->TopLayer__DOT__cpu__DOT__toWB_Result_Reg = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__toWB_rd_addr_Reg = VL_RAND_RESET_I(5);
    vlSelf->TopLayer__DOT__cpu__DOT__toWB_csr_addr_Reg = VL_RAND_RESET_I(12);
    vlSelf->TopLayer__DOT__cpu__DOT__toWB_csr_data_Reg = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__toWB_mode_Reg = VL_RAND_RESET_I(2);
    vlSelf->TopLayer__DOT__cpu__DOT__WB_rd_addr = VL_RAND_RESET_I(5);
    vlSelf->TopLayer__DOT__cpu__DOT__WB_rd_data = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__WB_write_enable = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__cpu__DOT__branch_taken = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__cpu__DOT__take_trap = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__cpu__DOT__take_mret = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__cpu__DOT__trap_cause = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__trap_tval = VL_RAND_RESET_I(32);
    vlSelf->TopLayer__DOT__cpu__DOT__irq_ext = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__cpu__DOT__irq_soft = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__cpu__DOT__irq_ready = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__cpu__DOT____VdfgRegularize_h0c4dd555_2_3 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->TopLayer__DOT__cpu__DOT__registry__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->TopLayer__DOT__bram__DOT__InstructionMem[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->TopLayer__DOT__bram__DOT__DataMem[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->TopLayer__DOT__uart0__DOT__txbuf[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->TopLayer__DOT__uart0__DOT__tx_wr = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart0__DOT__tx_rd = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart0__DOT__tx_cnt = VL_RAND_RESET_I(4);
    vlSelf->TopLayer__DOT__uart0__DOT__tx_full = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->TopLayer__DOT__uart0__DOT__rxbuf[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->TopLayer__DOT__uart0__DOT__rx_wr = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart0__DOT__rx_rd = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart0__DOT__rx_cnt = VL_RAND_RESET_I(4);
    vlSelf->TopLayer__DOT__uart0__DOT__rx_empty = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart0__DOT__tx_state = VL_RAND_RESET_I(2);
    vlSelf->TopLayer__DOT__uart0__DOT__tx_baud = VL_RAND_RESET_I(16);
    vlSelf->TopLayer__DOT__uart0__DOT__tx_bit = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart0__DOT__tx_shift = VL_RAND_RESET_I(8);
    vlSelf->TopLayer__DOT__uart0__DOT__tx_line = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart0__DOT__tx_pop = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart0__DOT__rx_state = VL_RAND_RESET_I(2);
    vlSelf->TopLayer__DOT__uart0__DOT__rx_baud = VL_RAND_RESET_I(16);
    vlSelf->TopLayer__DOT__uart0__DOT__rx_bit = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart0__DOT__rx_shift = VL_RAND_RESET_I(8);
    vlSelf->TopLayer__DOT__uart0__DOT__rx_s1 = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart0__DOT__rx_s2 = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart0__DOT__rx_push = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->TopLayer__DOT__uart1__DOT__txbuf[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->TopLayer__DOT__uart1__DOT__tx_wr = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart1__DOT__tx_rd = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart1__DOT__tx_cnt = VL_RAND_RESET_I(4);
    vlSelf->TopLayer__DOT__uart1__DOT__tx_full = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->TopLayer__DOT__uart1__DOT__rxbuf[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->TopLayer__DOT__uart1__DOT__rx_wr = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart1__DOT__rx_rd = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart1__DOT__rx_cnt = VL_RAND_RESET_I(4);
    vlSelf->TopLayer__DOT__uart1__DOT__rx_empty = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart1__DOT__tx_state = VL_RAND_RESET_I(2);
    vlSelf->TopLayer__DOT__uart1__DOT__tx_baud = VL_RAND_RESET_I(16);
    vlSelf->TopLayer__DOT__uart1__DOT__tx_bit = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart1__DOT__tx_shift = VL_RAND_RESET_I(8);
    vlSelf->TopLayer__DOT__uart1__DOT__tx_line = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart1__DOT__tx_pop = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart1__DOT__rx_state = VL_RAND_RESET_I(2);
    vlSelf->TopLayer__DOT__uart1__DOT__rx_baud = VL_RAND_RESET_I(16);
    vlSelf->TopLayer__DOT__uart1__DOT__rx_bit = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart1__DOT__rx_shift = VL_RAND_RESET_I(8);
    vlSelf->TopLayer__DOT__uart1__DOT__rx_s1 = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart1__DOT__rx_s2 = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart1__DOT__rx_push = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->TopLayer__DOT__uart2__DOT__txbuf[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->TopLayer__DOT__uart2__DOT__tx_wr = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart2__DOT__tx_rd = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart2__DOT__tx_cnt = VL_RAND_RESET_I(4);
    vlSelf->TopLayer__DOT__uart2__DOT__tx_full = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->TopLayer__DOT__uart2__DOT__rxbuf[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->TopLayer__DOT__uart2__DOT__rx_wr = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart2__DOT__rx_rd = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart2__DOT__rx_cnt = VL_RAND_RESET_I(4);
    vlSelf->TopLayer__DOT__uart2__DOT__rx_empty = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart2__DOT__tx_state = VL_RAND_RESET_I(2);
    vlSelf->TopLayer__DOT__uart2__DOT__tx_baud = VL_RAND_RESET_I(16);
    vlSelf->TopLayer__DOT__uart2__DOT__tx_bit = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart2__DOT__tx_shift = VL_RAND_RESET_I(8);
    vlSelf->TopLayer__DOT__uart2__DOT__tx_line = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart2__DOT__tx_pop = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart2__DOT__rx_state = VL_RAND_RESET_I(2);
    vlSelf->TopLayer__DOT__uart2__DOT__rx_baud = VL_RAND_RESET_I(16);
    vlSelf->TopLayer__DOT__uart2__DOT__rx_bit = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart2__DOT__rx_shift = VL_RAND_RESET_I(8);
    vlSelf->TopLayer__DOT__uart2__DOT__rx_s1 = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart2__DOT__rx_s2 = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart2__DOT__rx_push = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->TopLayer__DOT__uart3__DOT__txbuf[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->TopLayer__DOT__uart3__DOT__tx_wr = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart3__DOT__tx_rd = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart3__DOT__tx_cnt = VL_RAND_RESET_I(4);
    vlSelf->TopLayer__DOT__uart3__DOT__tx_full = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->TopLayer__DOT__uart3__DOT__rxbuf[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->TopLayer__DOT__uart3__DOT__rx_wr = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart3__DOT__rx_rd = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart3__DOT__rx_cnt = VL_RAND_RESET_I(4);
    vlSelf->TopLayer__DOT__uart3__DOT__rx_empty = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart3__DOT__tx_state = VL_RAND_RESET_I(2);
    vlSelf->TopLayer__DOT__uart3__DOT__tx_baud = VL_RAND_RESET_I(16);
    vlSelf->TopLayer__DOT__uart3__DOT__tx_bit = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart3__DOT__tx_shift = VL_RAND_RESET_I(8);
    vlSelf->TopLayer__DOT__uart3__DOT__tx_line = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart3__DOT__tx_pop = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart3__DOT__rx_state = VL_RAND_RESET_I(2);
    vlSelf->TopLayer__DOT__uart3__DOT__rx_baud = VL_RAND_RESET_I(16);
    vlSelf->TopLayer__DOT__uart3__DOT__rx_bit = VL_RAND_RESET_I(3);
    vlSelf->TopLayer__DOT__uart3__DOT__rx_shift = VL_RAND_RESET_I(8);
    vlSelf->TopLayer__DOT__uart3__DOT__rx_s1 = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart3__DOT__rx_s2 = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__uart3__DOT__rx_push = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__0__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__0__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__1__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__1__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__2__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__2__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__3__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__3__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__4__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__4__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__5__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__5__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__6__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__6__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__7__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__7__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__8__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__8__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__9__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__9__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__10__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__10__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__11__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__11__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__12__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__12__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__13__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__13__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__14__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__14__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__15__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__15__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__16__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__16__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__17__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__17__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__18__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__18__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__19__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__19__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__20__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__20__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__21__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__21__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__22__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__22__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__23__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__23__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__24__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__24__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__25__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__25__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__26__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__26__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__27__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__27__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__28__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__28__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__29__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__29__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__30__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__30__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__31__KET____DOT__gpio_pin__DOT__in_latch = VL_RAND_RESET_I(1);
    vlSelf->TopLayer__DOT__gpio_bank__BRA__31__KET____DOT__gpio_pin__DOT__out_latch = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_RAND_RESET_I(1);
}
