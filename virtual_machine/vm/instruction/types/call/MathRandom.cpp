#include "IntSystem.h"

void MathRandomCommand::call(std::vector <Variable*> arguments){    
    if(arguments.size() < 2){
        return;
    }
    
    if(arguments[0]->type() != INT || arguments[1]->type() != INT){
        return;
    }
    
    IntegerVariable * from = (IntegerVariable*)arguments[0];
    IntegerVariable * to   = (IntegerVariable*)arguments[1];
    
    IntegerVariable * intRandom = FactoryVariable::produceInteger(rand() % (to->getValue() - from->getValue()) + from->getValue());
    Trace * trace = VM_MY_TRACE();
    Stack * stack = trace->stack;
    
    PUSH(stack, intRandom);    
}