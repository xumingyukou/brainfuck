#pragma once
#include "header.h"
#include<stdio.h>
#include<iostream>

class Body;

class ASTNode {
public:
    ASTNodeType type;
    TokenKind val;
    Body* body;

    ASTNode(){};
    ASTNode(ASTNodeType type, TokenKind val, Body* body): type(type), val(val), body(body){};

    void show();
    void eval(EvalContext& ctx);

};
