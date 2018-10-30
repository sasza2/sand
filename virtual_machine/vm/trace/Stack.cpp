#include "Stack.h"

Stack::Stack(){
    capacity = 20;
    stack = new Variable * [capacity];
    for(int i = 0; i < capacity; i++){
        stack[i] = NULL;
    }
    pos = 0;
}

Stack::~Stack(){
    for(int i = 0; i < pos; i++){
        FREE(&stack[i]);
    }
    
    delete [] stack;
}