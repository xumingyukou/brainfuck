#pragma once
#include "ASTNode.h"
#include<vector>

class Body {
public:
    std::vector<ASTNode*> nodes;

    void show() {
        for(auto& node: this->nodes) {
            node->show();
        }
    }
};