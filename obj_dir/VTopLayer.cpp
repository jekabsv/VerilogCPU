// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VTopLayer__pch.h"

//============================================================
// Constructors

VTopLayer::VTopLayer(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VTopLayer__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , irq_external{vlSymsp->TOP.irq_external}
    , uart_rx{vlSymsp->TOP.uart_rx}
    , uart_tx{vlSymsp->TOP.uart_tx}
    , gpio_in{vlSymsp->TOP.gpio_in}
    , gpio_out{vlSymsp->TOP.gpio_out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VTopLayer::VTopLayer(const char* _vcname__)
    : VTopLayer(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VTopLayer::~VTopLayer() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VTopLayer___024root___eval_debug_assertions(VTopLayer___024root* vlSelf);
#endif  // VL_DEBUG
void VTopLayer___024root___eval_static(VTopLayer___024root* vlSelf);
void VTopLayer___024root___eval_initial(VTopLayer___024root* vlSelf);
void VTopLayer___024root___eval_settle(VTopLayer___024root* vlSelf);
void VTopLayer___024root___eval(VTopLayer___024root* vlSelf);

void VTopLayer::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VTopLayer::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VTopLayer___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VTopLayer___024root___eval_static(&(vlSymsp->TOP));
        VTopLayer___024root___eval_initial(&(vlSymsp->TOP));
        VTopLayer___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VTopLayer___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VTopLayer::eventsPending() { return false; }

uint64_t VTopLayer::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VTopLayer::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VTopLayer___024root___eval_final(VTopLayer___024root* vlSelf);

VL_ATTR_COLD void VTopLayer::final() {
    VTopLayer___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VTopLayer::hierName() const { return vlSymsp->name(); }
const char* VTopLayer::modelName() const { return "VTopLayer"; }
unsigned VTopLayer::threads() const { return 1; }
void VTopLayer::prepareClone() const { contextp()->prepareClone(); }
void VTopLayer::atClone() const {
    contextp()->threadPoolpOnClone();
}
