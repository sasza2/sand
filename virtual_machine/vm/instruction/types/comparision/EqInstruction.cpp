#include "Comparision.h"

Instruction * EqInstruction::fromList(std::vector <std::string> mnemonics){
    return new EqInstruction();
}

void EqInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;
    Variable * a = POP(stack);    
    Variable * b = POP(stack);    
    PUSH(stack, a->eq(b));    
    current->position++;
    
    FREE(&a);
    FREE(&b);
}

std::string EqInstruction::toString(){
    return "EQ";
}