#pragma once

#include "header.h"

class Ir {
public:
    IrOpCode::Type op;
    int val;

    Ir(IrOpCode::Type _op, int i): op(_op), val(i) {}

    // friend std::ostream& operator<<(std::ostream& os, const Ir& ir) {
    //     os << "Ir(op=<IrOpCode." << ir.op << ">, val = " << ir.val << ")" << std::endl;
    //     return os;
    // }
};

void ir_eval(std::vector<Ir>& buf, EvalContext& ctx);