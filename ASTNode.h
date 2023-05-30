#pragma once
#include "header.h"
#include "Ir.h"
#include<stdio.h>
#include<iostream>
#include<vector>

class Body;

class ASTNode {
public:
    ASTNodeType type;
    TokenKind::Type val;
    Body* body;

    ASTNode(){};
    ASTNode(ASTNodeType type, TokenKind::Type val, Body* body): type(type), val(val), body(body){};

    void show();
    void eval(EvalContext& ctx);
    void gen(std::vector<Ir>& buf);

};
