#include "MulInstruction.h"

Instruction * MulInstruction::fromList(std::vector <std::string> mnemonics){
    return new MulInstruction();
}

void MulInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack = current->stack;
    Variable * a = POP(stack);    
    Variable * b = POP(stack);            
    PUSH(stack, a->mul(b));    
    current->position++;
    
    FREE(&a);
    FREE(&b);
}

std::string MulInstruction::toString(){
    return "MUL";
}