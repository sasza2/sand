#include "./CatchInstruction.h"

Instruction * TryInstruction::fromList(std::vector <std::string> mnemonics){
    TryInstruction * instruction = new TryInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));
    return instruction;
}

void TryInstruction::execute(){    
    Trace * current = VM_MY_TRACE();
    current->position++;
    current->getExceptions().push(catchPosition);
}

std::string TryInstruction::toString(){
    return "TRY " + std::to_string(getLevel());
}

void TryInstruction::refresh(Method * method){
    InstructionPosFinder finder;
    catchPosition = finder.addMethod(method)
                          .addPosition(positionInMethod)
                          .addLevel(getLevel())
                          .addDirection(1)
                          .addType("CATCH")                                                 
                          .find();
}