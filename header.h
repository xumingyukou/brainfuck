#pragma once

enum TokenKind {
    MOVERIGHT,
    MOVELEFT,
    ADD,
    SUB,
    READ,
    WRITE,
    LOOPBEGIN,
    LOOPEND
};

enum ASTNodeType {
    EXPRESSIONSTATEMENT,
    LOOPSTATEMENT
};