#include "Parser.h"

Program Parser::program() {
        Program* program = new Program;

        std::vector<std::vector<ASTNode*>*> nodeStack;  // 保存上一层的body->nodes
        std::vector<ASTNode*>* currentNode = &(program->body->nodes);

        Token token = lx.next();
    
        while (token.tk != TokenKind::Eof) {
            switch(token.tk) {
            case TokenKind::MOVERIGHT:
            case TokenKind::MOVELEFT:
            case TokenKind::ADD:
            case TokenKind::SUB:
            case TokenKind::READ:
            case TokenKind::WRITE: {
                ASTNode* astNode = new ASTNode(EXPRESSIONSTATEMENT, token.tk, nullptr);
                (*currentNode).push_back(astNode);
                break;
            }
            default:
                break;
            }

            if(token.tk == TokenKind::LOOPBEGIN) {
                ASTNode* node = new ASTNode;
                node->type = LOOPSTATEMENT;
                node->val = TokenKind::LOOPBEGIN;
                node->body = new Body;
                (*currentNode).push_back(node);
                nodeStack.push_back(currentNode);
                currentNode = &(node->body->nodes);
            }

            if(token.tk == TokenKind::LOOPEND) {
                currentNode = nodeStack.back();
                nodeStack.pop_back();
            }

            token = lx.next();
        }

        return *program;
    }