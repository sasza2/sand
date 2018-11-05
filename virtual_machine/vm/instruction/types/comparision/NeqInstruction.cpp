#include "Comparision.h"

Instruction * NeqInstruction::fromList(std::vector <std::string> mnemonics){
    return new NeqInstruction();
}

void NeqInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;
    Variable * a = POP(stack);
    Variable * b = POP(stack);
    PUSH(stack, a->neq(b));
    current->position++;

    FREE(&a);
    FREE(&b);
}

std::string NeqInstruction::toString(){
    return "NEQ";
}

bool NeqInstruction::isComparision(){
    return true;
}
