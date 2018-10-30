#include "./CatchInstruction.h"

Instruction * CatchInstruction::fromList(std::vector <std::string> mnemonics){
    CatchInstruction * instruction = new CatchInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));
    instruction->setVariableName(mnemonics[2]);
    return instruction;
}

void CatchInstruction::execute(){    
    TraceList * traceList = VM_MY_THREAD_LIST();
    
    Trace * current = traceList->current;    
    current->getExceptions().pop();
    
    if(traceList->exception == NULL){
        current->position = catchEndPosition;
    } else {        
        current->local->set(str_to_int_hash(variableName), traceList->exception);
        current->position++;
        traceList->exception = NULL;
    }        
}

std::string CatchInstruction::toString(){
    return "CATCH " + std::to_string(getLevel());
}

void CatchInstruction::setVariableName(std::string variableName){
    this->variableName = variableName;
}

void CatchInstruction::refresh(Method * method){
    InstructionPosFinder finder;
    catchEndPosition = finder.addMethod(method)
                             .addPosition(positionInMethod)
                             .addLevel(getLevel())
                             .addDirection(1)
                             .addType("CATCHEND")                                                 
                             .find() + 1;
}