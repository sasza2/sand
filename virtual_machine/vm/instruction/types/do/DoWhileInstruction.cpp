#include "DoWhileInstruction.h"

Instruction * DoWhileInstruction::fromList(std::vector <std::string> mnemonics){
    return new DoWhileInstruction();    
}

void DoWhileInstruction::execute(){
	Trace * current = VM_MY_TRACE();
    current->position = nextPosition;
}

std::string DoWhileInstruction::toString(){
    return "DOWHILE " + std::to_string(getLevel());
}

void DoWhileInstruction::refresh(Method * method){
    InstructionPosFinder finder;
    nextPosition = finder.addMethod(method)
                         .addPosition(positionInMethod)
                         .addType("WHILEIF")
                         .find() + 1;
}
