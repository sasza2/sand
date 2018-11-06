#include "NotInstruction.h"

Instruction * NotInstruction::fromList(std::vector <std::string> mnemonics){
    return new NotInstruction();
}

void NotInstruction::execute(){
	Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;
    Variable * variable = POP(stack);
    if(variable->type() == BOOLEAN){
		BooleanVariable * boolean = (BooleanVariable*)variable;
        PUSH(stack, boolean->getValue() ? FactoryVariable::produceFalse() : FactoryVariable::produceTrue());
    } else {
        PUSH(stack, FactoryVariable::produceUndefined());
    }
    FREE(&variable);
}

std::string NotInstruction::toString(){
    return "NOT";
}
