#pragma once

#include "Token.h"
#include<string>


class Lexer {
public:
    int         current;
    std::string code;

    Lexer(){}
    Lexer(std::string str) {
        this->current = 0;
        this->code = str;
    }

    Token next() {
        if(current == code.size()) {
            return Token(TokenKind::Eof, ' ');
        }
        const char op = code[current++];

        switch (op)
        {
        case '+':
            return Token(TokenKind::ADD, op);
            break;
        case '-':
            return Token(TokenKind::SUB, op);
            break;
        case '>':
            return Token(TokenKind::MOVERIGHT, op);
            break;
        case '<':
            return Token(TokenKind::MOVELEFT, op);
            break;
        case '.':
            return Token(TokenKind::READ, op);
            break;
        case ',':
            return Token(TokenKind::WRITE, op);
            break;
        case '[':
            return Token(TokenKind::LOOPBEGIN, op);
            break;
        case ']':
            return Token(TokenKind::LOOPEND, op);
            break;
        default:
            break;
        }

    }
};