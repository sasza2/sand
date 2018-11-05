#include "PushUndefinedInstruction.h"

PushUndefinedInstruction::PushUndefinedInstruction(){
    variable = FactoryVariable::produceUndefined();
}

void PushUndefinedInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;
    PUSH(stack, variable);
    current->position++;
}

std::string PushUndefinedInstruction::toString(){
    return "PUSH U undefined";
}
