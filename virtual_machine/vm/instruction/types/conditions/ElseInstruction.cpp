#include "Conditions.h"

Instruction * ElseInstruction::fromList(std::vector <std::string> mnemonics){
    ElseInstruction * instruction = new ElseInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));
    return instruction;
}

void ElseInstruction::execute(){    
    VM_MY_TRACE_POS_INC();
}

std::string ElseInstruction::toString(){
    return "ELSE " + std::to_string(getLevel());
}
