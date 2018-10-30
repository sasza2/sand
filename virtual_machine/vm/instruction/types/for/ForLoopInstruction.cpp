#include "For.h"

Instruction * ForLoopInstruction::fromList(std::vector <std::string> mnemonics){
    ForLoopInstruction * instruction = new ForLoopInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));
    return instruction;
}

void ForLoopInstruction::execute(){    
    Trace * trace = VM_MY_TRACE();
    trace->position = nextPosition;
}

std::string ForLoopInstruction::toString(){
    return "FORLOOP " + std::to_string(getLevel());
}

void ForLoopInstruction::refresh(Method * method){
    InstructionPosFinder finder;
    nextPosition = finder.addMethod(method)
                         .addPosition(positionInMethod)
                         .addLevel(getLevel())
                         .addDirection(-1)
                         .addType("FORIF")                                                 
                         .find() + 1;
}