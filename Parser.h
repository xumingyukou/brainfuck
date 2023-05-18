#pragma once

#include "Lexer.h"
#include "Program.h"
#include "Body.h"
#include "ASTNode.h"

class Parser {
public:
    Lexer lx;

    Parser(Lexer lx) {
        this->lx = lx;
    }

    Program program();
};