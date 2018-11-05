#include "While.h"

Instruction * WhileInstruction::fromList(std::vector <std::string> mnemonics){
    WhileInstruction * instruction = new WhileInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));
    return instruction;
}

void WhileInstruction::execute(){
    VM_MY_TRACE_POS_INC();
}

std::string WhileInstruction::toString(){
    return "WHILE " + std::to_string(getLevel());
}
