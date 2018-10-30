#include "For.h"

Instruction * ForBodyInstruction::fromList(std::vector <std::string> mnemonics){
    ForBodyInstruction * instruction = new ForBodyInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));
    return instruction;
}

void ForBodyInstruction::execute(){    
    Trace * current = VM_MY_TRACE();
    current->position = nextPosition;
}

std::string ForBodyInstruction::toString(){
    return "FORBODY " + std::to_string(getLevel());
}

void ForBodyInstruction::refresh(Method * method){
    InstructionPosFinder finder;
    nextPosition = finder.addMethod(method)
                         .addPosition(positionInMethod)
                         .addLevel(getLevel())
                         .addDirection(-1)
                         .addType("FOR")                                                 
                         .find() + 1;
}