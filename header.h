#pragma once

#include<string>
#include<vector>

namespace TokenKind {
    enum Type {
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
}


// const std::string const TokenKindArr[] = {
//     "MOVERIGHT",
//     "MOVELEFT",
//     "ADD",
//     "SUB",
//     "READ",
//     "WRITE",
//     "LOOPBEGIN",
//     "LOOPEND",
//     "Eof"
// };

enum ASTNodeType {
    EXPRESSIONSTATEMENT,
    LOOPSTATEMENT
};

class EvalContext {
public:
    std::vector<int> Array;
    int index;

    EvalContext() {
        Array.push_back(0);
        this->index = 0;
    }
};

// void showArray111(EvalContext& ctx) {
//     printf("{size = %d, index = %d, [", int(ctx.Array.size()), ctx.index);
//     for(auto& i: ctx.Array) {
//         printf("%d ", i);
//     }
//     printf("]\n");
// }

namespace IrOpCode {
    enum Type {
    MOVERIGHT = 0,
    MOVELEFT = 1,
    ADD = 2,
    SUB = 3,
    READ = 4,
    WRITE = 5,
    IfEnough = 6,
    JUMP = 7,
    BrFalse = 8,
    Halt = 9
    };
}
