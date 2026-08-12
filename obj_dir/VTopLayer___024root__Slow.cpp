// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTopLayer.h for the primary calling header

#include "VTopLayer__pch.h"
#include "VTopLayer__Syms.h"
#include "VTopLayer___024root.h"

void VTopLayer___024root___ctor_var_reset(VTopLayer___024root* vlSelf);

VTopLayer___024root::VTopLayer___024root(VTopLayer__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTopLayer___024root___ctor_var_reset(this);
}

void VTopLayer___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VTopLayer___024root::~VTopLayer___024root() {
}
