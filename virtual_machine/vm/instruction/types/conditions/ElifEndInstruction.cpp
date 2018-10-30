#include "Conditions.h"

Instruction * ElifEndInstruction::fromList(std::vector <std::string> mnemonics){
    ElifEndInstruction * instruction = new ElifEndInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));
    return instruction;
}

void ElifEndInstruction::execute(){    
    VM_MY_TRACE_POS_INC();
}

std::string ElifEndInstruction::toString(){
    return "ELIFEND " + std::to_string(getLevel());
}

void ElifEndInstruction::refresh(Method * method){
    InstructionPosFinder finder;
    nextPosition = finder.addMethod(method)
                         .addPosition(positionInMethod)
                         .addLevel(getLevel())
                         .addType("IFENDALL")
                         .find();
}