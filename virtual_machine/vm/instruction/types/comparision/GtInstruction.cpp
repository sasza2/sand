#include "Comparision.h"

Instruction * GtInstruction::fromList(std::vector <std::string> mnemonics){
    return new GtInstruction();
}

void GtInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;
    Variable * a = POP(stack);    
    Variable * b = POP(stack);    
    PUSH(stack, a->gt(b));    
    current->position++;
    
    FREE(&a);
    FREE(&b);
}

std::string GtInstruction::toString(){
    return "GT";
}