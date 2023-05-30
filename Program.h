#pragma once
#include "Body.h"
#include "Ir.h"
#include<vector>

class Program {
public:
    Body* body;

    Program() {
        this->body = new Body;
    }
    Program(Body* body) {
        this->body = body;
    }
    
    void show() {
        this->body->show();
    }

    void eval(EvalContext& ctx) {
        this->body->eval(ctx);
    }

    void gen(std::vector<Ir>& buf) {
        this->body->gen(buf);
        buf.push_back(Ir(IrOpCode::Halt, 0));
    }
};