#include "OrInstruction.h"

Instruction * OrInstruction::fromList(std::vector <std::string> mnemonics){
    return new OrInstruction();
}

void OrInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;
    
    Variable * a = POP(stack);
    Variable * ret = a->_or();
    if(ret->type() == BOOLEAN && ((BooleanVariable*)ret)->getValue()){        
        PUSH(stack, ret);
        current->position = posOnTrue;
    } else {
        current->position++;
    }            
    
    FREE(&a);
    FREE(&ret);
}

std::string OrInstruction::toString(){
    return "OR";
}

void OrInstruction::refresh(Method * method){
    InstructionPosFinder finder;
    posOnTrue = finder.addMethod(method)
                      .addMoveable(true)
                      .addPosition(positionInMethod)
                      .addType("AND")
                      .addType("CEND")
                      .find();
}