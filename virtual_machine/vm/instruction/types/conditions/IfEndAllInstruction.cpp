#include "Conditions.h"

Instruction * IfEndAllInstruction::fromList(std::vector <std::string> mnemonics){
    IfEndAllInstruction * instruction = new IfEndAllInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));
    return instruction;
}

void IfEndAllInstruction::execute(){    
    VM_MY_TRACE_POS_INC();
}

std::string IfEndAllInstruction::toString(){
    return "IFENDALL " + std::to_string(getLevel());
}
