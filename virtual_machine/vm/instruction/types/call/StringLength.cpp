#include "IntSystem.h"

void StringLengthCommand::call(std::vector <Variable*> arguments){    
    if(arguments.size() < 1){
        return;
    }
        
    if(arguments[0]->type() != STRING){
        return;
    }
    
    Variable * length = FactoryVariable::produceInteger(((StringVariable*)arguments[0])->value().length());
    
    Trace * trace = VM_MY_TRACE();
    Stack * stack = trace->stack;
    
    PUSH(stack, length);    
}