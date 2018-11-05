#include "CendInstruction.h"

Instruction * CendInstruction::fromList(std::vector <std::string> mnemonics){
    return new CendInstruction();
}

void CendInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;
    if(!shouldNotPop){
        Variable * ret = POP(stack);
        FREE(&ret);
    }
    current->position++;
}

void CendInstruction::refresh(Method * method){
    Instruction * next = method->getInstruction(positionInMethod + 1);
    Instruction * prev = method->getInstruction(positionInMethod - 1);

    shouldNotPop = next->type() == "RET" || next->type() == "THROW" || prev->isComparision();
}

std::string CendInstruction::toString(){
    return "CEND";
}
