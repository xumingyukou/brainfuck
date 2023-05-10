#pragma once
#include "Body.h"

class Program {
public:
    Body* body;

    Program() {
        this->body = new Body;
    }
    
    void show() {
        this->body->show();
    }
};