#include "SubInstruction.h"

Instruction * SubInstruction::fromList(std::vector <std::string> mnemonics){
    return new SubInstruction();
}

void SubInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack = current->stack;
    Variable * a = POP(stack);    
    Variable * b = POP(stack);            
    PUSH(stack, a->sub(b));    
    current->position++;
    
    FREE(&a);
    FREE(&b);
}

std::string SubInstruction::toString(){
    return "SUB";
}