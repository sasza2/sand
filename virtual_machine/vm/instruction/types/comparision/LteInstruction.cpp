#include "Comparision.h"

Instruction * LteInstruction::fromList(std::vector <std::string> mnemonics){
    return new LteInstruction();
}

void LteInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;
    Variable * a = POP(stack);    
    Variable * b = POP(stack);    
    PUSH(stack, a->lte(b));    
    current->position++;
    
    FREE(&a);
    FREE(&b);
}

std::string LteInstruction::toString(){
    return "LTE";
}