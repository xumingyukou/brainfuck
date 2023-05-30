#pragma once

#include<iostream>
#include "Ir.h"

void ir_eval(std::vector<Ir>& buf, EvalContext& ctx) {
    int pc = 0;
    std::vector<Ir> sp;

    while(pc < buf.size()) {
        Ir ir = buf[pc];
        pc++;

        switch(ir.op) {
        case IrOpCode::ADD:
            if(ctx.Array[ctx.index] == 127) {
                    std::cerr << "Invalid ADD: larger than 127";
                    exit(1);
                } else {
                    ctx.Array[ctx.index]++;
                }
            break;

        case IrOpCode::SUB:
            if(ctx.Array[ctx.index] == 0) {
                    std::cerr << "Invalid SUB: smaller than 0";
                    exit(1);
                } else {
                    ctx.Array[ctx.index]--;
                }
            break;

        case IrOpCode::MOVERIGHT:
            if(ctx.index == ctx.Array.size()) {
                    ctx.Array.push_back(0);
                    ctx.index++;
                } else {
                    ctx.index++;
                }
            break;

        case IrOpCode::MOVELEFT:
            if(ctx.index == 0) {
                    std::cerr << "Invalid position: out of range";
                } else {
                    ctx.index--;
                }
            break;

        case IrOpCode::READ:
            printf("%c; ", ctx.Array[ctx.index]);
            break;

        case IrOpCode::WRITE:
            scanf("%d", &ctx.Array[ctx.index]);
            break;

        case IrOpCode::IfEnough:
            if(ctx.Array[ctx.index] > 0) {
                pc = ir.val;
            }
            break;

        case IrOpCode::JUMP:
            pc = ir.val;
            break;

        case IrOpCode::BrFalse:
            pc = ir.val;
            break;

        case IrOpCode::Halt:
            return;
        }
    }
}
