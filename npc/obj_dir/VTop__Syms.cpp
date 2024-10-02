// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VTop__Syms.h"
#include "VTop.h"
#include "VTop___024root.h"

void VTop___024root____Vdpiexp_Top__DOT__inst_memory__DOT__pc_read_TOP(VTop__Syms* __restrict vlSymsp, IData/*31:0*/ &pc_read__Vfuncrtn);

// FUNCTIONS
VTop__Syms::~VTop__Syms()
{
}

VTop__Syms::VTop__Syms(VerilatedContext* contextp, const char* namep, VTop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_Top__inst_memory.configure(this, name(), "Top.inst_memory", "inst_memory", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_Top__memory.configure(this, name(), "Top.memory", "memory", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_Top__terminate.configure(this, name(), "Top.terminate", "terminate", -12, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_Top__inst_memory.exportInsert(__Vfinal, "pc_read", (void*)(&VTop___024root____Vdpiexp_Top__DOT__inst_memory__DOT__pc_read_TOP));
    }
}
