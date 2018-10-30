#include "DivInstruction.h"

Instruction * DivInstruction::fromList(std::vector <std::string> mnemonics){
    return new DivInstruction();
}

void DivInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack = current->stack;
    Variable * a = POP(stack);    
    Variable * b = POP(stack);            
    PUSH(stack, a->div(b));    
    current->position++;
    
    FREE(&a);
    FREE(&b);
}

std::string DivInstruction::toString(){
    return "DIV";
}