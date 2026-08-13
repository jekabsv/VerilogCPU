// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTopLayer.h for the primary calling header

#include "VTopLayer__pch.h"
#include "VTopLayer___024root.h"

void VTopLayer___024root___ico_sequent__TOP__0(VTopLayer___024root* vlSelf);

void VTopLayer___024root___eval_ico(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___eval_ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VTopLayer___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VTopLayer___024root___ico_sequent__TOP__0(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___ico_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ TopLayer__DOT__mmio_read_en;
    TopLayer__DOT__mmio_read_en = 0;
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
    // Body
    vlSelfRef.TopLayer__DOT__cpu__DOT__irq_ext = (1U 
                                                  & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mstatus 
                                                      >> 3U) 
                                                     & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mie 
                                                         >> 0xbU) 
                                                        & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mip 
                                                            >> 0xbU) 
                                                           | ((0U 
                                                               != vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_pending) 
                                                              | ((IData)(vlSelfRef.irq_external) 
                                                                 | ((IData)(vlSelfRef.TopLayer__DOT__uart_irq0) 
                                                                    | ((IData)(vlSelfRef.TopLayer__DOT__uart_irq1) 
                                                                       | ((IData)(vlSelfRef.TopLayer__DOT__uart_irq2) 
                                                                          | (IData)(vlSelfRef.TopLayer__DOT__uart_irq3))))))))));
    vlSelfRef.TopLayer__DOT__cpu__DOT__irq_ready = 
        (1U & ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__irq_ext) 
               | ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__irq_soft) 
                  | ((vlSelfRef.TopLayer__DOT__cpu__DOT__mstatus 
                      >> 3U) & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mie 
                                 >> 7U) & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mip 
                                            >> 7U) 
                                           | (vlSelfRef.TopLayer__DOT__mtime 
                                              >= vlSelfRef.TopLayer__DOT__mtimecmp)))))));
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
    TopLayer__DOT__mmio_read_en = ((0xffffffU == (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                  >> 8U)) 
                                   & (7U != (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_load_mode)));
    if ((0xffffffU == (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                       >> 8U))) {
        vlSelfRef.TopLayer__DOT__bram_write_mode = 7U;
        vlSelfRef.TopLayer__DOT__mmio_write_en = (7U 
                                                  != (IData)(TopLayer__DOT__cpu__DOT__BRAM_store_mode));
    } else {
        vlSelfRef.TopLayer__DOT__bram_write_mode = TopLayer__DOT__cpu__DOT__BRAM_store_mode;
        vlSelfRef.TopLayer__DOT__mmio_write_en = 0U;
    }
    vlSelfRef.TopLayer__DOT____Vcellinp__uart0__rd_data_en 
        = ((IData)(TopLayer__DOT__mmio_read_en) & (0x40U 
                                                   == 
                                                   (0xfcU 
                                                    & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart1__rd_data_en 
        = ((IData)(TopLayer__DOT__mmio_read_en) & (0x50U 
                                                   == 
                                                   (0xfcU 
                                                    & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart2__rd_data_en 
        = ((IData)(TopLayer__DOT__mmio_read_en) & (0x60U 
                                                   == 
                                                   (0xfcU 
                                                    & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart3__rd_data_en 
        = ((IData)(TopLayer__DOT__mmio_read_en) & (0x70U 
                                                   == 
                                                   (0xfcU 
                                                    & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)));
    vlSelfRef.TopLayer__DOT__gpio_we = ((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
                                        & (8U >= (0x3fU 
                                                  & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                                                     >> 2U))));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart0__wr_en 
        = ((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
           & (0x40U == (0xfcU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart1__wr_en 
        = ((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
           & (0x50U == (0xfcU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart2__wr_en 
        = ((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
           & (0x60U == (0xfcU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart3__wr_en 
        = ((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
           & (0x70U == (0xfcU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)));
}

void VTopLayer___024root___eval_triggers__ico(VTopLayer___024root* vlSelf);

bool VTopLayer___024root___eval_phase__ico(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___eval_phase__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VTopLayer___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        VTopLayer___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VTopLayer___024root___eval_act(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VTopLayer___024root___nba_sequent__TOP__0(VTopLayer___024root* vlSelf);
void VTopLayer___024root___nba_sequent__TOP__1(VTopLayer___024root* vlSelf);
void VTopLayer___024root___nba_sequent__TOP__2(VTopLayer___024root* vlSelf);
void VTopLayer___024root___nba_comb__TOP__0(VTopLayer___024root* vlSelf);

void VTopLayer___024root___eval_nba(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTopLayer___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTopLayer___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTopLayer___024root___nba_sequent__TOP__2(vlSelf);
        VTopLayer___024root___nba_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VTopLayer___024root___nba_sequent__TOP__0(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*11:0*/ __Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr;
    __Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr = 0;
    IData/*31:0*/ __Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__value;
    __Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__value = 0;
    QData/*63:0*/ __Vdly__TopLayer__DOT__mtime;
    __Vdly__TopLayer__DOT__mtime = 0;
    QData/*63:0*/ __Vdly__TopLayer__DOT__cpu__DOT__instret;
    __Vdly__TopLayer__DOT__cpu__DOT__instret = 0;
    IData/*31:0*/ __Vdly__TopLayer__DOT__cpu__DOT__mstatus;
    __Vdly__TopLayer__DOT__cpu__DOT__mstatus = 0;
    IData/*31:0*/ __Vdly__TopLayer__DOT__gpio_bank__DOT__data_out;
    __Vdly__TopLayer__DOT__gpio_bank__DOT__data_out = 0;
    CData/*1:0*/ __Vdly__TopLayer__DOT__uart0__DOT__rx_state;
    __Vdly__TopLayer__DOT__uart0__DOT__rx_state = 0;
    SData/*15:0*/ __Vdly__TopLayer__DOT__uart0__DOT__rx_baud;
    __Vdly__TopLayer__DOT__uart0__DOT__rx_baud = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart0__DOT__rx_bit;
    __Vdly__TopLayer__DOT__uart0__DOT__rx_bit = 0;
    CData/*3:0*/ __Vdly__TopLayer__DOT__uart0__DOT__rx_cnt;
    __Vdly__TopLayer__DOT__uart0__DOT__rx_cnt = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart0__DOT__rx_rd;
    __Vdly__TopLayer__DOT__uart0__DOT__rx_rd = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart0__DOT__rx_wr;
    __Vdly__TopLayer__DOT__uart0__DOT__rx_wr = 0;
    CData/*3:0*/ __Vdly__TopLayer__DOT__uart0__DOT__tx_cnt;
    __Vdly__TopLayer__DOT__uart0__DOT__tx_cnt = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart0__DOT__tx_rd;
    __Vdly__TopLayer__DOT__uart0__DOT__tx_rd = 0;
    CData/*1:0*/ __Vdly__TopLayer__DOT__uart0__DOT__tx_state;
    __Vdly__TopLayer__DOT__uart0__DOT__tx_state = 0;
    SData/*15:0*/ __Vdly__TopLayer__DOT__uart0__DOT__tx_baud;
    __Vdly__TopLayer__DOT__uart0__DOT__tx_baud = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart0__DOT__tx_bit;
    __Vdly__TopLayer__DOT__uart0__DOT__tx_bit = 0;
    CData/*7:0*/ __Vdly__TopLayer__DOT__uart0__DOT__tx_shift;
    __Vdly__TopLayer__DOT__uart0__DOT__tx_shift = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart0__DOT__tx_wr;
    __Vdly__TopLayer__DOT__uart0__DOT__tx_wr = 0;
    CData/*1:0*/ __Vdly__TopLayer__DOT__uart1__DOT__rx_state;
    __Vdly__TopLayer__DOT__uart1__DOT__rx_state = 0;
    SData/*15:0*/ __Vdly__TopLayer__DOT__uart1__DOT__rx_baud;
    __Vdly__TopLayer__DOT__uart1__DOT__rx_baud = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart1__DOT__rx_bit;
    __Vdly__TopLayer__DOT__uart1__DOT__rx_bit = 0;
    CData/*3:0*/ __Vdly__TopLayer__DOT__uart1__DOT__rx_cnt;
    __Vdly__TopLayer__DOT__uart1__DOT__rx_cnt = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart1__DOT__rx_rd;
    __Vdly__TopLayer__DOT__uart1__DOT__rx_rd = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart1__DOT__rx_wr;
    __Vdly__TopLayer__DOT__uart1__DOT__rx_wr = 0;
    CData/*3:0*/ __Vdly__TopLayer__DOT__uart1__DOT__tx_cnt;
    __Vdly__TopLayer__DOT__uart1__DOT__tx_cnt = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart1__DOT__tx_rd;
    __Vdly__TopLayer__DOT__uart1__DOT__tx_rd = 0;
    CData/*1:0*/ __Vdly__TopLayer__DOT__uart1__DOT__tx_state;
    __Vdly__TopLayer__DOT__uart1__DOT__tx_state = 0;
    SData/*15:0*/ __Vdly__TopLayer__DOT__uart1__DOT__tx_baud;
    __Vdly__TopLayer__DOT__uart1__DOT__tx_baud = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart1__DOT__tx_bit;
    __Vdly__TopLayer__DOT__uart1__DOT__tx_bit = 0;
    CData/*7:0*/ __Vdly__TopLayer__DOT__uart1__DOT__tx_shift;
    __Vdly__TopLayer__DOT__uart1__DOT__tx_shift = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart1__DOT__tx_wr;
    __Vdly__TopLayer__DOT__uart1__DOT__tx_wr = 0;
    CData/*1:0*/ __Vdly__TopLayer__DOT__uart2__DOT__rx_state;
    __Vdly__TopLayer__DOT__uart2__DOT__rx_state = 0;
    SData/*15:0*/ __Vdly__TopLayer__DOT__uart2__DOT__rx_baud;
    __Vdly__TopLayer__DOT__uart2__DOT__rx_baud = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart2__DOT__rx_bit;
    __Vdly__TopLayer__DOT__uart2__DOT__rx_bit = 0;
    CData/*3:0*/ __Vdly__TopLayer__DOT__uart2__DOT__rx_cnt;
    __Vdly__TopLayer__DOT__uart2__DOT__rx_cnt = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart2__DOT__rx_rd;
    __Vdly__TopLayer__DOT__uart2__DOT__rx_rd = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart2__DOT__rx_wr;
    __Vdly__TopLayer__DOT__uart2__DOT__rx_wr = 0;
    CData/*3:0*/ __Vdly__TopLayer__DOT__uart2__DOT__tx_cnt;
    __Vdly__TopLayer__DOT__uart2__DOT__tx_cnt = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart2__DOT__tx_rd;
    __Vdly__TopLayer__DOT__uart2__DOT__tx_rd = 0;
    CData/*1:0*/ __Vdly__TopLayer__DOT__uart2__DOT__tx_state;
    __Vdly__TopLayer__DOT__uart2__DOT__tx_state = 0;
    SData/*15:0*/ __Vdly__TopLayer__DOT__uart2__DOT__tx_baud;
    __Vdly__TopLayer__DOT__uart2__DOT__tx_baud = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart2__DOT__tx_bit;
    __Vdly__TopLayer__DOT__uart2__DOT__tx_bit = 0;
    CData/*7:0*/ __Vdly__TopLayer__DOT__uart2__DOT__tx_shift;
    __Vdly__TopLayer__DOT__uart2__DOT__tx_shift = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart2__DOT__tx_wr;
    __Vdly__TopLayer__DOT__uart2__DOT__tx_wr = 0;
    CData/*1:0*/ __Vdly__TopLayer__DOT__uart3__DOT__rx_state;
    __Vdly__TopLayer__DOT__uart3__DOT__rx_state = 0;
    SData/*15:0*/ __Vdly__TopLayer__DOT__uart3__DOT__rx_baud;
    __Vdly__TopLayer__DOT__uart3__DOT__rx_baud = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart3__DOT__rx_bit;
    __Vdly__TopLayer__DOT__uart3__DOT__rx_bit = 0;
    CData/*3:0*/ __Vdly__TopLayer__DOT__uart3__DOT__rx_cnt;
    __Vdly__TopLayer__DOT__uart3__DOT__rx_cnt = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart3__DOT__rx_rd;
    __Vdly__TopLayer__DOT__uart3__DOT__rx_rd = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart3__DOT__rx_wr;
    __Vdly__TopLayer__DOT__uart3__DOT__rx_wr = 0;
    CData/*3:0*/ __Vdly__TopLayer__DOT__uart3__DOT__tx_cnt;
    __Vdly__TopLayer__DOT__uart3__DOT__tx_cnt = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart3__DOT__tx_rd;
    __Vdly__TopLayer__DOT__uart3__DOT__tx_rd = 0;
    CData/*1:0*/ __Vdly__TopLayer__DOT__uart3__DOT__tx_state;
    __Vdly__TopLayer__DOT__uart3__DOT__tx_state = 0;
    SData/*15:0*/ __Vdly__TopLayer__DOT__uart3__DOT__tx_baud;
    __Vdly__TopLayer__DOT__uart3__DOT__tx_baud = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart3__DOT__tx_bit;
    __Vdly__TopLayer__DOT__uart3__DOT__tx_bit = 0;
    CData/*7:0*/ __Vdly__TopLayer__DOT__uart3__DOT__tx_shift;
    __Vdly__TopLayer__DOT__uart3__DOT__tx_shift = 0;
    CData/*2:0*/ __Vdly__TopLayer__DOT__uart3__DOT__tx_wr;
    __Vdly__TopLayer__DOT__uart3__DOT__tx_wr = 0;
    CData/*0:0*/ __VdlySet__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v0;
    __VdlySet__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v0 = 0;
    IData/*31:0*/ __VdlyVal__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v32;
    __VdlyVal__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v32 = 0;
    CData/*4:0*/ __VdlyDim0__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v32;
    __VdlyDim0__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v32 = 0;
    CData/*0:0*/ __VdlySet__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v32;
    __VdlySet__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v32 = 0;
    CData/*7:0*/ __VdlyVal__TopLayer__DOT__uart0__DOT__rxbuf__v0;
    __VdlyVal__TopLayer__DOT__uart0__DOT__rxbuf__v0 = 0;
    CData/*2:0*/ __VdlyDim0__TopLayer__DOT__uart0__DOT__rxbuf__v0;
    __VdlyDim0__TopLayer__DOT__uart0__DOT__rxbuf__v0 = 0;
    CData/*0:0*/ __VdlySet__TopLayer__DOT__uart0__DOT__rxbuf__v0;
    __VdlySet__TopLayer__DOT__uart0__DOT__rxbuf__v0 = 0;
    CData/*7:0*/ __VdlyVal__TopLayer__DOT__uart0__DOT__txbuf__v0;
    __VdlyVal__TopLayer__DOT__uart0__DOT__txbuf__v0 = 0;
    CData/*2:0*/ __VdlyDim0__TopLayer__DOT__uart0__DOT__txbuf__v0;
    __VdlyDim0__TopLayer__DOT__uart0__DOT__txbuf__v0 = 0;
    CData/*0:0*/ __VdlySet__TopLayer__DOT__uart0__DOT__txbuf__v0;
    __VdlySet__TopLayer__DOT__uart0__DOT__txbuf__v0 = 0;
    CData/*7:0*/ __VdlyVal__TopLayer__DOT__uart1__DOT__rxbuf__v0;
    __VdlyVal__TopLayer__DOT__uart1__DOT__rxbuf__v0 = 0;
    CData/*2:0*/ __VdlyDim0__TopLayer__DOT__uart1__DOT__rxbuf__v0;
    __VdlyDim0__TopLayer__DOT__uart1__DOT__rxbuf__v0 = 0;
    CData/*0:0*/ __VdlySet__TopLayer__DOT__uart1__DOT__rxbuf__v0;
    __VdlySet__TopLayer__DOT__uart1__DOT__rxbuf__v0 = 0;
    CData/*7:0*/ __VdlyVal__TopLayer__DOT__uart1__DOT__txbuf__v0;
    __VdlyVal__TopLayer__DOT__uart1__DOT__txbuf__v0 = 0;
    CData/*2:0*/ __VdlyDim0__TopLayer__DOT__uart1__DOT__txbuf__v0;
    __VdlyDim0__TopLayer__DOT__uart1__DOT__txbuf__v0 = 0;
    CData/*0:0*/ __VdlySet__TopLayer__DOT__uart1__DOT__txbuf__v0;
    __VdlySet__TopLayer__DOT__uart1__DOT__txbuf__v0 = 0;
    CData/*7:0*/ __VdlyVal__TopLayer__DOT__uart2__DOT__rxbuf__v0;
    __VdlyVal__TopLayer__DOT__uart2__DOT__rxbuf__v0 = 0;
    CData/*2:0*/ __VdlyDim0__TopLayer__DOT__uart2__DOT__rxbuf__v0;
    __VdlyDim0__TopLayer__DOT__uart2__DOT__rxbuf__v0 = 0;
    CData/*0:0*/ __VdlySet__TopLayer__DOT__uart2__DOT__rxbuf__v0;
    __VdlySet__TopLayer__DOT__uart2__DOT__rxbuf__v0 = 0;
    CData/*7:0*/ __VdlyVal__TopLayer__DOT__uart2__DOT__txbuf__v0;
    __VdlyVal__TopLayer__DOT__uart2__DOT__txbuf__v0 = 0;
    CData/*2:0*/ __VdlyDim0__TopLayer__DOT__uart2__DOT__txbuf__v0;
    __VdlyDim0__TopLayer__DOT__uart2__DOT__txbuf__v0 = 0;
    CData/*0:0*/ __VdlySet__TopLayer__DOT__uart2__DOT__txbuf__v0;
    __VdlySet__TopLayer__DOT__uart2__DOT__txbuf__v0 = 0;
    CData/*7:0*/ __VdlyVal__TopLayer__DOT__uart3__DOT__rxbuf__v0;
    __VdlyVal__TopLayer__DOT__uart3__DOT__rxbuf__v0 = 0;
    CData/*2:0*/ __VdlyDim0__TopLayer__DOT__uart3__DOT__rxbuf__v0;
    __VdlyDim0__TopLayer__DOT__uart3__DOT__rxbuf__v0 = 0;
    CData/*0:0*/ __VdlySet__TopLayer__DOT__uart3__DOT__rxbuf__v0;
    __VdlySet__TopLayer__DOT__uart3__DOT__rxbuf__v0 = 0;
    CData/*7:0*/ __VdlyVal__TopLayer__DOT__uart3__DOT__txbuf__v0;
    __VdlyVal__TopLayer__DOT__uart3__DOT__txbuf__v0 = 0;
    CData/*2:0*/ __VdlyDim0__TopLayer__DOT__uart3__DOT__txbuf__v0;
    __VdlyDim0__TopLayer__DOT__uart3__DOT__txbuf__v0 = 0;
    CData/*0:0*/ __VdlySet__TopLayer__DOT__uart3__DOT__txbuf__v0;
    __VdlySet__TopLayer__DOT__uart3__DOT__txbuf__v0 = 0;
    // Body
    __Vdly__TopLayer__DOT__uart0__DOT__rx_bit = vlSelfRef.TopLayer__DOT__uart0__DOT__rx_bit;
    __Vdly__TopLayer__DOT__uart1__DOT__rx_bit = vlSelfRef.TopLayer__DOT__uart1__DOT__rx_bit;
    __Vdly__TopLayer__DOT__uart2__DOT__rx_bit = vlSelfRef.TopLayer__DOT__uart2__DOT__rx_bit;
    __Vdly__TopLayer__DOT__uart3__DOT__rx_bit = vlSelfRef.TopLayer__DOT__uart3__DOT__rx_bit;
    __Vdly__TopLayer__DOT__cpu__DOT__instret = vlSelfRef.TopLayer__DOT__cpu__DOT__instret;
    __Vdly__TopLayer__DOT__uart0__DOT__rx_state = vlSelfRef.TopLayer__DOT__uart0__DOT__rx_state;
    __Vdly__TopLayer__DOT__uart0__DOT__rx_baud = vlSelfRef.TopLayer__DOT__uart0__DOT__rx_baud;
    __Vdly__TopLayer__DOT__uart1__DOT__rx_state = vlSelfRef.TopLayer__DOT__uart1__DOT__rx_state;
    __Vdly__TopLayer__DOT__uart1__DOT__rx_baud = vlSelfRef.TopLayer__DOT__uart1__DOT__rx_baud;
    __Vdly__TopLayer__DOT__uart2__DOT__rx_state = vlSelfRef.TopLayer__DOT__uart2__DOT__rx_state;
    __Vdly__TopLayer__DOT__uart2__DOT__rx_baud = vlSelfRef.TopLayer__DOT__uart2__DOT__rx_baud;
    __Vdly__TopLayer__DOT__uart3__DOT__rx_state = vlSelfRef.TopLayer__DOT__uart3__DOT__rx_state;
    __Vdly__TopLayer__DOT__uart3__DOT__rx_baud = vlSelfRef.TopLayer__DOT__uart3__DOT__rx_baud;
    __Vdly__TopLayer__DOT__uart0__DOT__tx_wr = vlSelfRef.TopLayer__DOT__uart0__DOT__tx_wr;
    __Vdly__TopLayer__DOT__uart1__DOT__tx_wr = vlSelfRef.TopLayer__DOT__uart1__DOT__tx_wr;
    __Vdly__TopLayer__DOT__uart2__DOT__tx_wr = vlSelfRef.TopLayer__DOT__uart2__DOT__tx_wr;
    __Vdly__TopLayer__DOT__uart3__DOT__tx_wr = vlSelfRef.TopLayer__DOT__uart3__DOT__tx_wr;
    __VdlySet__TopLayer__DOT__uart0__DOT__txbuf__v0 = 0U;
    __VdlySet__TopLayer__DOT__uart1__DOT__txbuf__v0 = 0U;
    __VdlySet__TopLayer__DOT__uart2__DOT__txbuf__v0 = 0U;
    __VdlySet__TopLayer__DOT__uart3__DOT__txbuf__v0 = 0U;
    __Vdly__TopLayer__DOT__uart0__DOT__rx_rd = vlSelfRef.TopLayer__DOT__uart0__DOT__rx_rd;
    __Vdly__TopLayer__DOT__uart1__DOT__rx_rd = vlSelfRef.TopLayer__DOT__uart1__DOT__rx_rd;
    __Vdly__TopLayer__DOT__uart2__DOT__rx_rd = vlSelfRef.TopLayer__DOT__uart2__DOT__rx_rd;
    __Vdly__TopLayer__DOT__uart3__DOT__rx_rd = vlSelfRef.TopLayer__DOT__uart3__DOT__rx_rd;
    __Vdly__TopLayer__DOT__gpio_bank__DOT__data_out 
        = vlSelfRef.TopLayer__DOT__gpio_bank__DOT__data_out;
    __Vdly__TopLayer__DOT__uart0__DOT__rx_wr = vlSelfRef.TopLayer__DOT__uart0__DOT__rx_wr;
    __Vdly__TopLayer__DOT__uart1__DOT__rx_wr = vlSelfRef.TopLayer__DOT__uart1__DOT__rx_wr;
    __Vdly__TopLayer__DOT__uart2__DOT__rx_wr = vlSelfRef.TopLayer__DOT__uart2__DOT__rx_wr;
    __Vdly__TopLayer__DOT__uart3__DOT__rx_wr = vlSelfRef.TopLayer__DOT__uart3__DOT__rx_wr;
    __Vdly__TopLayer__DOT__mtime = vlSelfRef.TopLayer__DOT__mtime;
    __VdlySet__TopLayer__DOT__uart0__DOT__rxbuf__v0 = 0U;
    __VdlySet__TopLayer__DOT__uart1__DOT__rxbuf__v0 = 0U;
    __VdlySet__TopLayer__DOT__uart2__DOT__rxbuf__v0 = 0U;
    __VdlySet__TopLayer__DOT__uart3__DOT__rxbuf__v0 = 0U;
    __Vdly__TopLayer__DOT__uart0__DOT__rx_cnt = vlSelfRef.TopLayer__DOT__uart0__DOT__rx_cnt;
    __Vdly__TopLayer__DOT__uart1__DOT__rx_cnt = vlSelfRef.TopLayer__DOT__uart1__DOT__rx_cnt;
    __Vdly__TopLayer__DOT__uart2__DOT__rx_cnt = vlSelfRef.TopLayer__DOT__uart2__DOT__rx_cnt;
    __Vdly__TopLayer__DOT__uart3__DOT__rx_cnt = vlSelfRef.TopLayer__DOT__uart3__DOT__rx_cnt;
    __Vdly__TopLayer__DOT__uart0__DOT__tx_rd = vlSelfRef.TopLayer__DOT__uart0__DOT__tx_rd;
    __Vdly__TopLayer__DOT__uart0__DOT__tx_baud = vlSelfRef.TopLayer__DOT__uart0__DOT__tx_baud;
    __Vdly__TopLayer__DOT__uart0__DOT__tx_bit = vlSelfRef.TopLayer__DOT__uart0__DOT__tx_bit;
    __Vdly__TopLayer__DOT__uart0__DOT__tx_shift = vlSelfRef.TopLayer__DOT__uart0__DOT__tx_shift;
    __Vdly__TopLayer__DOT__uart1__DOT__tx_rd = vlSelfRef.TopLayer__DOT__uart1__DOT__tx_rd;
    __Vdly__TopLayer__DOT__uart1__DOT__tx_baud = vlSelfRef.TopLayer__DOT__uart1__DOT__tx_baud;
    __Vdly__TopLayer__DOT__uart1__DOT__tx_bit = vlSelfRef.TopLayer__DOT__uart1__DOT__tx_bit;
    __Vdly__TopLayer__DOT__uart1__DOT__tx_shift = vlSelfRef.TopLayer__DOT__uart1__DOT__tx_shift;
    __Vdly__TopLayer__DOT__uart2__DOT__tx_rd = vlSelfRef.TopLayer__DOT__uart2__DOT__tx_rd;
    __Vdly__TopLayer__DOT__uart2__DOT__tx_baud = vlSelfRef.TopLayer__DOT__uart2__DOT__tx_baud;
    __Vdly__TopLayer__DOT__uart2__DOT__tx_bit = vlSelfRef.TopLayer__DOT__uart2__DOT__tx_bit;
    __Vdly__TopLayer__DOT__uart2__DOT__tx_shift = vlSelfRef.TopLayer__DOT__uart2__DOT__tx_shift;
    __Vdly__TopLayer__DOT__uart3__DOT__tx_rd = vlSelfRef.TopLayer__DOT__uart3__DOT__tx_rd;
    __Vdly__TopLayer__DOT__uart3__DOT__tx_baud = vlSelfRef.TopLayer__DOT__uart3__DOT__tx_baud;
    __Vdly__TopLayer__DOT__uart3__DOT__tx_bit = vlSelfRef.TopLayer__DOT__uart3__DOT__tx_bit;
    __Vdly__TopLayer__DOT__uart3__DOT__tx_shift = vlSelfRef.TopLayer__DOT__uart3__DOT__tx_shift;
    __Vdly__TopLayer__DOT__uart0__DOT__tx_cnt = vlSelfRef.TopLayer__DOT__uart0__DOT__tx_cnt;
    __Vdly__TopLayer__DOT__uart1__DOT__tx_cnt = vlSelfRef.TopLayer__DOT__uart1__DOT__tx_cnt;
    __Vdly__TopLayer__DOT__uart2__DOT__tx_cnt = vlSelfRef.TopLayer__DOT__uart2__DOT__tx_cnt;
    __Vdly__TopLayer__DOT__uart3__DOT__tx_cnt = vlSelfRef.TopLayer__DOT__uart3__DOT__tx_cnt;
    __Vdly__TopLayer__DOT__uart0__DOT__tx_state = vlSelfRef.TopLayer__DOT__uart0__DOT__tx_state;
    __Vdly__TopLayer__DOT__uart1__DOT__tx_state = vlSelfRef.TopLayer__DOT__uart1__DOT__tx_state;
    __Vdly__TopLayer__DOT__uart2__DOT__tx_state = vlSelfRef.TopLayer__DOT__uart2__DOT__tx_state;
    __Vdly__TopLayer__DOT__uart3__DOT__tx_state = vlSelfRef.TopLayer__DOT__uart3__DOT__tx_state;
    __VdlySet__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v0 = 0U;
    __VdlySet__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v32 = 0U;
    __Vdly__TopLayer__DOT__cpu__DOT__mstatus = vlSelfRef.TopLayer__DOT__cpu__DOT__mstatus;
    if (vlSelfRef.rst) {
        vlSelfRef.TopLayer__DOT__cpu__DOT__cycle = 0ULL;
        __Vdly__TopLayer__DOT__cpu__DOT__instret = 0ULL;
        __Vdly__TopLayer__DOT__uart0__DOT__tx_wr = 0U;
        __Vdly__TopLayer__DOT__uart1__DOT__tx_wr = 0U;
        __Vdly__TopLayer__DOT__uart2__DOT__tx_wr = 0U;
        __Vdly__TopLayer__DOT__uart3__DOT__tx_wr = 0U;
        __Vdly__TopLayer__DOT__uart0__DOT__rx_rd = 0U;
        __Vdly__TopLayer__DOT__uart1__DOT__rx_rd = 0U;
        __Vdly__TopLayer__DOT__uart2__DOT__rx_rd = 0U;
        __Vdly__TopLayer__DOT__uart3__DOT__rx_rd = 0U;
        __Vdly__TopLayer__DOT__gpio_bank__DOT__data_out = 0U;
        __Vdly__TopLayer__DOT__mtime = 0ULL;
        __Vdly__TopLayer__DOT__uart0__DOT__rx_wr = 0U;
        __Vdly__TopLayer__DOT__uart1__DOT__rx_wr = 0U;
        __Vdly__TopLayer__DOT__uart2__DOT__rx_wr = 0U;
        __Vdly__TopLayer__DOT__uart3__DOT__rx_wr = 0U;
        __Vdly__TopLayer__DOT__uart0__DOT__rx_cnt = 0U;
        __Vdly__TopLayer__DOT__uart1__DOT__rx_cnt = 0U;
        __Vdly__TopLayer__DOT__uart2__DOT__rx_cnt = 0U;
        __Vdly__TopLayer__DOT__uart3__DOT__rx_cnt = 0U;
        __Vdly__TopLayer__DOT__uart0__DOT__tx_cnt = 0U;
        __Vdly__TopLayer__DOT__uart1__DOT__tx_cnt = 0U;
        __Vdly__TopLayer__DOT__uart2__DOT__tx_cnt = 0U;
        __Vdly__TopLayer__DOT__uart3__DOT__tx_cnt = 0U;
        vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_pending = 0U;
        __VdlySet__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v0 = 1U;
        vlSelfRef.TopLayer__DOT__mtimecmp = 0xffffffffffffffffULL;
        vlSelfRef.TopLayer__DOT__msip = 0U;
        vlSelfRef.TopLayer__DOT__uart0__DOT__ier = 0U;
        vlSelfRef.TopLayer__DOT__uart1__DOT__ier = 0U;
        vlSelfRef.TopLayer__DOT__uart2__DOT__ier = 0U;
        vlSelfRef.TopLayer__DOT__uart3__DOT__ier = 0U;
        __Vdly__TopLayer__DOT__uart0__DOT__tx_rd = 0U;
        __Vdly__TopLayer__DOT__uart0__DOT__tx_state = 0U;
        __Vdly__TopLayer__DOT__uart0__DOT__tx_baud = 0U;
        __Vdly__TopLayer__DOT__uart0__DOT__tx_bit = 0U;
        __Vdly__TopLayer__DOT__uart0__DOT__tx_shift = 0U;
        vlSelfRef.TopLayer__DOT__uart0__DOT__tx_line = 1U;
        __Vdly__TopLayer__DOT__uart1__DOT__tx_rd = 0U;
        __Vdly__TopLayer__DOT__uart1__DOT__tx_state = 0U;
        __Vdly__TopLayer__DOT__uart1__DOT__tx_baud = 0U;
        __Vdly__TopLayer__DOT__uart1__DOT__tx_bit = 0U;
        __Vdly__TopLayer__DOT__uart1__DOT__tx_shift = 0U;
        vlSelfRef.TopLayer__DOT__uart1__DOT__tx_line = 1U;
        __Vdly__TopLayer__DOT__uart2__DOT__tx_rd = 0U;
        __Vdly__TopLayer__DOT__uart2__DOT__tx_state = 0U;
        __Vdly__TopLayer__DOT__uart2__DOT__tx_baud = 0U;
        __Vdly__TopLayer__DOT__uart2__DOT__tx_bit = 0U;
        __Vdly__TopLayer__DOT__uart2__DOT__tx_shift = 0U;
        vlSelfRef.TopLayer__DOT__uart2__DOT__tx_line = 1U;
        __Vdly__TopLayer__DOT__uart3__DOT__tx_rd = 0U;
        __Vdly__TopLayer__DOT__uart3__DOT__tx_state = 0U;
        __Vdly__TopLayer__DOT__uart3__DOT__tx_baud = 0U;
        __Vdly__TopLayer__DOT__uart3__DOT__tx_bit = 0U;
        __Vdly__TopLayer__DOT__uart3__DOT__tx_shift = 0U;
        vlSelfRef.TopLayer__DOT__uart3__DOT__tx_line = 1U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_Result_Reg = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_rd_addr_Reg = 0U;
        __Vdly__TopLayer__DOT__cpu__DOT__mstatus = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__mie = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__mip = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__mtvec = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__mepc = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__mcause = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__mtval = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__mscratch = 0U;
        vlSelfRef.TopLayer__DOT__gpio_bank__DOT__dir = 0U;
        __Vdly__TopLayer__DOT__uart0__DOT__rx_state = 0U;
        __Vdly__TopLayer__DOT__uart0__DOT__rx_baud = 0U;
        __Vdly__TopLayer__DOT__uart0__DOT__rx_bit = 0U;
        vlSelfRef.TopLayer__DOT__uart0__DOT__rx_shift = 0U;
        __Vdly__TopLayer__DOT__uart1__DOT__rx_state = 0U;
        __Vdly__TopLayer__DOT__uart1__DOT__rx_baud = 0U;
        __Vdly__TopLayer__DOT__uart1__DOT__rx_bit = 0U;
        vlSelfRef.TopLayer__DOT__uart1__DOT__rx_shift = 0U;
        __Vdly__TopLayer__DOT__uart2__DOT__rx_state = 0U;
        __Vdly__TopLayer__DOT__uart2__DOT__rx_baud = 0U;
        __Vdly__TopLayer__DOT__uart2__DOT__rx_bit = 0U;
        vlSelfRef.TopLayer__DOT__uart2__DOT__rx_shift = 0U;
        __Vdly__TopLayer__DOT__uart3__DOT__rx_state = 0U;
        __Vdly__TopLayer__DOT__uart3__DOT__rx_baud = 0U;
        __Vdly__TopLayer__DOT__uart3__DOT__rx_bit = 0U;
        vlSelfRef.TopLayer__DOT__uart3__DOT__rx_shift = 0U;
        vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_enable = 0U;
        vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_rise_en = 0U;
        vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_fall_en = 0U;
        vlSelfRef.TopLayer__DOT__gpio_bank__DOT__sync1_d = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_csr_data_Reg = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_csr_addr_Reg = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__PC_decode = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg = 3U;
        vlSelfRef.TopLayer__DOT__gpio_bank__DOT__sync1 = 0U;
        vlSelfRef.TopLayer__DOT__gpio_bank__DOT__sync0 = 0U;
    } else {
        vlSelfRef.TopLayer__DOT__cpu__DOT__cycle = 
            (1ULL + vlSelfRef.TopLayer__DOT__cpu__DOT__cycle);
        if (((0U != vlSelfRef.TopLayer__DOT__cpu__DOT__BRAMInstruction) 
             & (~ (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__take_trap)))) {
            __Vdly__TopLayer__DOT__cpu__DOT__instret 
                = (1ULL + vlSelfRef.TopLayer__DOT__cpu__DOT__instret);
        }
        if (((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart0__wr_en) 
             & (8U != (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_cnt)))) {
            __VdlyVal__TopLayer__DOT__uart0__DOT__txbuf__v0 
                = (0xffU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in);
            __VdlyDim0__TopLayer__DOT__uart0__DOT__txbuf__v0 
                = vlSelfRef.TopLayer__DOT__uart0__DOT__tx_wr;
            __VdlySet__TopLayer__DOT__uart0__DOT__txbuf__v0 = 1U;
            __Vdly__TopLayer__DOT__uart0__DOT__tx_wr 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_wr)));
        }
        if (((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart1__wr_en) 
             & (8U != (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_cnt)))) {
            __VdlyVal__TopLayer__DOT__uart1__DOT__txbuf__v0 
                = (0xffU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in);
            __VdlyDim0__TopLayer__DOT__uart1__DOT__txbuf__v0 
                = vlSelfRef.TopLayer__DOT__uart1__DOT__tx_wr;
            __VdlySet__TopLayer__DOT__uart1__DOT__txbuf__v0 = 1U;
            __Vdly__TopLayer__DOT__uart1__DOT__tx_wr 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_wr)));
        }
        if (((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart2__wr_en) 
             & (8U != (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_cnt)))) {
            __VdlyVal__TopLayer__DOT__uart2__DOT__txbuf__v0 
                = (0xffU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in);
            __VdlyDim0__TopLayer__DOT__uart2__DOT__txbuf__v0 
                = vlSelfRef.TopLayer__DOT__uart2__DOT__tx_wr;
            __VdlySet__TopLayer__DOT__uart2__DOT__txbuf__v0 = 1U;
            __Vdly__TopLayer__DOT__uart2__DOT__tx_wr 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_wr)));
        }
        if (((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart3__wr_en) 
             & (8U != (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_cnt)))) {
            __VdlyVal__TopLayer__DOT__uart3__DOT__txbuf__v0 
                = (0xffU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in);
            __VdlyDim0__TopLayer__DOT__uart3__DOT__txbuf__v0 
                = vlSelfRef.TopLayer__DOT__uart3__DOT__tx_wr;
            __VdlySet__TopLayer__DOT__uart3__DOT__txbuf__v0 = 1U;
            __Vdly__TopLayer__DOT__uart3__DOT__tx_wr 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_wr)));
        }
        if (((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart0__rd_data_en) 
             & (0U != (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_cnt)))) {
            __Vdly__TopLayer__DOT__uart0__DOT__rx_rd 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_rd)));
        }
        if (((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart1__rd_data_en) 
             & (0U != (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_cnt)))) {
            __Vdly__TopLayer__DOT__uart1__DOT__rx_rd 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_rd)));
        }
        if (((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart2__rd_data_en) 
             & (0U != (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_cnt)))) {
            __Vdly__TopLayer__DOT__uart2__DOT__rx_rd 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_rd)));
        }
        if (((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart3__rd_data_en) 
             & (0U != (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_cnt)))) {
            __Vdly__TopLayer__DOT__uart3__DOT__rx_rd 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_rd)));
        }
        __Vdly__TopLayer__DOT__mtime = (1ULL + vlSelfRef.TopLayer__DOT__mtime);
        if (vlSelfRef.TopLayer__DOT__mmio_write_en) {
            if ((0x80U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)) {
                if ((0x40U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)) {
                    if ((1U & (~ (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                                  >> 5U)))) {
                        if ((0x10U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)) {
                            if ((1U & (~ (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                                          >> 3U)))) {
                                if ((1U & (~ (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                                              >> 2U)))) {
                                    __Vdly__TopLayer__DOT__mtime 
                                        = ((0xffffffffULL 
                                            & __Vdly__TopLayer__DOT__mtime) 
                                           | ((QData)((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in)) 
                                              << 0x20U));
                                }
                            }
                        } else if ((8U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)) {
                            if ((4U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)) {
                                __Vdly__TopLayer__DOT__mtime 
                                    = ((0xffffffff00000000ULL 
                                        & __Vdly__TopLayer__DOT__mtime) 
                                       | (IData)((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in)));
                            }
                        }
                        if ((1U & (~ (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                                      >> 4U)))) {
                            if ((8U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)) {
                                if ((1U & (~ (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                                              >> 2U)))) {
                                    vlSelfRef.TopLayer__DOT__mtimecmp 
                                        = ((0xffffffffULL 
                                            & vlSelfRef.TopLayer__DOT__mtimecmp) 
                                           | ((QData)((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in)) 
                                              << 0x20U));
                                }
                            } else if ((4U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)) {
                                vlSelfRef.TopLayer__DOT__mtimecmp 
                                    = ((0xffffffff00000000ULL 
                                        & vlSelfRef.TopLayer__DOT__mtimecmp) 
                                       | (IData)((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in)));
                            }
                            if ((1U & (~ (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                                          >> 3U)))) {
                                if ((1U & (~ (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                                              >> 2U)))) {
                                    vlSelfRef.TopLayer__DOT__msip 
                                        = (1U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in);
                                }
                            }
                        }
                    }
                }
            }
        }
        if (vlSelfRef.TopLayer__DOT__uart0__DOT__rx_push) {
            __VdlyVal__TopLayer__DOT__uart0__DOT__rxbuf__v0 
                = vlSelfRef.TopLayer__DOT__uart0__DOT__rx_shift;
            __VdlyDim0__TopLayer__DOT__uart0__DOT__rxbuf__v0 
                = vlSelfRef.TopLayer__DOT__uart0__DOT__rx_wr;
            __VdlySet__TopLayer__DOT__uart0__DOT__rxbuf__v0 = 1U;
            __Vdly__TopLayer__DOT__uart0__DOT__rx_wr 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_wr)));
        }
        if (vlSelfRef.TopLayer__DOT__uart1__DOT__rx_push) {
            __VdlyVal__TopLayer__DOT__uart1__DOT__rxbuf__v0 
                = vlSelfRef.TopLayer__DOT__uart1__DOT__rx_shift;
            __VdlyDim0__TopLayer__DOT__uart1__DOT__rxbuf__v0 
                = vlSelfRef.TopLayer__DOT__uart1__DOT__rx_wr;
            __VdlySet__TopLayer__DOT__uart1__DOT__rxbuf__v0 = 1U;
            __Vdly__TopLayer__DOT__uart1__DOT__rx_wr 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_wr)));
        }
        if (vlSelfRef.TopLayer__DOT__uart2__DOT__rx_push) {
            __VdlyVal__TopLayer__DOT__uart2__DOT__rxbuf__v0 
                = vlSelfRef.TopLayer__DOT__uart2__DOT__rx_shift;
            __VdlyDim0__TopLayer__DOT__uart2__DOT__rxbuf__v0 
                = vlSelfRef.TopLayer__DOT__uart2__DOT__rx_wr;
            __VdlySet__TopLayer__DOT__uart2__DOT__rxbuf__v0 = 1U;
            __Vdly__TopLayer__DOT__uart2__DOT__rx_wr 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_wr)));
        }
        if (vlSelfRef.TopLayer__DOT__uart3__DOT__rx_push) {
            __VdlyVal__TopLayer__DOT__uart3__DOT__rxbuf__v0 
                = vlSelfRef.TopLayer__DOT__uart3__DOT__rx_shift;
            __VdlyDim0__TopLayer__DOT__uart3__DOT__rxbuf__v0 
                = vlSelfRef.TopLayer__DOT__uart3__DOT__rx_wr;
            __VdlySet__TopLayer__DOT__uart3__DOT__rxbuf__v0 = 1U;
            __Vdly__TopLayer__DOT__uart3__DOT__rx_wr 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_wr)));
        }
        if (((IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_push) 
             & (~ ((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart0__rd_data_en) 
                   & (~ (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_empty)))))) {
            __Vdly__TopLayer__DOT__uart0__DOT__rx_cnt 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_cnt)));
        } else if (((~ (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_push)) 
                    & ((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart0__rd_data_en) 
                       & (~ (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_empty))))) {
            __Vdly__TopLayer__DOT__uart0__DOT__rx_cnt 
                = (0xfU & ((IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_cnt) 
                           - (IData)(1U)));
        }
        if (((IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_push) 
             & (~ ((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart1__rd_data_en) 
                   & (~ (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_empty)))))) {
            __Vdly__TopLayer__DOT__uart1__DOT__rx_cnt 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_cnt)));
        } else if (((~ (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_push)) 
                    & ((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart1__rd_data_en) 
                       & (~ (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_empty))))) {
            __Vdly__TopLayer__DOT__uart1__DOT__rx_cnt 
                = (0xfU & ((IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_cnt) 
                           - (IData)(1U)));
        }
        if (((IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_push) 
             & (~ ((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart2__rd_data_en) 
                   & (~ (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_empty)))))) {
            __Vdly__TopLayer__DOT__uart2__DOT__rx_cnt 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_cnt)));
        } else if (((~ (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_push)) 
                    & ((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart2__rd_data_en) 
                       & (~ (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_empty))))) {
            __Vdly__TopLayer__DOT__uart2__DOT__rx_cnt 
                = (0xfU & ((IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_cnt) 
                           - (IData)(1U)));
        }
        if (((IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_push) 
             & (~ ((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart3__rd_data_en) 
                   & (~ (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_empty)))))) {
            __Vdly__TopLayer__DOT__uart3__DOT__rx_cnt 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_cnt)));
        } else if (((~ (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_push)) 
                    & ((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart3__rd_data_en) 
                       & (~ (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_empty))))) {
            __Vdly__TopLayer__DOT__uart3__DOT__rx_cnt 
                = (0xfU & ((IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_cnt) 
                           - (IData)(1U)));
        }
        if ((((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart0__wr_en) 
              & (~ (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_full))) 
             & (~ (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_pop)))) {
            __Vdly__TopLayer__DOT__uart0__DOT__tx_cnt 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_cnt)));
        } else if (((~ ((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart0__wr_en) 
                        & (~ (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_full)))) 
                    & (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_pop))) {
            __Vdly__TopLayer__DOT__uart0__DOT__tx_cnt 
                = (0xfU & ((IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_cnt) 
                           - (IData)(1U)));
        }
        if ((((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart1__wr_en) 
              & (~ (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_full))) 
             & (~ (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_pop)))) {
            __Vdly__TopLayer__DOT__uart1__DOT__tx_cnt 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_cnt)));
        } else if (((~ ((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart1__wr_en) 
                        & (~ (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_full)))) 
                    & (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_pop))) {
            __Vdly__TopLayer__DOT__uart1__DOT__tx_cnt 
                = (0xfU & ((IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_cnt) 
                           - (IData)(1U)));
        }
        if ((((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart2__wr_en) 
              & (~ (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_full))) 
             & (~ (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_pop)))) {
            __Vdly__TopLayer__DOT__uart2__DOT__tx_cnt 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_cnt)));
        } else if (((~ ((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart2__wr_en) 
                        & (~ (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_full)))) 
                    & (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_pop))) {
            __Vdly__TopLayer__DOT__uart2__DOT__tx_cnt 
                = (0xfU & ((IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_cnt) 
                           - (IData)(1U)));
        }
        if ((((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart3__wr_en) 
              & (~ (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_full))) 
             & (~ (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_pop)))) {
            __Vdly__TopLayer__DOT__uart3__DOT__tx_cnt 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_cnt)));
        } else if (((~ ((IData)(vlSelfRef.TopLayer__DOT____Vcellinp__uart3__wr_en) 
                        & (~ (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_full)))) 
                    & (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_pop))) {
            __Vdly__TopLayer__DOT__uart3__DOT__tx_cnt 
                = (0xfU & ((IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_cnt) 
                           - (IData)(1U)));
        }
        vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_pending 
            = ((vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_pending 
                & (~ (((IData)(vlSelfRef.TopLayer__DOT__gpio_we) 
                       & (0x20U == (0x3cU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)))
                       ? vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in
                       : 0U))) | (vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_enable 
                                  & ((vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_rise_en 
                                      & ((~ vlSelfRef.TopLayer__DOT__gpio_bank__DOT__sync1_d) 
                                         & vlSelfRef.TopLayer__DOT__gpio_bank__DOT__sync1)) 
                                     | (vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_fall_en 
                                        & ((~ vlSelfRef.TopLayer__DOT__gpio_bank__DOT__sync1) 
                                           & vlSelfRef.TopLayer__DOT__gpio_bank__DOT__sync1_d)))));
        if (vlSelfRef.TopLayer__DOT__gpio_we) {
            if ((1U & (~ (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                          >> 5U)))) {
                if ((0x10U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)) {
                    if ((1U & (~ (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                                  >> 3U)))) {
                        if ((1U & (~ (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                                      >> 2U)))) {
                            __Vdly__TopLayer__DOT__gpio_bank__DOT__data_out 
                                = (vlSelfRef.TopLayer__DOT__gpio_bank__DOT__data_out 
                                   & (~ vlSelfRef.TopLayer__DOT__gpio_bank__DOT__write_mask));
                        }
                        if ((4U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)) {
                            vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_enable 
                                = vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in;
                        }
                    }
                    if ((8U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)) {
                        if ((1U & (~ (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                                      >> 2U)))) {
                            vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_rise_en 
                                = vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in;
                        }
                        if ((4U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)) {
                            vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_fall_en 
                                = vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in;
                        }
                    }
                } else if ((8U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)) {
                    if ((4U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)) {
                        __Vdly__TopLayer__DOT__gpio_bank__DOT__data_out 
                            = (vlSelfRef.TopLayer__DOT__gpio_bank__DOT__data_out 
                               | vlSelfRef.TopLayer__DOT__gpio_bank__DOT__write_mask);
                    }
                } else if ((4U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)) {
                    __Vdly__TopLayer__DOT__gpio_bank__DOT__data_out 
                        = ((vlSelfRef.TopLayer__DOT__gpio_bank__DOT__data_out 
                            & (~ vlSelfRef.TopLayer__DOT__gpio_bank__DOT__dir)) 
                           | vlSelfRef.TopLayer__DOT__gpio_bank__DOT__write_mask);
                }
                if ((1U & (~ (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                              >> 4U)))) {
                    if ((8U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)) {
                        if ((1U & (~ (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                                      >> 2U)))) {
                            vlSelfRef.TopLayer__DOT__gpio_bank__DOT__dir 
                                = vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in;
                        }
                    }
                }
            }
        }
        if (((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__WB_write_enable) 
             & (0U != (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_addr)))) {
            __VdlyVal__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v32 
                = vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_data;
            __VdlyDim0__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v32 
                = vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_addr;
            __VdlySet__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v32 = 1U;
        }
        if (((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
             & (0x48U == (0xfcU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)))) {
            vlSelfRef.TopLayer__DOT__uart0__DOT__ier 
                = (7U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in);
        }
        if (((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
             & (0x58U == (0xfcU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)))) {
            vlSelfRef.TopLayer__DOT__uart1__DOT__ier 
                = (7U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in);
        }
        if (((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
             & (0x68U == (0xfcU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)))) {
            vlSelfRef.TopLayer__DOT__uart2__DOT__ier 
                = (7U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in);
        }
        if (((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
             & (0x78U == (0xfcU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)))) {
            vlSelfRef.TopLayer__DOT__uart3__DOT__ier 
                = (7U & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in);
        }
        if ((2U & (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_state))) {
            if ((1U & (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_state))) {
                vlSelfRef.TopLayer__DOT__uart0__DOT__tx_line = 1U;
                if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_baud))) {
                    __Vdly__TopLayer__DOT__uart0__DOT__tx_baud = 0U;
                    __Vdly__TopLayer__DOT__uart0__DOT__tx_state = 0U;
                } else {
                    __Vdly__TopLayer__DOT__uart0__DOT__tx_baud 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_baud)));
                }
            } else {
                vlSelfRef.TopLayer__DOT__uart0__DOT__tx_line 
                    = (1U & ((IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_shift) 
                             >> (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_bit)));
                if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_baud))) {
                    __Vdly__TopLayer__DOT__uart0__DOT__tx_baud = 0U;
                    if ((7U == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_bit))) {
                        __Vdly__TopLayer__DOT__uart0__DOT__tx_state = 3U;
                    } else {
                        __Vdly__TopLayer__DOT__uart0__DOT__tx_bit 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_bit)));
                    }
                } else {
                    __Vdly__TopLayer__DOT__uart0__DOT__tx_baud 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_baud)));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_state))) {
            vlSelfRef.TopLayer__DOT__uart0__DOT__tx_line = 0U;
            if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_baud))) {
                __Vdly__TopLayer__DOT__uart0__DOT__tx_baud = 0U;
                __Vdly__TopLayer__DOT__uart0__DOT__tx_state = 2U;
            } else {
                __Vdly__TopLayer__DOT__uart0__DOT__tx_baud 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_baud)));
            }
        } else {
            vlSelfRef.TopLayer__DOT__uart0__DOT__tx_line = 1U;
            __Vdly__TopLayer__DOT__uart0__DOT__tx_baud = 0U;
            __Vdly__TopLayer__DOT__uart0__DOT__tx_bit = 0U;
            if ((0U != (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_cnt))) {
                __Vdly__TopLayer__DOT__uart0__DOT__tx_shift 
                    = vlSelfRef.TopLayer__DOT__uart0__DOT__txbuf
                    [vlSelfRef.TopLayer__DOT__uart0__DOT__tx_rd];
                __Vdly__TopLayer__DOT__uart0__DOT__tx_state = 1U;
                __Vdly__TopLayer__DOT__uart0__DOT__tx_rd 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_rd)));
            }
        }
        if ((2U & (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_state))) {
            if ((1U & (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_state))) {
                vlSelfRef.TopLayer__DOT__uart1__DOT__tx_line = 1U;
                if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_baud))) {
                    __Vdly__TopLayer__DOT__uart1__DOT__tx_baud = 0U;
                    __Vdly__TopLayer__DOT__uart1__DOT__tx_state = 0U;
                } else {
                    __Vdly__TopLayer__DOT__uart1__DOT__tx_baud 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_baud)));
                }
            } else {
                vlSelfRef.TopLayer__DOT__uart1__DOT__tx_line 
                    = (1U & ((IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_shift) 
                             >> (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_bit)));
                if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_baud))) {
                    __Vdly__TopLayer__DOT__uart1__DOT__tx_baud = 0U;
                    if ((7U == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_bit))) {
                        __Vdly__TopLayer__DOT__uart1__DOT__tx_state = 3U;
                    } else {
                        __Vdly__TopLayer__DOT__uart1__DOT__tx_bit 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_bit)));
                    }
                } else {
                    __Vdly__TopLayer__DOT__uart1__DOT__tx_baud 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_baud)));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_state))) {
            vlSelfRef.TopLayer__DOT__uart1__DOT__tx_line = 0U;
            if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_baud))) {
                __Vdly__TopLayer__DOT__uart1__DOT__tx_baud = 0U;
                __Vdly__TopLayer__DOT__uart1__DOT__tx_state = 2U;
            } else {
                __Vdly__TopLayer__DOT__uart1__DOT__tx_baud 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_baud)));
            }
        } else {
            vlSelfRef.TopLayer__DOT__uart1__DOT__tx_line = 1U;
            __Vdly__TopLayer__DOT__uart1__DOT__tx_baud = 0U;
            __Vdly__TopLayer__DOT__uart1__DOT__tx_bit = 0U;
            if ((0U != (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_cnt))) {
                __Vdly__TopLayer__DOT__uart1__DOT__tx_shift 
                    = vlSelfRef.TopLayer__DOT__uart1__DOT__txbuf
                    [vlSelfRef.TopLayer__DOT__uart1__DOT__tx_rd];
                __Vdly__TopLayer__DOT__uart1__DOT__tx_state = 1U;
                __Vdly__TopLayer__DOT__uart1__DOT__tx_rd 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_rd)));
            }
        }
        if ((2U & (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_state))) {
            if ((1U & (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_state))) {
                vlSelfRef.TopLayer__DOT__uart2__DOT__tx_line = 1U;
                if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_baud))) {
                    __Vdly__TopLayer__DOT__uart2__DOT__tx_baud = 0U;
                    __Vdly__TopLayer__DOT__uart2__DOT__tx_state = 0U;
                } else {
                    __Vdly__TopLayer__DOT__uart2__DOT__tx_baud 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_baud)));
                }
            } else {
                vlSelfRef.TopLayer__DOT__uart2__DOT__tx_line 
                    = (1U & ((IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_shift) 
                             >> (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_bit)));
                if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_baud))) {
                    __Vdly__TopLayer__DOT__uart2__DOT__tx_baud = 0U;
                    if ((7U == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_bit))) {
                        __Vdly__TopLayer__DOT__uart2__DOT__tx_state = 3U;
                    } else {
                        __Vdly__TopLayer__DOT__uart2__DOT__tx_bit 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_bit)));
                    }
                } else {
                    __Vdly__TopLayer__DOT__uart2__DOT__tx_baud 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_baud)));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_state))) {
            vlSelfRef.TopLayer__DOT__uart2__DOT__tx_line = 0U;
            if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_baud))) {
                __Vdly__TopLayer__DOT__uart2__DOT__tx_baud = 0U;
                __Vdly__TopLayer__DOT__uart2__DOT__tx_state = 2U;
            } else {
                __Vdly__TopLayer__DOT__uart2__DOT__tx_baud 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_baud)));
            }
        } else {
            vlSelfRef.TopLayer__DOT__uart2__DOT__tx_line = 1U;
            __Vdly__TopLayer__DOT__uart2__DOT__tx_baud = 0U;
            __Vdly__TopLayer__DOT__uart2__DOT__tx_bit = 0U;
            if ((0U != (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_cnt))) {
                __Vdly__TopLayer__DOT__uart2__DOT__tx_shift 
                    = vlSelfRef.TopLayer__DOT__uart2__DOT__txbuf
                    [vlSelfRef.TopLayer__DOT__uart2__DOT__tx_rd];
                __Vdly__TopLayer__DOT__uart2__DOT__tx_state = 1U;
                __Vdly__TopLayer__DOT__uart2__DOT__tx_rd 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_rd)));
            }
        }
        if ((2U & (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_state))) {
            if ((1U & (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_state))) {
                vlSelfRef.TopLayer__DOT__uart3__DOT__tx_line = 1U;
                if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_baud))) {
                    __Vdly__TopLayer__DOT__uart3__DOT__tx_baud = 0U;
                    __Vdly__TopLayer__DOT__uart3__DOT__tx_state = 0U;
                } else {
                    __Vdly__TopLayer__DOT__uart3__DOT__tx_baud 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_baud)));
                }
            } else {
                vlSelfRef.TopLayer__DOT__uart3__DOT__tx_line 
                    = (1U & ((IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_shift) 
                             >> (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_bit)));
                if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_baud))) {
                    __Vdly__TopLayer__DOT__uart3__DOT__tx_baud = 0U;
                    if ((7U == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_bit))) {
                        __Vdly__TopLayer__DOT__uart3__DOT__tx_state = 3U;
                    } else {
                        __Vdly__TopLayer__DOT__uart3__DOT__tx_bit 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_bit)));
                    }
                } else {
                    __Vdly__TopLayer__DOT__uart3__DOT__tx_baud 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_baud)));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_state))) {
            vlSelfRef.TopLayer__DOT__uart3__DOT__tx_line = 0U;
            if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_baud))) {
                __Vdly__TopLayer__DOT__uart3__DOT__tx_baud = 0U;
                __Vdly__TopLayer__DOT__uart3__DOT__tx_state = 2U;
            } else {
                __Vdly__TopLayer__DOT__uart3__DOT__tx_baud 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_baud)));
            }
        } else {
            vlSelfRef.TopLayer__DOT__uart3__DOT__tx_line = 1U;
            __Vdly__TopLayer__DOT__uart3__DOT__tx_baud = 0U;
            __Vdly__TopLayer__DOT__uart3__DOT__tx_bit = 0U;
            if ((0U != (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_cnt))) {
                __Vdly__TopLayer__DOT__uart3__DOT__tx_shift 
                    = vlSelfRef.TopLayer__DOT__uart3__DOT__txbuf
                    [vlSelfRef.TopLayer__DOT__uart3__DOT__tx_rd];
                __Vdly__TopLayer__DOT__uart3__DOT__tx_state = 1U;
                __Vdly__TopLayer__DOT__uart3__DOT__tx_rd 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_rd)));
            }
        }
        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_Result_Reg 
            = vlSelfRef.TopLayer__DOT__cpu__DOT__EX_result;
        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_rd_addr_Reg 
            = vlSelfRef.TopLayer__DOT__cpu__DOT__rd_addr;
        if ((1U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg))) {
            __Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__value 
                = vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_csr_data_Reg;
            __Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr 
                = vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_csr_addr_Reg;
            if (((((((((0x300U == (IData)(__Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr)) 
                       | (0x304U == (IData)(__Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr))) 
                      | (0x305U == (IData)(__Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr))) 
                     | (0x340U == (IData)(__Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr))) 
                    | (0x341U == (IData)(__Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr))) 
                   | (0x342U == (IData)(__Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr))) 
                  | (0x343U == (IData)(__Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr))) 
                 | (0x344U == (IData)(__Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr)))) {
                if ((0x300U == (IData)(__Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr))) {
                    __Vdly__TopLayer__DOT__cpu__DOT__mstatus 
                        = __Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__value;
                } else if ((0x304U == (IData)(__Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr))) {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__mie 
                        = __Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__value;
                } else if ((0x305U == (IData)(__Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr))) {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__mtvec 
                        = __Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__value;
                } else if ((0x340U == (IData)(__Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr))) {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__mscratch 
                        = __Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__value;
                } else if ((0x341U == (IData)(__Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr))) {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__mepc 
                        = __Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__value;
                } else if ((0x342U == (IData)(__Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr))) {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__mcause 
                        = __Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__value;
                } else if ((0x343U == (IData)(__Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__addr))) {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__mtval 
                        = __Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__value;
                } else {
                    vlSelfRef.TopLayer__DOT__cpu__DOT__mip 
                        = __Vtask_TopLayer__DOT__cpu__DOT__SetCSR__0__value;
                }
            }
        }
        if (vlSelfRef.TopLayer__DOT__cpu__DOT__take_trap) {
            __Vdly__TopLayer__DOT__cpu__DOT__mstatus 
                = ((0xffffff7fU & __Vdly__TopLayer__DOT__cpu__DOT__mstatus) 
                   | (0x80U & (vlSelfRef.TopLayer__DOT__cpu__DOT__mstatus 
                               << 4U)));
            vlSelfRef.TopLayer__DOT__cpu__DOT__mepc 
                = vlSelfRef.TopLayer__DOT__cpu__DOT__PC_decode;
            vlSelfRef.TopLayer__DOT__cpu__DOT__mcause 
                = vlSelfRef.TopLayer__DOT__cpu__DOT__trap_cause;
            vlSelfRef.TopLayer__DOT__cpu__DOT__mtval 
                = vlSelfRef.TopLayer__DOT__cpu__DOT__trap_tval;
            __Vdly__TopLayer__DOT__cpu__DOT__mstatus 
                = (0xfffffff7U & __Vdly__TopLayer__DOT__cpu__DOT__mstatus);
            __Vdly__TopLayer__DOT__cpu__DOT__mstatus 
                = (0x1800U | __Vdly__TopLayer__DOT__cpu__DOT__mstatus);
        } else if (vlSelfRef.TopLayer__DOT__cpu__DOT__take_mret) {
            __Vdly__TopLayer__DOT__cpu__DOT__mstatus 
                = ((0xfffffff7U & __Vdly__TopLayer__DOT__cpu__DOT__mstatus) 
                   | (8U & (vlSelfRef.TopLayer__DOT__cpu__DOT__mstatus 
                            >> 4U)));
            __Vdly__TopLayer__DOT__cpu__DOT__mstatus 
                = (0x80U | __Vdly__TopLayer__DOT__cpu__DOT__mstatus);
            __Vdly__TopLayer__DOT__cpu__DOT__mstatus 
                = (0x1800U | __Vdly__TopLayer__DOT__cpu__DOT__mstatus);
        }
        if ((2U & (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_state))) {
            if ((1U & (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_state))) {
                if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_baud))) {
                    __Vdly__TopLayer__DOT__uart0__DOT__rx_baud = 0U;
                    __Vdly__TopLayer__DOT__uart0__DOT__rx_state = 0U;
                } else {
                    __Vdly__TopLayer__DOT__uart0__DOT__rx_baud 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_baud)));
                }
            } else if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_baud))) {
                __Vdly__TopLayer__DOT__uart0__DOT__rx_baud = 0U;
                vlSelfRef.TopLayer__DOT__uart0__DOT__rx_shift 
                    = (((~ ((IData)(1U) << (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_bit))) 
                        & (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_shift)) 
                       | (0xffU & ((IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_s2) 
                                   << (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_bit))));
                if ((7U == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_bit))) {
                    __Vdly__TopLayer__DOT__uart0__DOT__rx_state = 3U;
                } else {
                    __Vdly__TopLayer__DOT__uart0__DOT__rx_bit 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_bit)));
                }
            } else {
                __Vdly__TopLayer__DOT__uart0__DOT__rx_baud 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_baud)));
            }
        } else if ((1U & (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_state))) {
            if ((7U == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_baud))) {
                __Vdly__TopLayer__DOT__uart0__DOT__rx_baud = 0U;
                __Vdly__TopLayer__DOT__uart0__DOT__rx_state 
                    = ((IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_s2)
                        ? 0U : 2U);
            } else {
                __Vdly__TopLayer__DOT__uart0__DOT__rx_baud 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_baud)));
            }
        } else {
            __Vdly__TopLayer__DOT__uart0__DOT__rx_baud = 0U;
            __Vdly__TopLayer__DOT__uart0__DOT__rx_bit = 0U;
            if ((1U & (~ (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_s2)))) {
                __Vdly__TopLayer__DOT__uart0__DOT__rx_state = 1U;
            }
        }
        if ((2U & (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_state))) {
            if ((1U & (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_state))) {
                if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_baud))) {
                    __Vdly__TopLayer__DOT__uart1__DOT__rx_baud = 0U;
                    __Vdly__TopLayer__DOT__uart1__DOT__rx_state = 0U;
                } else {
                    __Vdly__TopLayer__DOT__uart1__DOT__rx_baud 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_baud)));
                }
            } else if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_baud))) {
                __Vdly__TopLayer__DOT__uart1__DOT__rx_baud = 0U;
                vlSelfRef.TopLayer__DOT__uart1__DOT__rx_shift 
                    = (((~ ((IData)(1U) << (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_bit))) 
                        & (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_shift)) 
                       | (0xffU & ((IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_s2) 
                                   << (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_bit))));
                if ((7U == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_bit))) {
                    __Vdly__TopLayer__DOT__uart1__DOT__rx_state = 3U;
                } else {
                    __Vdly__TopLayer__DOT__uart1__DOT__rx_bit 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_bit)));
                }
            } else {
                __Vdly__TopLayer__DOT__uart1__DOT__rx_baud 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_baud)));
            }
        } else if ((1U & (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_state))) {
            if ((7U == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_baud))) {
                __Vdly__TopLayer__DOT__uart1__DOT__rx_baud = 0U;
                __Vdly__TopLayer__DOT__uart1__DOT__rx_state 
                    = ((IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_s2)
                        ? 0U : 2U);
            } else {
                __Vdly__TopLayer__DOT__uart1__DOT__rx_baud 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_baud)));
            }
        } else {
            __Vdly__TopLayer__DOT__uart1__DOT__rx_baud = 0U;
            __Vdly__TopLayer__DOT__uart1__DOT__rx_bit = 0U;
            if ((1U & (~ (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_s2)))) {
                __Vdly__TopLayer__DOT__uart1__DOT__rx_state = 1U;
            }
        }
        if ((2U & (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_state))) {
            if ((1U & (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_state))) {
                if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_baud))) {
                    __Vdly__TopLayer__DOT__uart2__DOT__rx_baud = 0U;
                    __Vdly__TopLayer__DOT__uart2__DOT__rx_state = 0U;
                } else {
                    __Vdly__TopLayer__DOT__uart2__DOT__rx_baud 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_baud)));
                }
            } else if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_baud))) {
                __Vdly__TopLayer__DOT__uart2__DOT__rx_baud = 0U;
                vlSelfRef.TopLayer__DOT__uart2__DOT__rx_shift 
                    = (((~ ((IData)(1U) << (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_bit))) 
                        & (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_shift)) 
                       | (0xffU & ((IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_s2) 
                                   << (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_bit))));
                if ((7U == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_bit))) {
                    __Vdly__TopLayer__DOT__uart2__DOT__rx_state = 3U;
                } else {
                    __Vdly__TopLayer__DOT__uart2__DOT__rx_bit 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_bit)));
                }
            } else {
                __Vdly__TopLayer__DOT__uart2__DOT__rx_baud 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_baud)));
            }
        } else if ((1U & (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_state))) {
            if ((7U == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_baud))) {
                __Vdly__TopLayer__DOT__uart2__DOT__rx_baud = 0U;
                __Vdly__TopLayer__DOT__uart2__DOT__rx_state 
                    = ((IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_s2)
                        ? 0U : 2U);
            } else {
                __Vdly__TopLayer__DOT__uart2__DOT__rx_baud 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_baud)));
            }
        } else {
            __Vdly__TopLayer__DOT__uart2__DOT__rx_baud = 0U;
            __Vdly__TopLayer__DOT__uart2__DOT__rx_bit = 0U;
            if ((1U & (~ (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_s2)))) {
                __Vdly__TopLayer__DOT__uart2__DOT__rx_state = 1U;
            }
        }
        if ((2U & (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_state))) {
            if ((1U & (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_state))) {
                if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_baud))) {
                    __Vdly__TopLayer__DOT__uart3__DOT__rx_baud = 0U;
                    __Vdly__TopLayer__DOT__uart3__DOT__rx_state = 0U;
                } else {
                    __Vdly__TopLayer__DOT__uart3__DOT__rx_baud 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_baud)));
                }
            } else if ((0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_baud))) {
                __Vdly__TopLayer__DOT__uart3__DOT__rx_baud = 0U;
                vlSelfRef.TopLayer__DOT__uart3__DOT__rx_shift 
                    = (((~ ((IData)(1U) << (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_bit))) 
                        & (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_shift)) 
                       | (0xffU & ((IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_s2) 
                                   << (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_bit))));
                if ((7U == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_bit))) {
                    __Vdly__TopLayer__DOT__uart3__DOT__rx_state = 3U;
                } else {
                    __Vdly__TopLayer__DOT__uart3__DOT__rx_bit 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_bit)));
                }
            } else {
                __Vdly__TopLayer__DOT__uart3__DOT__rx_baud 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_baud)));
            }
        } else if ((1U & (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_state))) {
            if ((7U == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_baud))) {
                __Vdly__TopLayer__DOT__uart3__DOT__rx_baud = 0U;
                __Vdly__TopLayer__DOT__uart3__DOT__rx_state 
                    = ((IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_s2)
                        ? 0U : 2U);
            } else {
                __Vdly__TopLayer__DOT__uart3__DOT__rx_baud 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_baud)));
            }
        } else {
            __Vdly__TopLayer__DOT__uart3__DOT__rx_baud = 0U;
            __Vdly__TopLayer__DOT__uart3__DOT__rx_bit = 0U;
            if ((1U & (~ (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_s2)))) {
                __Vdly__TopLayer__DOT__uart3__DOT__rx_state = 1U;
            }
        }
        vlSelfRef.TopLayer__DOT__gpio_bank__DOT__sync1_d 
            = vlSelfRef.TopLayer__DOT__gpio_bank__DOT__sync1;
        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_csr_data_Reg 
            = vlSelfRef.TopLayer__DOT__cpu__DOT__EX_csr_result;
        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_csr_addr_Reg 
            = vlSelfRef.TopLayer__DOT__cpu__DOT__csr_addr;
        vlSelfRef.TopLayer__DOT__cpu__DOT__PC_decode 
            = vlSelfRef.TopLayer__DOT__cpu__DOT__PC;
        vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg 
            = vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode;
        vlSelfRef.TopLayer__DOT__gpio_bank__DOT__sync1 
            = vlSelfRef.TopLayer__DOT__gpio_bank__DOT__sync0;
        vlSelfRef.TopLayer__DOT__gpio_bank__DOT__sync0 
            = vlSelfRef.gpio_in;
    }
    vlSelfRef.TopLayer__DOT__cpu__DOT__flush_d = ((1U 
                                                   & (~ (IData)(vlSelfRef.rst))) 
                                                  && ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__take_trap) 
                                                      | ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__take_mret) 
                                                         | ((0x6fU 
                                                             == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode)) 
                                                            | ((0x67U 
                                                                == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode)) 
                                                               | ((0x63U 
                                                                   == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode)) 
                                                                  & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__branch_taken)))))));
    vlSelfRef.TopLayer__DOT__cpu__DOT__instret = __Vdly__TopLayer__DOT__cpu__DOT__instret;
    vlSelfRef.TopLayer__DOT__uart0__DOT__tx_wr = __Vdly__TopLayer__DOT__uart0__DOT__tx_wr;
    vlSelfRef.TopLayer__DOT__uart1__DOT__tx_wr = __Vdly__TopLayer__DOT__uart1__DOT__tx_wr;
    vlSelfRef.TopLayer__DOT__uart2__DOT__tx_wr = __Vdly__TopLayer__DOT__uart2__DOT__tx_wr;
    vlSelfRef.TopLayer__DOT__uart3__DOT__tx_wr = __Vdly__TopLayer__DOT__uart3__DOT__tx_wr;
    vlSelfRef.TopLayer__DOT__uart0__DOT__rx_rd = __Vdly__TopLayer__DOT__uart0__DOT__rx_rd;
    vlSelfRef.TopLayer__DOT__uart1__DOT__rx_rd = __Vdly__TopLayer__DOT__uart1__DOT__rx_rd;
    vlSelfRef.TopLayer__DOT__uart2__DOT__rx_rd = __Vdly__TopLayer__DOT__uart2__DOT__rx_rd;
    vlSelfRef.TopLayer__DOT__uart3__DOT__rx_rd = __Vdly__TopLayer__DOT__uart3__DOT__rx_rd;
    vlSelfRef.TopLayer__DOT__gpio_bank__DOT__data_out 
        = __Vdly__TopLayer__DOT__gpio_bank__DOT__data_out;
    vlSelfRef.TopLayer__DOT__mtime = __Vdly__TopLayer__DOT__mtime;
    vlSelfRef.TopLayer__DOT__uart0__DOT__rx_wr = __Vdly__TopLayer__DOT__uart0__DOT__rx_wr;
    if (__VdlySet__TopLayer__DOT__uart0__DOT__rxbuf__v0) {
        vlSelfRef.TopLayer__DOT__uart0__DOT__rxbuf[__VdlyDim0__TopLayer__DOT__uart0__DOT__rxbuf__v0] 
            = __VdlyVal__TopLayer__DOT__uart0__DOT__rxbuf__v0;
    }
    vlSelfRef.TopLayer__DOT__uart1__DOT__rx_wr = __Vdly__TopLayer__DOT__uart1__DOT__rx_wr;
    if (__VdlySet__TopLayer__DOT__uart1__DOT__rxbuf__v0) {
        vlSelfRef.TopLayer__DOT__uart1__DOT__rxbuf[__VdlyDim0__TopLayer__DOT__uart1__DOT__rxbuf__v0] 
            = __VdlyVal__TopLayer__DOT__uart1__DOT__rxbuf__v0;
    }
    vlSelfRef.TopLayer__DOT__uart2__DOT__rx_wr = __Vdly__TopLayer__DOT__uart2__DOT__rx_wr;
    if (__VdlySet__TopLayer__DOT__uart2__DOT__rxbuf__v0) {
        vlSelfRef.TopLayer__DOT__uart2__DOT__rxbuf[__VdlyDim0__TopLayer__DOT__uart2__DOT__rxbuf__v0] 
            = __VdlyVal__TopLayer__DOT__uart2__DOT__rxbuf__v0;
    }
    vlSelfRef.TopLayer__DOT__uart3__DOT__rx_wr = __Vdly__TopLayer__DOT__uart3__DOT__rx_wr;
    if (__VdlySet__TopLayer__DOT__uart3__DOT__rxbuf__v0) {
        vlSelfRef.TopLayer__DOT__uart3__DOT__rxbuf[__VdlyDim0__TopLayer__DOT__uart3__DOT__rxbuf__v0] 
            = __VdlyVal__TopLayer__DOT__uart3__DOT__rxbuf__v0;
    }
    vlSelfRef.TopLayer__DOT__uart0__DOT__rx_cnt = __Vdly__TopLayer__DOT__uart0__DOT__rx_cnt;
    vlSelfRef.TopLayer__DOT__uart1__DOT__rx_cnt = __Vdly__TopLayer__DOT__uart1__DOT__rx_cnt;
    vlSelfRef.TopLayer__DOT__uart2__DOT__rx_cnt = __Vdly__TopLayer__DOT__uart2__DOT__rx_cnt;
    vlSelfRef.TopLayer__DOT__uart3__DOT__rx_cnt = __Vdly__TopLayer__DOT__uart3__DOT__rx_cnt;
    if (__VdlySet__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v0) {
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[1U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[2U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[3U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[4U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[5U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[6U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[7U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[8U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[9U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0xaU] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0xbU] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0xcU] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0xdU] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0xeU] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0xfU] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0x10U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0x11U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0x12U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0x13U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0x14U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0x15U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0x16U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0x17U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0x18U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0x19U] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0x1aU] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0x1bU] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0x1cU] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0x1dU] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0x1eU] = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[0x1fU] = 0U;
    }
    if (__VdlySet__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v32) {
        vlSelfRef.TopLayer__DOT__cpu__DOT__registry__DOT__registers[__VdlyDim0__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v32] 
            = __VdlyVal__TopLayer__DOT__cpu__DOT__registry__DOT__registers__v32;
    }
    vlSelfRef.TopLayer__DOT__uart0__DOT__tx_rd = __Vdly__TopLayer__DOT__uart0__DOT__tx_rd;
    vlSelfRef.TopLayer__DOT__uart0__DOT__tx_baud = __Vdly__TopLayer__DOT__uart0__DOT__tx_baud;
    vlSelfRef.TopLayer__DOT__uart0__DOT__tx_bit = __Vdly__TopLayer__DOT__uart0__DOT__tx_bit;
    vlSelfRef.TopLayer__DOT__uart0__DOT__tx_shift = __Vdly__TopLayer__DOT__uart0__DOT__tx_shift;
    if (__VdlySet__TopLayer__DOT__uart0__DOT__txbuf__v0) {
        vlSelfRef.TopLayer__DOT__uart0__DOT__txbuf[__VdlyDim0__TopLayer__DOT__uart0__DOT__txbuf__v0] 
            = __VdlyVal__TopLayer__DOT__uart0__DOT__txbuf__v0;
    }
    vlSelfRef.TopLayer__DOT__uart0__DOT__tx_state = __Vdly__TopLayer__DOT__uart0__DOT__tx_state;
    vlSelfRef.TopLayer__DOT__uart0__DOT__tx_cnt = __Vdly__TopLayer__DOT__uart0__DOT__tx_cnt;
    vlSelfRef.TopLayer__DOT__uart1__DOT__tx_rd = __Vdly__TopLayer__DOT__uart1__DOT__tx_rd;
    vlSelfRef.TopLayer__DOT__uart1__DOT__tx_baud = __Vdly__TopLayer__DOT__uart1__DOT__tx_baud;
    vlSelfRef.TopLayer__DOT__uart1__DOT__tx_bit = __Vdly__TopLayer__DOT__uart1__DOT__tx_bit;
    vlSelfRef.TopLayer__DOT__uart1__DOT__tx_shift = __Vdly__TopLayer__DOT__uart1__DOT__tx_shift;
    if (__VdlySet__TopLayer__DOT__uart1__DOT__txbuf__v0) {
        vlSelfRef.TopLayer__DOT__uart1__DOT__txbuf[__VdlyDim0__TopLayer__DOT__uart1__DOT__txbuf__v0] 
            = __VdlyVal__TopLayer__DOT__uart1__DOT__txbuf__v0;
    }
    vlSelfRef.TopLayer__DOT__uart1__DOT__tx_state = __Vdly__TopLayer__DOT__uart1__DOT__tx_state;
    vlSelfRef.TopLayer__DOT__uart1__DOT__tx_cnt = __Vdly__TopLayer__DOT__uart1__DOT__tx_cnt;
    vlSelfRef.TopLayer__DOT__uart2__DOT__tx_rd = __Vdly__TopLayer__DOT__uart2__DOT__tx_rd;
    vlSelfRef.TopLayer__DOT__uart2__DOT__tx_baud = __Vdly__TopLayer__DOT__uart2__DOT__tx_baud;
    vlSelfRef.TopLayer__DOT__uart2__DOT__tx_bit = __Vdly__TopLayer__DOT__uart2__DOT__tx_bit;
    vlSelfRef.TopLayer__DOT__uart2__DOT__tx_shift = __Vdly__TopLayer__DOT__uart2__DOT__tx_shift;
    if (__VdlySet__TopLayer__DOT__uart2__DOT__txbuf__v0) {
        vlSelfRef.TopLayer__DOT__uart2__DOT__txbuf[__VdlyDim0__TopLayer__DOT__uart2__DOT__txbuf__v0] 
            = __VdlyVal__TopLayer__DOT__uart2__DOT__txbuf__v0;
    }
    vlSelfRef.TopLayer__DOT__uart2__DOT__tx_state = __Vdly__TopLayer__DOT__uart2__DOT__tx_state;
    vlSelfRef.TopLayer__DOT__uart2__DOT__tx_cnt = __Vdly__TopLayer__DOT__uart2__DOT__tx_cnt;
    vlSelfRef.TopLayer__DOT__uart3__DOT__tx_rd = __Vdly__TopLayer__DOT__uart3__DOT__tx_rd;
    vlSelfRef.TopLayer__DOT__uart3__DOT__tx_baud = __Vdly__TopLayer__DOT__uart3__DOT__tx_baud;
    vlSelfRef.TopLayer__DOT__uart3__DOT__tx_bit = __Vdly__TopLayer__DOT__uart3__DOT__tx_bit;
    vlSelfRef.TopLayer__DOT__uart3__DOT__tx_shift = __Vdly__TopLayer__DOT__uart3__DOT__tx_shift;
    if (__VdlySet__TopLayer__DOT__uart3__DOT__txbuf__v0) {
        vlSelfRef.TopLayer__DOT__uart3__DOT__txbuf[__VdlyDim0__TopLayer__DOT__uart3__DOT__txbuf__v0] 
            = __VdlyVal__TopLayer__DOT__uart3__DOT__txbuf__v0;
    }
    vlSelfRef.TopLayer__DOT__uart3__DOT__tx_state = __Vdly__TopLayer__DOT__uart3__DOT__tx_state;
    vlSelfRef.TopLayer__DOT__uart3__DOT__tx_cnt = __Vdly__TopLayer__DOT__uart3__DOT__tx_cnt;
    vlSelfRef.TopLayer__DOT__cpu__DOT__mstatus = __Vdly__TopLayer__DOT__cpu__DOT__mstatus;
    vlSelfRef.gpio_out = vlSelfRef.TopLayer__DOT__gpio_bank__DOT__data_out;
    vlSelfRef.TopLayer__DOT__uart0__DOT__rx_empty = 
        (0U == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_cnt));
    vlSelfRef.TopLayer__DOT__uart1__DOT__rx_empty = 
        (0U == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_cnt));
    vlSelfRef.TopLayer__DOT__uart2__DOT__rx_empty = 
        (0U == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_cnt));
    vlSelfRef.TopLayer__DOT__uart3__DOT__rx_empty = 
        (0U == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_cnt));
    vlSelfRef.TopLayer__DOT__uart0__DOT__tx_full = 
        (8U == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_cnt));
    vlSelfRef.TopLayer__DOT__uart0__DOT__tx_pop = (
                                                   (0U 
                                                    != (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_cnt)) 
                                                   & (0U 
                                                      == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_state)));
    vlSelfRef.TopLayer__DOT__uart0__DOT__tx_idle_empty 
        = ((0U == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_cnt)) 
           & (0U == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_state)));
    vlSelfRef.TopLayer__DOT__uart1__DOT__tx_full = 
        (8U == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_cnt));
    vlSelfRef.TopLayer__DOT__uart1__DOT__tx_pop = (
                                                   (0U 
                                                    != (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_cnt)) 
                                                   & (0U 
                                                      == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_state)));
    vlSelfRef.TopLayer__DOT__uart1__DOT__tx_idle_empty 
        = ((0U == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_cnt)) 
           & (0U == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_state)));
    vlSelfRef.TopLayer__DOT__uart2__DOT__tx_full = 
        (8U == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_cnt));
    vlSelfRef.TopLayer__DOT__uart2__DOT__tx_pop = (
                                                   (0U 
                                                    != (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_cnt)) 
                                                   & (0U 
                                                      == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_state)));
    vlSelfRef.TopLayer__DOT__uart2__DOT__tx_idle_empty 
        = ((0U == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_cnt)) 
           & (0U == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_state)));
    vlSelfRef.uart_tx = ((((IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_line) 
                           << 3U) | ((IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_line) 
                                     << 2U)) | (((IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_line) 
                                                 << 1U) 
                                                | (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_line)));
    vlSelfRef.TopLayer__DOT__uart3__DOT__tx_full = 
        (8U == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_cnt));
    vlSelfRef.TopLayer__DOT__uart3__DOT__tx_pop = (
                                                   (0U 
                                                    != (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_cnt)) 
                                                   & (0U 
                                                      == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_state)));
    vlSelfRef.TopLayer__DOT__uart3__DOT__tx_idle_empty 
        = ((0U == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_cnt)) 
           & (0U == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_state)));
    vlSelfRef.TopLayer__DOT__cpu__DOT__irq_soft = (1U 
                                                   & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mstatus 
                                                       >> 3U) 
                                                      & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mie 
                                                          >> 3U) 
                                                         & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mip 
                                                             >> 3U) 
                                                            | (IData)(vlSelfRef.TopLayer__DOT__msip)))));
    vlSelfRef.TopLayer__DOT__uart0__DOT__rx_bit = __Vdly__TopLayer__DOT__uart0__DOT__rx_bit;
    vlSelfRef.TopLayer__DOT__uart0__DOT__rx_state = __Vdly__TopLayer__DOT__uart0__DOT__rx_state;
    vlSelfRef.TopLayer__DOT__uart0__DOT__rx_baud = __Vdly__TopLayer__DOT__uart0__DOT__rx_baud;
    vlSelfRef.TopLayer__DOT__uart1__DOT__rx_bit = __Vdly__TopLayer__DOT__uart1__DOT__rx_bit;
    vlSelfRef.TopLayer__DOT__uart1__DOT__rx_state = __Vdly__TopLayer__DOT__uart1__DOT__rx_state;
    vlSelfRef.TopLayer__DOT__uart1__DOT__rx_baud = __Vdly__TopLayer__DOT__uart1__DOT__rx_baud;
    vlSelfRef.TopLayer__DOT__uart2__DOT__rx_bit = __Vdly__TopLayer__DOT__uart2__DOT__rx_bit;
    vlSelfRef.TopLayer__DOT__uart2__DOT__rx_state = __Vdly__TopLayer__DOT__uart2__DOT__rx_state;
    vlSelfRef.TopLayer__DOT__uart2__DOT__rx_baud = __Vdly__TopLayer__DOT__uart2__DOT__rx_baud;
    vlSelfRef.TopLayer__DOT__uart3__DOT__rx_bit = __Vdly__TopLayer__DOT__uart3__DOT__rx_bit;
    vlSelfRef.TopLayer__DOT__uart3__DOT__rx_state = __Vdly__TopLayer__DOT__uart3__DOT__rx_state;
    vlSelfRef.TopLayer__DOT__uart3__DOT__rx_baud = __Vdly__TopLayer__DOT__uart3__DOT__rx_baud;
    vlSelfRef.TopLayer__DOT__uart_irq0 = (((0U != (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_cnt)) 
                                           & (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__ier)) 
                                          | ((((IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__ier) 
                                               >> 1U) 
                                              & (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_idle_empty)) 
                                             | (((IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__ier) 
                                                 >> 2U) 
                                                & (8U 
                                                   == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_cnt)))));
    vlSelfRef.TopLayer__DOT__uart_irq1 = (((0U != (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_cnt)) 
                                           & (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__ier)) 
                                          | ((((IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__ier) 
                                               >> 1U) 
                                              & (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_idle_empty)) 
                                             | (((IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__ier) 
                                                 >> 2U) 
                                                & (8U 
                                                   == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_cnt)))));
    vlSelfRef.TopLayer__DOT__uart_irq2 = (((0U != (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_cnt)) 
                                           & (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__ier)) 
                                          | ((((IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__ier) 
                                               >> 1U) 
                                              & (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_idle_empty)) 
                                             | (((IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__ier) 
                                                 >> 2U) 
                                                & (8U 
                                                   == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_cnt)))));
    vlSelfRef.TopLayer__DOT__uart_irq3 = (((0U != (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_cnt)) 
                                           & (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__ier)) 
                                          | ((((IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__ier) 
                                               >> 1U) 
                                              & (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_idle_empty)) 
                                             | (((IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__ier) 
                                                 >> 2U) 
                                                & (8U 
                                                   == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_cnt)))));
    vlSelfRef.TopLayer__DOT__uart0__DOT__rx_push = 
        ((3U == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_state)) 
         & ((8U != (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_cnt)) 
            & (0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_baud))));
    vlSelfRef.TopLayer__DOT__uart0__DOT__rx_s2 = ((IData)(vlSelfRef.rst) 
                                                  || (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_s1));
    vlSelfRef.TopLayer__DOT__uart1__DOT__rx_push = 
        ((3U == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_state)) 
         & ((8U != (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_cnt)) 
            & (0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_baud))));
    vlSelfRef.TopLayer__DOT__uart1__DOT__rx_s2 = ((IData)(vlSelfRef.rst) 
                                                  || (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_s1));
    vlSelfRef.TopLayer__DOT__uart2__DOT__rx_push = 
        ((3U == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_state)) 
         & ((8U != (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_cnt)) 
            & (0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_baud))));
    vlSelfRef.TopLayer__DOT__uart2__DOT__rx_s2 = ((IData)(vlSelfRef.rst) 
                                                  || (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_s1));
    vlSelfRef.TopLayer__DOT__uart3__DOT__rx_push = 
        ((3U == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_state)) 
         & ((8U != (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_cnt)) 
            & (0xfU == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_baud))));
    vlSelfRef.TopLayer__DOT__uart3__DOT__rx_s2 = ((IData)(vlSelfRef.rst) 
                                                  || (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_s1));
    vlSelfRef.TopLayer__DOT__cpu__DOT__irq_ext = (1U 
                                                  & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mstatus 
                                                      >> 3U) 
                                                     & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mie 
                                                         >> 0xbU) 
                                                        & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mip 
                                                            >> 0xbU) 
                                                           | ((0U 
                                                               != vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_pending) 
                                                              | ((IData)(vlSelfRef.irq_external) 
                                                                 | ((IData)(vlSelfRef.TopLayer__DOT__uart_irq0) 
                                                                    | ((IData)(vlSelfRef.TopLayer__DOT__uart_irq1) 
                                                                       | ((IData)(vlSelfRef.TopLayer__DOT__uart_irq2) 
                                                                          | (IData)(vlSelfRef.TopLayer__DOT__uart_irq3))))))))));
    vlSelfRef.TopLayer__DOT__cpu__DOT__WB_write_enable 
        = ((0U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg)) 
           || ((1U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg)) 
               || (2U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg))));
    vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_addr = 0U;
    if ((0U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg))) {
        vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_addr 
            = vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_rd_addr_Reg;
    } else if ((1U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg))) {
        vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_addr 
            = vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_rd_addr_Reg;
    } else if ((2U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg))) {
        vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_addr 
            = vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_rd_addr_Reg;
    }
    vlSelfRef.TopLayer__DOT__cpu__DOT__wb_write_gpr 
        = ((3U != (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg)) 
           & (0U != (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_rd_addr_Reg)));
    vlSelfRef.TopLayer__DOT__cpu__DOT__irq_ready = 
        (1U & ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__irq_ext) 
               | ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__irq_soft) 
                  | ((vlSelfRef.TopLayer__DOT__cpu__DOT__mstatus 
                      >> 3U) & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mie 
                                 >> 7U) & ((vlSelfRef.TopLayer__DOT__cpu__DOT__mip 
                                            >> 7U) 
                                           | (vlSelfRef.TopLayer__DOT__mtime 
                                              >= vlSelfRef.TopLayer__DOT__mtimecmp)))))));
    vlSelfRef.TopLayer__DOT__uart0__DOT__rx_s1 = ((IData)(vlSelfRef.rst) 
                                                  || (1U 
                                                      & (IData)(vlSelfRef.uart_rx)));
    vlSelfRef.TopLayer__DOT__uart1__DOT__rx_s1 = ((IData)(vlSelfRef.rst) 
                                                  || (1U 
                                                      & ((IData)(vlSelfRef.uart_rx) 
                                                         >> 1U)));
    vlSelfRef.TopLayer__DOT__uart2__DOT__rx_s1 = ((IData)(vlSelfRef.rst) 
                                                  || (1U 
                                                      & ((IData)(vlSelfRef.uart_rx) 
                                                         >> 2U)));
    vlSelfRef.TopLayer__DOT__uart3__DOT__rx_s1 = ((IData)(vlSelfRef.rst) 
                                                  || (1U 
                                                      & ((IData)(vlSelfRef.uart_rx) 
                                                         >> 3U)));
}

