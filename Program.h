#pragma once
#include "Body.h"

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
};