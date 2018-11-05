#include "./BreakInstruction.h"

Instruction * BreakInstruction::fromList(std::vector <std::string> mnemonics){
    return new BreakInstruction();
}

void BreakInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    current->position = nextPosition;
}

void BreakInstruction::refresh(Method * method){
	InstructionPosFinder finder;
	nextPosition = finder.addMethod(method)
						 .addPosition(positionInMethod)					     
					     .addType("FOREND")
						 .addType("WHILEEND")
				    	 .find() + 1;
}

std::string BreakInstruction::toString(){
    return "BREAK";
}
