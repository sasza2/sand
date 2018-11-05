#include "./ContinueInstruction.h"

Instruction * ContinueInstruction::fromList(std::vector <std::string> mnemonics){
    return new ContinueInstruction();
}

void ContinueInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    current->position = nextPosition;
}

void ContinueInstruction::refresh(Method * method){
	InstructionPosFinder finder;
	nextPosition = finder.addMethod(method)
						 .addPosition(positionInMethod)
						 .addDirection(-1)
					     .addType("FORIF")
						 .addType("WHILE")
				    	 .find() + 1;
}

std::string ContinueInstruction::toString(){
    return "CONTINUE";
}
