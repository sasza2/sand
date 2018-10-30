#include "PushStringInstruction.h"

PushStringInstruction::PushStringInstruction(std::string value){
    this->value = value;
    variable = FactoryVariable::produceString(value);
    variable->readOnly = true;
}

void PushStringInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;
    PUSH(stack, variable);
    current->position++;
}

std::string PushStringInstruction::toString(){
    return "PUSH C " + value;
}

PushStringInstruction::~PushStringInstruction(){
    delete variable;
}