#include "header.h"
#include "ASTNode.h"
#include "Token.h"
#include "Program.h"
#include "Lexer.h"
#include "Parser.h"
#include<vector>
#include<string>

// std::vector<Token> lexer(std::string code) {
//     std::vector<Token> tokens;
//     int current = 0;
//     int totalLen = code.size();

//     while (current < totalLen)
//     {
//         const char op = code[current++];

//         switch(op) {
//         case '+':
//             tokens.push_back(Token(ADD, op));
//             break;
//         case '-':
//             tokens.push_back(Token(SUB, op));
//             break;
//         case '>':
//             tokens.push_back(Token(MOVERIGHT, op));
//             break;
//         case '<':
//             tokens.push_back(Token(MOVELEFT, op));
//             break;
//         case '.':
//             tokens.push_back(Token(READ, op));
//             break;   
//         case ',':
//             tokens.push_back(Token(WRITE, op));
//             break;
//         case '[':
//             tokens.push_back(Token(LOOPBEGIN, op));
//             break;
//         case ']':
//             tokens.push_back(Token(LOOPEND, op));
//             break;
//         default:
//             break;
//         }
//     }
    
//     return tokens;
// }

// Program Parser(std::vector<Token> tokens) {
//     Program* program = new Program;

//     std::vector<std::vector<ASTNode*>*> nodeStack;  // 保存上一层的body->nodes
//     std::vector<ASTNode*>* currentNode = &(program->body->nodes);

    
//     for(auto& token: tokens) {
//         switch(token.tk) {
//         case MOVERIGHT:
//         case MOVELEFT:
//         case ADD:
//         case SUB:
//         case READ:
//         case WRITE: {
//             ASTNode* astNode = new ASTNode(EXPRESSIONSTATEMENT, token.tk, nullptr);
//             (*currentNode).push_back(astNode);
//             break;
//         }
//         default:
//             break;
//         }

//         if(token.tk == LOOPBEGIN) {
//             ASTNode* node = new ASTNode;
//             node->type = LOOPSTATEMENT;
//             node->val = LOOPBEGIN;
//             node->body = new Body;
//             (*currentNode).push_back(node);
//             nodeStack.push_back(currentNode);
//             currentNode = &(node->body->nodes);
//         }

//         if(token.tk == LOOPEND) {
//             currentNode = nodeStack.back();
//             nodeStack.pop_back();
//         }
//     }

//     return *program;
// }

int main() {

    std::string TEST = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";

    //std::string TEST = "[>+++++++>++++++++++>+++>+<<<<-]";

    // std::vector<Token> tokens = lexer(TEST);
    // // for(auto& token: tokens) {
    // //     printf("{Token | Type: %d, Val: %c}\n", token.tk, token.val);
    // // }

    // Program program = Parser(tokens);
    // program.show();

    Parser ps = Parser(Lexer(TEST));
    Program ast = ps.program();
    ast.show();
}