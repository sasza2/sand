#include "Conditions.h"

Instruction * IfEndInstruction::fromList(std::vector <std::string> mnemonics){
    IfEndInstruction * instruction = new IfEndInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));
    return instruction;
}

void IfEndInstruction::execute(){        
    Trace * current = VM_MY_TRACE();
    current->position = nextPosition;
}

std::string IfEndInstruction::toString(){
    return "IFEND " + std::to_string(getLevel());
}

void IfEndInstruction::refresh(Method * method){
    InstructionPosFinder finder;
    nextPosition = finder.addMethod(method)
                         .addPosition(positionInMethod)
                         .addLevel(getLevel())
                         .addType("IFENDALL")
                         .find();
}