VL_INLINE_OPT void VTopLayer___024root___nba_sequent__TOP__1(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___nba_sequent__TOP__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v0;
    __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v0 = 0;
    SData/*15:0*/ __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v0;
    __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v0 = 0;
    CData/*0:0*/ __VdlySet__TopLayer__DOT__bram__DOT__Mem__v0;
    __VdlySet__TopLayer__DOT__bram__DOT__Mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v1;
    __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v1 = 0;
    SData/*15:0*/ __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v1;
    __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v1 = 0;
    CData/*0:0*/ __VdlySet__TopLayer__DOT__bram__DOT__Mem__v1;
    __VdlySet__TopLayer__DOT__bram__DOT__Mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v2;
    __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v2 = 0;
    SData/*15:0*/ __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v2;
    __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v3;
    __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v3 = 0;
    SData/*15:0*/ __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v3;
    __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v3 = 0;
    CData/*0:0*/ __VdlySet__TopLayer__DOT__bram__DOT__Mem__v3;
    __VdlySet__TopLayer__DOT__bram__DOT__Mem__v3 = 0;
    CData/*7:0*/ __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v4;
    __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v4 = 0;
    SData/*15:0*/ __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v4;
    __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v4 = 0;
    CData/*7:0*/ __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v5;
    __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v5 = 0;
    SData/*15:0*/ __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v5;
    __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v5 = 0;
    CData/*7:0*/ __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v6;
    __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v6 = 0;
    SData/*15:0*/ __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v6;
    __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v6 = 0;
    // Body
    __VdlySet__TopLayer__DOT__bram__DOT__Mem__v0 = 0U;
    __VdlySet__TopLayer__DOT__bram__DOT__Mem__v1 = 0U;
    __VdlySet__TopLayer__DOT__bram__DOT__Mem__v3 = 0U;
    if ((0U == (IData)(vlSelfRef.TopLayer__DOT__bram_write_mode))) {
        __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v0 
            = (0xffU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in);
        __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v0 
            = (0xffffU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr);
        __VdlySet__TopLayer__DOT__bram__DOT__Mem__v0 = 1U;
    } else if ((1U == (IData)(vlSelfRef.TopLayer__DOT__bram_write_mode))) {
        __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v1 
            = (0xffU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in);
        __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v1 
            = (0xffffU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr);
        __VdlySet__TopLayer__DOT__bram__DOT__Mem__v1 = 1U;
        __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v2 
            = (0xffU & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in 
                        >> 8U));
        __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v2 
            = (0xffffU & ((IData)(1U) + vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr));
    } else if ((2U == (IData)(vlSelfRef.TopLayer__DOT__bram_write_mode))) {
        __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v3 
            = (0xffU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in);
        __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v3 
            = (0xffffU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr);
        __VdlySet__TopLayer__DOT__bram__DOT__Mem__v3 = 1U;
        __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v4 
            = (0xffU & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in 
                        >> 8U));
        __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v4 
            = (0xffffU & ((IData)(1U) + vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr));
        __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v5 
            = (0xffU & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in 
                        >> 0x10U));
        __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v5 
            = (0xffffU & ((IData)(2U) + vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr));
        __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v6 
            = (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in 
               >> 0x18U);
        __VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v6 
            = (0xffffU & ((IData)(3U) + vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr));
    }
    vlSelfRef.TopLayer__DOT__mmio_read_data_q = vlSelfRef.TopLayer__DOT__mmio_read_data;
    vlSelfRef.TopLayer__DOT__read_was_mmio = (0xffffffU 
                                              == (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                  >> 8U));
    vlSelfRef.TopLayer__DOT__bram_data_out = ((0U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_load_mode))
                                               ? ((
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlSelfRef.TopLayer__DOT__bram__DOT__Mem
                                                                  [
                                                                  (0xffffU 
                                                                   & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)] 
                                                                  >> 7U)))) 
                                                   << 8U) 
                                                  | vlSelfRef.TopLayer__DOT__bram__DOT__Mem
                                                  [
                                                  (0xffffU 
                                                   & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)])
                                               : ((1U 
                                                   == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_load_mode))
                                                   ? 
                                                  (((- (IData)(
                                                               (1U 
                                                                & (vlSelfRef.TopLayer__DOT__bram__DOT__Mem
                                                                   [
                                                                   (0xffffU 
                                                                    & ((IData)(1U) 
                                                                       + vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr))] 
                                                                   >> 7U)))) 
                                                    << 0x10U) 
                                                   | ((vlSelfRef.TopLayer__DOT__bram__DOT__Mem
                                                       [
                                                       (0xffffU 
                                                        & ((IData)(1U) 
                                                           + vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr))] 
                                                       << 8U) 
                                                      | vlSelfRef.TopLayer__DOT__bram__DOT__Mem
                                                      [
                                                      (0xffffU 
                                                       & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)]))
                                                   : 
                                                  ((2U 
                                                    == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_load_mode))
                                                    ? 
                                                   (((vlSelfRef.TopLayer__DOT__bram__DOT__Mem
                                                      [
                                                      (0xffffU 
                                                       & ((IData)(3U) 
                                                          + vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr))] 
                                                      << 0x18U) 
                                                     | (vlSelfRef.TopLayer__DOT__bram__DOT__Mem
                                                        [
                                                        (0xffffU 
                                                         & ((IData)(2U) 
                                                            + vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr))] 
                                                        << 0x10U)) 
                                                    | ((vlSelfRef.TopLayer__DOT__bram__DOT__Mem
                                                        [
                                                        (0xffffU 
                                                         & ((IData)(1U) 
                                                            + vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr))] 
                                                        << 8U) 
                                                       | vlSelfRef.TopLayer__DOT__bram__DOT__Mem
                                                       [
                                                       (0xffffU 
                                                        & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)]))
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_load_mode))
                                                     ? 
                                                    vlSelfRef.TopLayer__DOT__bram__DOT__Mem
                                                    [
                                                    (0xffffU 
                                                     & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)]
                                                     : 
                                                    ((5U 
                                                      == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_load_mode))
                                                      ? 
                                                     ((vlSelfRef.TopLayer__DOT__bram__DOT__Mem
                                                       [
                                                       (0xffffU 
                                                        & ((IData)(1U) 
                                                           + vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr))] 
                                                       << 8U) 
                                                      | vlSelfRef.TopLayer__DOT__bram__DOT__Mem
                                                      [
                                                      (0xffffU 
                                                       & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)])
                                                      : 0U)))));
    vlSelfRef.TopLayer__DOT__mem_instruction = (((vlSelfRef.TopLayer__DOT__bram__DOT__Mem
                                                  [
                                                  (0xffffU 
                                                   & ((IData)(3U) 
                                                      + vlSelfRef.TopLayer__DOT__cpu__DOT__PC))] 
                                                  << 0x18U) 
                                                 | (vlSelfRef.TopLayer__DOT__bram__DOT__Mem
                                                    [
                                                    (0xffffU 
                                                     & ((IData)(2U) 
                                                        + vlSelfRef.TopLayer__DOT__cpu__DOT__PC))] 
                                                    << 0x10U)) 
                                                | ((vlSelfRef.TopLayer__DOT__bram__DOT__Mem
                                                    [
                                                    (0xffffU 
                                                     & ((IData)(1U) 
                                                        + vlSelfRef.TopLayer__DOT__cpu__DOT__PC))] 
                                                    << 8U) 
                                                   | vlSelfRef.TopLayer__DOT__bram__DOT__Mem
                                                   [
                                                   (0xffffU 
                                                    & vlSelfRef.TopLayer__DOT__cpu__DOT__PC)]));
    if (__VdlySet__TopLayer__DOT__bram__DOT__Mem__v0) {
        vlSelfRef.TopLayer__DOT__bram__DOT__Mem[__VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v0] 
            = __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v0;
    }
    if (__VdlySet__TopLayer__DOT__bram__DOT__Mem__v1) {
        vlSelfRef.TopLayer__DOT__bram__DOT__Mem[__VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v1] 
            = __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v1;
        vlSelfRef.TopLayer__DOT__bram__DOT__Mem[__VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v2] 
            = __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v2;
    }
    if (__VdlySet__TopLayer__DOT__bram__DOT__Mem__v3) {
        vlSelfRef.TopLayer__DOT__bram__DOT__Mem[__VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v3] 
            = __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v3;
        vlSelfRef.TopLayer__DOT__bram__DOT__Mem[__VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v4] 
            = __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v4;
        vlSelfRef.TopLayer__DOT__bram__DOT__Mem[__VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v5] 
            = __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v5;
        vlSelfRef.TopLayer__DOT__bram__DOT__Mem[__VdlyDim0__TopLayer__DOT__bram__DOT__Mem__v6] 
            = __VdlyVal__TopLayer__DOT__bram__DOT__Mem__v6;
    }
    vlSelfRef.TopLayer__DOT__mem_data_out = ((IData)(vlSelfRef.TopLayer__DOT__read_was_mmio)
                                              ? vlSelfRef.TopLayer__DOT__mmio_read_data_q
                                              : vlSelfRef.TopLayer__DOT__bram_data_out);
}

