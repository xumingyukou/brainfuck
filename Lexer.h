#include "Token.h"
#include<string>


class Lexer {
public:
    int         current;
    std::string code;

    Lexer(std::string str) {
        this->current = 0;
        this->code = str;
    }

    Token next() {
        if(current == code.size()) {
            return Token(Eof, ' ');
        }
        const char op = code[current++];

        switch (op)
        {
        case '+':
            return Token(ADD, op);
            break;
        case '-':
            return Token(SUB, op);
            break;
        case '>':
            return Token(MOVERIGHT, op);
            break;
        case '<':
            return Token(MOVELEFT, op);
            break;
        case '.':
            return Token(READ, op);
            break;
        case ',':
            return Token(WRITE, op);
            break;
        case '[':
            return Token(LOOPBEGIN, op);
            break;
        case ']':
            return Token(LOOPEND, op);
            break;
        default:
            break;
        }

    }
};