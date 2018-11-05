#include "While.h"

Instruction * WhileIfInstruction::fromList(std::vector <std::string> mnemonics){
    WhileIfInstruction * instruction = new WhileIfInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));
    return instruction;
}

void WhileIfInstruction::execute(){
	Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;
    Variable * boolean = POP(stack);
    if(boolean->type() == BOOLEAN && ((BooleanVariable*)boolean)->getValue()){
        VM_MY_TRACE_POS_INC();
    } else {
        current->position = positionOnFalse;
    }
    FREE(&boolean);
}

std::string WhileIfInstruction::toString(){
    return "WHILEIF " + std::to_string(getLevel());
}

void WhileIfInstruction::refresh(Method * method){
    InstructionPosFinder finder;
    positionOnFalse = finder.addMethod(method)
                            .addPosition(positionInMethod)
                            .addLevel(getLevel())
                            .addType("WHILEEND")
                            .find() + 1;
}
