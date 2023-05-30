#pragma once
#include "ASTNode.h"
#include "Ir.h"
#include<vector>

class Body {
public:
    std::vector<ASTNode*> nodes;

    void show() {
        for(auto& node: this->nodes) {
            node->show();
        }
    }

    void eval(EvalContext& ctx) {
        for(auto node: this->nodes) {
            (*node).eval(ctx);
        }
    }

    void gen(std::vector<Ir>& buf) {
        for(auto node: this->nodes) {
            (*node).gen(buf);
        }
    }
};