#ifndef STACK_H
#define STACK_H

#include "./../var/Variable.h"

#define PUSH(STACK, VARIABLE) (STACK)->stack[(STACK)->pos++] = VARIABLE; 

#define POP(STACK) (STACK)->stack[--(STACK)->pos];

#define FREE(VARIABLE) \
if((*VARIABLE) != NULL && !(*VARIABLE)->readOnly && --(*VARIABLE)->usage <= 0){ \
delete *VARIABLE; \
*VARIABLE = NULL; \
}

#define USE(VARIABLE) VARIABLE->usage+=;

class Stack {
     
    public:
        Variable ** stack;
        int pos;
        int capacity;
        
        Stack();
        ~Stack();
    
};

#endif