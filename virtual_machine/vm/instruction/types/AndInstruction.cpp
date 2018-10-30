#include "AndInstruction.h"

Instruction * AndInstruction::fromList(std::vector <std::string> mnemonics){
    return new AndInstruction();
}

void AndInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack  = current->stack;

    Variable * a = POP(stack);
    Variable * ret = a->_and();

    if(ret->type() == BOOLEAN && ((BooleanVariable*)ret)->getValue()){
        current->position++;
    } else {
        PUSH(stack, ret);        
        current->position = posOnFalse;
    }

    FREE(&a);
    FREE(&ret);
}

std::string AndInstruction::toString(){
    return "AND";
}

void AndInstruction::refresh(Method * method){
    InstructionPosFinder finder;
    posOnFalse = finder.addMethod(method)
                       .addMoveable(true)
                       .addPosition(positionInMethod)
                       .addType("OR")
                       .addType("CEND")
                       .find();
}
