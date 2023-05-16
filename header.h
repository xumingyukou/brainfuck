#pragma once

#include<string>

enum TokenKind {
    MOVERIGHT = 0,
    MOVELEFT = 1,
    ADD = 2,
    SUB = 3,
    READ = 4,
    WRITE = 5,
    LOOPBEGIN = 6,
    LOOPEND = 7,
    Eof = 8
};

const std::string const TokenKindArr[] = {
    "MOVERIGHT",
    "MOVELEFT",
    "ADD",
    "SUB",
    "READ",
    "WRITE",
    "LOOPBEGIN",
    "LOOPEND",
    "Eof"
};

enum ASTNodeType {
    EXPRESSIONSTATEMENT,
    LOOPSTATEMENT
};