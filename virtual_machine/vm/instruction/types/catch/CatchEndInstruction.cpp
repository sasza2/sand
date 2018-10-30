#include "./CatchInstruction.h"

Instruction * CatchEndInstruction::fromList(std::vector <std::string> mnemonics){
    CatchEndInstruction * instruction = new CatchEndInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));    
    return instruction;
}

void CatchEndInstruction::execute(){    
    Trace * current = VM_MY_TRACE();
    current->position++;    
}

std::string CatchEndInstruction::toString(){
    return "CATCHEND " + std::to_string(getLevel());
}
