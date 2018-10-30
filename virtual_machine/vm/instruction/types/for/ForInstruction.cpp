#include "For.h"

Instruction * ForInstruction::fromList(std::vector <std::string> mnemonics){
    ForInstruction * instruction = new ForInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));
    return instruction;
}

void ForInstruction::execute(){
    VM_MY_TRACE_POS_INC();
}

std::string ForInstruction::toString(){
    return "FOR " + std::to_string(getLevel());
}
