#include "PowInstruction.h"

Instruction * PowInstruction::fromList(std::vector <std::string> mnemonics){
    return new PowInstruction();
}

void PowInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack = current->stack;
    Variable * a = POP(stack);    
    Variable * b = POP(stack);            
    PUSH(stack, a->pow(b));    
    current->position++;
    
    FREE(&a);
    FREE(&b);
}

std::string PowInstruction::toString(){
    return "POW";
}