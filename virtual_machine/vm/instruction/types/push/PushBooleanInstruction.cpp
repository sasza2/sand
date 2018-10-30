#include "./PushBooleanInstruction.h"

PushBooleanInstruction::PushBooleanInstruction(bool value){
    this->value = value;
    ret = FactoryVariable::produceBoolean(value);
}

void PushBooleanInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;   
    PUSH(stack, ret);
    current->position++;
}

std::string PushBooleanInstruction::toString(){    
    return value ? "PUSH B true" : "PUSH B false";
}
