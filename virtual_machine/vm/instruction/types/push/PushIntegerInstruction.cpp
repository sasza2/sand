#include "PushIntegerInstruction.h"

PushIntegerInstruction::PushIntegerInstruction(long value){
    this->value = value;
    ret = FactoryVariable::produceInteger(value);
    ret->readOnly = true;
}

void PushIntegerInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;   
    PUSH(stack, ret);
    current->position++;
}

std::string PushIntegerInstruction::toString(){
    std::ostringstream ss;
    ss << value;
    return "PUSH I " + ss.str();
}

PushIntegerInstruction::~PushIntegerInstruction(){
    delete ret;
}