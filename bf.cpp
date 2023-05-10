// 这个语言由8种运算符组成
// 这种语言基于一个机器模型，除了指令之外，还包括：一个以字节为单位、已经初始化为0
// 的数组、一个指向该数组的指针（开始时指向数组的第一个字节）、以及用于输入输出的两个字节流

#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

string TEST = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";

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

class Token {
public:
    TokenKind tk;
    char val;

    Token(TokenKind tk, char val): tk(tk), val(val){}
};

vector<Token> lexer(string code) {
    vector<Token> tokens;
    int current = 0;
    int totalLen = code.size();

    while (current < totalLen)
    {
        const char op = code[current++];

        switch(op) {
        case '+':
            tokens.push_back(Token(ADD, op));
            break;
        case '-':
            tokens.push_back(Token(SUB, op));
            break;
        case '>':
            tokens.push_back(Token(MOVERIGHT, op));
            break;
        case '<':
            tokens.push_back(Token(MOVELEFT, op));
            break;
        case '.':
            tokens.push_back(Token(READ, op));
            break;   
        case ',':
            tokens.push_back(Token(WRITE, op));
            break;
        case '[':
            tokens.push_back(Token(LOOPBEGIN, op));
            break;
        case ']':
            tokens.push_back(Token(LOOPEND, op));
            break;
        default:
            break;
        }
    }
    
    return tokens;
}

enum ASTNodeType {
    EXPRESSIONSTATEMENT,
    LOOPSTATEMENT
};

class ASTNode;
class Body;
class Program;

class ASTNode {
public:
    ASTNodeType type;
    TokenKind val;
    Body* body;

    ASTNode(){};
    ASTNode(ASTNodeType type, TokenKind val, Body* body): type(type), val(val), body(body){};

    void show() {
        if(this->type == EXPRESSIONSTATEMENT) {
            printf("[Type: EXPRESSIONSTATEMENT, val: %d]\n", val);
        } else {
            printf("[Type: LOOPSTATEMENT, val: ");
            body->show();
            printf("]\n");
        }
    }
};

class Body {
public:
    vector<ASTNode*> nodes;

    void show() {
        for(auto& node: this->nodes) {
            node->show();
        }
    }
};

class Program {
public:
    Body* body;
    
    void show() {
        this->body->show();
    }
};

Program Parser(vector<Token> tokens) {
    Program* program = new Program;

    vector<vector<ASTNode*>*> nodeStack;  // 保存上一层的body->nodes
    vector<ASTNode*>* currentNode = &(program->body->nodes);

    
    for(auto& token: tokens) {
        switch(token.tk) {
        case MOVERIGHT:
        case MOVELEFT:
        case ADD:
        case SUB:
        case READ:
        case WRITE:
            ASTNode* astNode = new ASTNode(EXPRESSIONSTATEMENT, token.tk, nullptr);
            (*currentNode).push_back(astNode);
        }

        if(token.tk == LOOPBEGIN) {
            ASTNode* node = new ASTNode;
            node->type = LOOPSTATEMENT;
            (*currentNode).push_back(node);
            nodeStack.push_back(currentNode);
        }

        if(token.tk == LOOPEND) {
            currentNode = nodeStack.back();
            nodeStack.pop_back();
        }
    }

    return *program;
}


int main() {
    vector<Token> tokens = lexer(TEST);
    // for(auto& token: tokens) {
    //     printf("{Token | Type: %d, Val: %c}\n", token.tk, token.val);
    // }

    Program program = Parser(tokens);
    program.show();
}

