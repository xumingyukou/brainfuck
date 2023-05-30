#include "ASTNode.h"
#include "Body.h"

void ASTNode::show() {
    if(this->type == EXPRESSIONSTATEMENT) {
            printf("[Type: EXPRESSIONSTATEMENT, val: %d]\n", val);
        } else {
            printf("[Type: LOOPSTATEMENT, val: ");
            body->show();
            printf("]\n");
        }
}

void ASTNode::eval(EvalContext& ctx) {
        if(this->type == EXPRESSIONSTATEMENT) {
            
            if(this->val == TokenKind::MOVERIGHT) {
                if(ctx.index == ctx.Array.size()) {
                    ctx.Array.push_back(0);
                    ctx.index++;
                } else {
                    ctx.index++;
                }
            }

            else if(this->val == TokenKind::MOVELEFT) {
                if(ctx.index == 0) {
                    std::cerr << "Invalid position: out of range";
                    //exit(1);
                } else {
                    ctx.index--;
                }
            }

            else if(this->val == TokenKind::ADD) {
                if(ctx.Array[ctx.index] == 127) {
                    std::cerr << "Invalid ADD: larger than 127";
                    exit(1);
                } else {
                    ctx.Array[ctx.index]++;
                }
            }

            else if(this->val == TokenKind::SUB) {
                if(ctx.Array[ctx.index] == 0) {
                    std::cerr << "Invalid SUB: smaller than 0";
                    exit(1);
                } else {
                    ctx.Array[ctx.index]--;
                }
            }

            else if(this->val == TokenKind::READ) {
                printf("%c; ", ctx.Array[ctx.index]);
            }

            else if(this->val == TokenKind::WRITE) {
                scanf("%d", &ctx.Array[ctx.index]);
            }

            printf("{size = %d, index = %d, [", int(ctx.Array.size()), ctx.index);
            for(auto& i: ctx.Array) {
                printf("%d ", i);
            }
            printf("]}\n");
        }
        
        else {
            //int preIndex = ctx.index;
            while(ctx.Array[ctx.index]) {
                this->body->eval(ctx);
            }
        }

    }

void ASTNode::gen(std::vector<Ir>& buf) {
    if(this->type == EXPRESSIONSTATEMENT) {

        switch (this->val)
        {
        case IrOpCode::MOVERIGHT:
            buf.push_back(Ir(IrOpCode::MOVERIGHT, 1));
            break;
        case IrOpCode::MOVELEFT:
            buf.push_back(Ir(IrOpCode::MOVELEFT, 1));
            break;
        case IrOpCode::ADD:
            buf.push_back(Ir(IrOpCode::ADD, 1));
            break;
        case IrOpCode::SUB:
            buf.push_back(Ir(IrOpCode::SUB, 1));
            break;
        case IrOpCode::READ:
            buf.push_back(Ir(IrOpCode::READ, 0));
            break;
        case IrOpCode::WRITE:
            buf.push_back(Ir(IrOpCode::WRITE, 0));
            break;
        default:
            break;
        }

    } else {

        int i = buf.size();
        buf.push_back(Ir(IrOpCode::IfEnough, 0));
        int j = buf.size();
        buf.push_back(Ir(IrOpCode::BrFalse, 0));
        this->body->gen(buf);
        buf.push_back(Ir(IrOpCode::JUMP, i));
        buf[j].val = buf.size();

    }
}