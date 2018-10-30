#include "AddInstruction.h"

Instruction * AddInstruction::fromList(std::vector <std::string> mnemonics){
    return new AddInstruction();
}

void AddInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack = current->stack;
    Variable * a = POP(stack);    
    Variable * b = POP(stack);      
            
    PUSH(stack, a->sum(b));    
    current->position++;
        
    FREE(&a);
    FREE(&b);
}

std::string AddInstruction::toString(){
    return "ADD";
}