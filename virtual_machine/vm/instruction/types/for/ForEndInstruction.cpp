#include "For.h"

Instruction * ForEndInstruction::fromList(std::vector <std::string> mnemonics){
    ForEndInstruction * instruction = new ForEndInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));
    return instruction;
}

void ForEndInstruction::execute(){   
    VM_MY_TRACE_POS_INC();
}

std::string ForEndInstruction::toString(){
    return "FOREND " + std::to_string(getLevel());
}
