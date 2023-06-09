#pragma once

#include "header.h"
#include<iostream>

class Token {
public:
    TokenKind::Type tk;
    char val;

    Token(TokenKind::Type tk, char val): tk(tk), val(val){}

    friend std::ostream& operator<<(std::ostream& os, const Token& tk) {
        os << "Token(ty=<TokenKind." << tk.tk << ">, val = " << tk.val << ")" << std::endl;
        return os;
    }
};

