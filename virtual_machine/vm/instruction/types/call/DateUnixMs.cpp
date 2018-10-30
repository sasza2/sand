#include "IntSystem.h"

void DateUnixMsCommand::call(std::vector <Variable*> arguments){
    struct timeval te; 
    gettimeofday(&te, NULL); // get current time
    long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
    
    Trace * trace = VM_MY_TRACE();
    Stack * stack = trace->stack;
    PUSH(stack, FactoryVariable::produceInteger(milliseconds));    
}