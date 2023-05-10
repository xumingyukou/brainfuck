#pragma once

#include "header.h"

class Token {
public:
    TokenKind tk;
    char val;

    Token(TokenKind tk, char val): tk(tk), val(val){}
};