VL_INLINE_OPT void VTopLayer___024root___nba_sequent__TOP__2(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___nba_sequent__TOP__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.TopLayer__DOT__cpu__DOT__PC = ((IData)(vlSelfRef.rst)
                                              ? 0U : vlSelfRef.TopLayer__DOT__cpu__DOT__next_PC);
}

extern const VlUnpacked<CData/*0:0*/, 512> VTopLayer__ConstPool__TABLE_hf586ed68_0;

VL_INLINE_OPT void VTopLayer___024root___nba_comb__TOP__0(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___nba_comb__TOP__0\n"); );
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
    TopLayer__DOT__cpu__DOT__imm_u = (((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__flush_d)
                                        ? 0U : (vlSelfRef.TopLayer__DOT__mem_instruction 
                                                >> 0xcU)) 
                                      << 0xcU);
    if (vlSelfRef.TopLayer__DOT__cpu__DOT__flush_d) {
        vlSelfRef.TopLayer__DOT__cpu__DOT__BRAMInstruction = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__rd_addr = 0U;
        TopLayer__DOT__cpu__DOT__rs2_addr = 0U;
        TopLayer__DOT__cpu__DOT__rs1_addr = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__funct3 = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__opcode = 0U;
        vlSelfRef.TopLayer__DOT__cpu__DOT__csr_addr = 0U;
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
        vlSelfRef.TopLayer__DOT__cpu__DOT__funct3 = 
            (7U & (vlSelfRef.TopLayer__DOT__mem_instruction 
                   >> 0xcU));
        vlSelfRef.TopLayer__DOT__cpu__DOT__opcode = 
            (0x7fU & vlSelfRef.TopLayer__DOT__mem_instruction);
        vlSelfRef.TopLayer__DOT__cpu__DOT__csr_addr 
            = (vlSelfRef.TopLayer__DOT__mem_instruction 
               >> 0x14U);
    }
    vlSelfRef.TopLayer__DOT__cpu__DOT____VdfgRegularize_h0c4dd555_2_3 
        = ((~ (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__flush_d)) 
           & (vlSelfRef.TopLayer__DOT__mem_instruction 
              >> 0x1fU));
    vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_data = 0U;
    if ((0U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg))) {
        vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_data 
            = vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_Result_Reg;
    } else if ((1U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg))) {
        vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_data 
            = vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_Result_Reg;
    } else if ((2U == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg))) {
        vlSelfRef.TopLayer__DOT__cpu__DOT__WB_rd_data 
            = vlSelfRef.TopLayer__DOT__mem_data_out;
    }
    TopLayer__DOT__cpu__DOT__wb_forward_data = ((2U 
                                                 == (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_mode_Reg))
                                                 ? vlSelfRef.TopLayer__DOT__mem_data_out
                                                 : vlSelfRef.TopLayer__DOT__cpu__DOT__toWB_Result_Reg);
    TopLayer__DOT__cpu__DOT____VdfgExtracted_h7dc3c957__0 
        = ((8U & (((~ (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__flush_d)) 
                   << 3U) & (vlSelfRef.TopLayer__DOT__mem_instruction 
                             >> 0x1bU))) | (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__funct3));
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
    TopLayer__DOT__cpu__DOT__alu_control = 0U;
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
                    }
                }
            }
        }
    }
    vlSelfRef.TopLayer__DOT__gpio_bank__DOT__write_mask 
        = (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_data_in 
           & vlSelfRef.TopLayer__DOT__gpio_bank__DOT__dir);
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
        } else if ((0x10U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.TopLayer__DOT__cpu__DOT__opcode))) {
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
    vlSelfRef.TopLayer__DOT__mmio_read_data = ((8U 
                                                >= 
                                                (0x3fU 
                                                 & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                    >> 2U)))
                                                ? (
                                                   (0x20U 
                                                    & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                    ? 
                                                   ((0x10U 
                                                     & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                     ? 0U
                                                     : 
                                                    ((8U 
                                                      & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                       ? 0U
                                                       : vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_pending)))
                                                    : 
                                                   ((0x10U 
                                                     & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                     ? 
                                                    ((8U 
                                                      & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                      ? 
                                                     ((4U 
                                                       & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                       ? vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_fall_en
                                                       : vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_rise_en)
                                                      : 
                                                     ((4U 
                                                       & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                       ? vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_enable
                                                       : 0U))
                                                     : 
                                                    ((8U 
                                                      & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                      ? 
                                                     ((4U 
                                                       & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                       ? 0U
                                                       : vlSelfRef.TopLayer__DOT__gpio_bank__DOT__dir)
                                                      : 
                                                     ((4U 
                                                       & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                       ? vlSelfRef.TopLayer__DOT__gpio_bank__DOT__data_out
                                                       : vlSelfRef.TopLayer__DOT__gpio_bank__DOT__sync1))))
                                                : (
                                                   ((0x10U 
                                                     <= 
                                                     (0x3fU 
                                                      & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                         >> 2U))) 
                                                    & (0x1fU 
                                                       >= 
                                                       (0x3fU 
                                                        & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                           >> 2U))))
                                                    ? 
                                                   ((0x80U 
                                                     & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                     ? 0U
                                                     : 
                                                    ((0x40U 
                                                      & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                      ? 
                                                     ((0x20U 
                                                       & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                       ? 
                                                      ((0x10U 
                                                        & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                        ? 
                                                       ((1U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                             >> 2U)))
                                                         ? 
                                                        ((((8U 
                                                            == (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_cnt)) 
                                                           << 3U) 
                                                          | ((0U 
                                                              != (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__rx_cnt)) 
                                                             << 2U)) 
                                                         | (((IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_idle_empty) 
                                                             << 1U) 
                                                            | (8U 
                                                               != (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__tx_cnt))))
                                                         : 
                                                        ((2U 
                                                          == 
                                                          (3U 
                                                           & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                              >> 2U)))
                                                          ? (IData)(vlSelfRef.TopLayer__DOT__uart3__DOT__ier)
                                                          : 
                                                         vlSelfRef.TopLayer__DOT__uart3__DOT__rxbuf
                                                         [vlSelfRef.TopLayer__DOT__uart3__DOT__rx_rd]))
                                                        : 
                                                       ((1U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                             >> 2U)))
                                                         ? 
                                                        ((((8U 
                                                            == (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_cnt)) 
                                                           << 3U) 
                                                          | ((0U 
                                                              != (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__rx_cnt)) 
                                                             << 2U)) 
                                                         | (((IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_idle_empty) 
                                                             << 1U) 
                                                            | (8U 
                                                               != (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__tx_cnt))))
                                                         : 
                                                        ((2U 
                                                          == 
                                                          (3U 
                                                           & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                              >> 2U)))
                                                          ? (IData)(vlSelfRef.TopLayer__DOT__uart2__DOT__ier)
                                                          : 
                                                         vlSelfRef.TopLayer__DOT__uart2__DOT__rxbuf
                                                         [vlSelfRef.TopLayer__DOT__uart2__DOT__rx_rd])))
                                                       : 
                                                      ((0x10U 
                                                        & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)
                                                        ? 
                                                       ((1U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                             >> 2U)))
                                                         ? 
                                                        ((((8U 
                                                            == (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_cnt)) 
                                                           << 3U) 
                                                          | ((0U 
                                                              != (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__rx_cnt)) 
                                                             << 2U)) 
                                                         | (((IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_idle_empty) 
                                                             << 1U) 
                                                            | (8U 
                                                               != (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__tx_cnt))))
                                                         : 
                                                        ((2U 
                                                          == 
                                                          (3U 
                                                           & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                              >> 2U)))
                                                          ? (IData)(vlSelfRef.TopLayer__DOT__uart1__DOT__ier)
                                                          : 
                                                         vlSelfRef.TopLayer__DOT__uart1__DOT__rxbuf
                                                         [vlSelfRef.TopLayer__DOT__uart1__DOT__rx_rd]))
                                                        : 
                                                       ((1U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                             >> 2U)))
                                                         ? 
                                                        ((((8U 
                                                            == (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_cnt)) 
                                                           << 3U) 
                                                          | ((0U 
                                                              != (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__rx_cnt)) 
                                                             << 2U)) 
                                                         | (((IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_idle_empty) 
                                                             << 1U) 
                                                            | (8U 
                                                               != (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__tx_cnt))))
                                                         : 
                                                        ((2U 
                                                          == 
                                                          (3U 
                                                           & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                              >> 2U)))
                                                          ? (IData)(vlSelfRef.TopLayer__DOT__uart0__DOT__ier)
                                                          : 
                                                         vlSelfRef.TopLayer__DOT__uart0__DOT__rxbuf
                                                         [vlSelfRef.TopLayer__DOT__uart0__DOT__rx_rd]))))
                                                      : 0U))
                                                    : 
                                                   ((0x28U 
                                                     == 
                                                     (0x3fU 
                                                      & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr 
                                                         >> 2U)))
                                                     ? 
                                                    ((((IData)(vlSelfRef.TopLayer__DOT__uart_irq3) 
                                                       << 4U) 
                                                      | (((IData)(vlSelfRef.TopLayer__DOT__uart_irq2) 
                                                          << 3U) 
                                                         | ((IData)(vlSelfRef.TopLayer__DOT__uart_irq1) 
                                                            << 2U))) 
                                                     | (((IData)(vlSelfRef.TopLayer__DOT__uart_irq0) 
                                                         << 1U) 
                                                        | (0U 
                                                           != vlSelfRef.TopLayer__DOT__gpio_bank__DOT__int_pending)))
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
                                                      : 0U))));
    vlSelfRef.TopLayer__DOT__gpio_we = ((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
                                        & (8U >= (0x3fU 
                                                  & (vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr 
                                                     >> 2U))));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart0__wr_en 
        = ((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
           & (0x40U == (0xfcU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart1__wr_en 
        = ((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
           & (0x50U == (0xfcU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart2__wr_en 
        = ((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
           & (0x60U == (0xfcU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart3__wr_en 
        = ((IData)(vlSelfRef.TopLayer__DOT__mmio_write_en) 
           & (0x70U == (0xfcU & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_write_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart0__rd_data_en 
        = ((IData)(TopLayer__DOT__mmio_read_en) & (0x40U 
                                                   == 
                                                   (0xfcU 
                                                    & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart1__rd_data_en 
        = ((IData)(TopLayer__DOT__mmio_read_en) & (0x50U 
                                                   == 
                                                   (0xfcU 
                                                    & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart2__rd_data_en 
        = ((IData)(TopLayer__DOT__mmio_read_en) & (0x60U 
                                                   == 
                                                   (0xfcU 
                                                    & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)));
    vlSelfRef.TopLayer__DOT____Vcellinp__uart3__rd_data_en 
        = ((IData)(TopLayer__DOT__mmio_read_en) & (0x70U 
                                                   == 
                                                   (0xfcU 
                                                    & vlSelfRef.TopLayer__DOT__cpu__DOT__BRAM_read_addr)));
}

void VTopLayer___024root___eval_triggers__act(VTopLayer___024root* vlSelf);

bool VTopLayer___024root___eval_phase__act(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VTopLayer___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VTopLayer___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VTopLayer___024root___eval_phase__nba(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VTopLayer___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTopLayer___024root___dump_triggers__ico(VTopLayer___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTopLayer___024root___dump_triggers__nba(VTopLayer___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTopLayer___024root___dump_triggers__act(VTopLayer___024root* vlSelf);
#endif  // VL_DEBUG

void VTopLayer___024root___eval(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            VTopLayer___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("TopLayer.v", 44, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VTopLayer___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VTopLayer___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("TopLayer.v", 44, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                VTopLayer___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("TopLayer.v", 44, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VTopLayer___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VTopLayer___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VTopLayer___024root___eval_debug_assertions(VTopLayer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VTopLayer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLayer___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelfRef.irq_external & 0xfeU))) {
        Verilated::overWidthError("irq_external");}
    if (VL_UNLIKELY((vlSelfRef.uart_rx & 0xf0U))) {
        Verilated::overWidthError("uart_rx");}
}
#endif  // VL_DEBUG
