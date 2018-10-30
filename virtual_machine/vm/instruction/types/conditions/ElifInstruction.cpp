#include "Conditions.h"

Instruction * ElifInstruction::fromList(std::vector <std::string> mnemonics){
    ElifInstruction * instruction = new ElifInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));
    return instruction;
}

void ElifInstruction::execute(){
    VM_MY_TRACE_POS_INC();
}

std::string ElifInstruction::toString(){
    return "ELIF " + std::to_string(getLevel());
}
