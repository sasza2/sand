#include "Comparision.h"

Instruction * GteInstruction::fromList(std::vector <std::string> mnemonics){
    return new GteInstruction();
}

void GteInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;
    Variable * a = POP(stack);    
    Variable * b = POP(stack);    
    PUSH(stack, a->gte(b));    
    current->position++;
    
    FREE(&a);
    FREE(&b);
}

std::string GteInstruction::toString(){
    return "GTE";
}