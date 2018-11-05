#include "While.h"

Instruction * WhileEndInstruction::fromList(std::vector <std::string> mnemonics){
    WhileEndInstruction * instruction = new WhileEndInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));
    return instruction;
}

void WhileEndInstruction::execute(){
	Trace * current = VM_MY_TRACE();
	current->position = nextPosition;
}

std::string WhileEndInstruction::toString(){
    return "WHILEEND " + std::to_string(getLevel());
}

void WhileEndInstruction::refresh(Method * method){
    InstructionPosFinder finder;
    nextPosition = finder.addMethod(method)
                         .addPosition(positionInMethod)
                         .addLevel(getLevel())
                         .addType("WHILE")
                         .addDirection(-1)
                         .find() + 1;
}
