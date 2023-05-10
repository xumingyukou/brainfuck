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