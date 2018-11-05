#include "Comparision.h"

Instruction * LtInstruction::fromList(std::vector <std::string> mnemonics){
    return new LtInstruction();
}

void LtInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;
    Variable * a = POP(stack);
    Variable * b = POP(stack);

    PUSH(stack, a->lt(b));
    current->position++;

    FREE(&a);
    FREE(&b);
}

std::string LtInstruction::toString(){
    return "LT";
}

bool LtInstruction::isComparision(){
    return true;
}
