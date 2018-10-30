#include "Conditions.h"

Instruction * IfInstruction::fromList(std::vector <std::string> mnemonics){
    IfInstruction * instruction = new IfInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));
    return instruction;
}

void IfInstruction::execute(){    
    VM_MY_TRACE_POS_INC();
}

std::string IfInstruction::toString(){
    return "IF " + std::to_string(getLevel());
}
