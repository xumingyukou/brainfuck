#pragma once

#include "Lexer.h"
#include "Program.h"
#include "Body.h"
#include "ASTNode.h"

class Parser {
public:
    Lexer lx;

    Parser(Lexer lx) {
        this->lx = lx;
    }

    Program program() {
        Program* program = new Program;

        std::vector<std::vector<ASTNode*>*> nodeStack;  // 保存上一层的body->nodes
        std::vector<ASTNode*>* currentNode = &(program->body->nodes);

        Token token = lx.next();
    
        while (token.tk != Eof) {
            switch(token.tk) {
            MOVERIGHT:
            case MOVELEFT:
            case ADD:
            case SUB:
            case READ:
            case WRITE: {
                ASTNode* astNode = new ASTNode(EXPRESSIONSTATEMENT, token.tk, nullptr);
                (*currentNode).push_back(astNode);
                break;
            }
            default:
                break;
            }

            if(token.tk == LOOPBEGIN) {
                ASTNode* node = new ASTNode;
                node->type = LOOPSTATEMENT;
                node->val = LOOPBEGIN;
                node->body = new Body;
                (*currentNode).push_back(node);
                nodeStack.push_back(currentNode);
                currentNode = &(node->body->nodes);
            }

            if(token.tk == LOOPEND) {
                currentNode = nodeStack.back();
                nodeStack.pop_back();
            }

            token = lx.next();
        }

        return *program;
    }
};