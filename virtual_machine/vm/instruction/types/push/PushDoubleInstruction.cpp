#include "PushDoubleInstruction.h"

PushDoubleInstruction::PushDoubleInstruction(double value){
    this->value = value;
    ret = FactoryVariable::produceDouble(value);
    ret->readOnly = true;
}

void PushDoubleInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;   
    PUSH(stack, ret);
    current->position++;
}

std::string PushDoubleInstruction::toString(){
    return "PUSH D " + std::to_string(value);
}

PushDoubleInstruction::~PushDoubleInstruction(){
    delete ret;
}