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
            
            if(this->val == MOVERIGHT) {
                if(ctx.index == ctx.Array.size()) {
                    ctx.Array.push_back(0);
                    ctx.index++;
                } else {
                    ctx.index++;
                }
            }

            else if(this->val == MOVELEFT) {
                if(ctx.index == 0) {
                    std::cerr << "Invalid position: out of range";
                    //exit(1);
                } else {
                    ctx.index--;
                }
            }

            else if(this->val == ADD) {
                if(ctx.Array[ctx.index] == 127) {
                    std::cerr << "Invalid ADD: larger than 127";
                    exit(1);
                } else {
                    ctx.Array[ctx.index]++;
                }
            }

            else if(this->val == SUB) {
                if(ctx.Array[ctx.index] == 0) {
                    std::cerr << "Invalid SUB: smaller than 0";
                    exit(1);
                } else {
                    ctx.Array[ctx.index]--;
                }
            }

            else if(this->val == READ) {
                printf("%c; ", ctx.Array[ctx.index]);
            }

            else if(this->val == WRITE) {
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