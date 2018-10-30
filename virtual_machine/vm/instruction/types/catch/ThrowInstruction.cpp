#include "./CatchInstruction.h"

Instruction * ThrowInstruction::fromList(std::vector <std::string> mnemonics){
    ThrowInstruction * instruction = new ThrowInstruction();    
    return instruction;
}

void ThrowInstruction::execute(){    
    TraceList * traceList = VM_MY_THREAD_LIST();
    Variable * variable  = POP(traceList->stack);    
    traceList->exception = exceptionRead(variable);
    if(traceList->exception != variable){
        FREE(&variable);
    }
    traceList->exception->usage++;
    
    TraceException::catchIt(traceList);
    if(traceList->size > 0){
        traceList->current->position = traceList->current->getExceptions().last();
    }
}

Variable * ThrowInstruction::exceptionRead(Variable * variable){
    Variable * tmp;
    switch(variable->type()){        
        case CLASS:
            return ((ClassVariable*)variable)->getClass()->_static;            
        case NAME:
            tmp = ((NameVariable*)variable)->produceFromLocal();
            if(tmp == NULL){
                return FactoryVariable::produceUndefined();
            }
            return tmp;
        case NEXT:
            tmp = ((NextVariable*)variable)->produce();
            if(tmp == NULL || tmp->type() != OBJECT){
                return FactoryVariable::produceUndefined();
            }
            return tmp;            
        default:
            return variable;
    }       
}

std::string ThrowInstruction::toString(){
    return "THROW";
}
