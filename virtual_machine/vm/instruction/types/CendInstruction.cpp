#include "CendInstruction.h"

Instruction * CendInstruction::fromList(std::vector <std::string> mnemonics){
    return new CendInstruction();
}

void CendInstruction::execute(){
    VM_MY_TRACE_POS_INC();
}

std::string CendInstruction::toString(){
    return "CEND";
}
