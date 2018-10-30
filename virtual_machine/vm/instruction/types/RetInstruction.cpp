#include "RetInstruction.h"

Instruction * RetInstruction::fromList(std::vector <std::string> mnemonics){
    return new RetInstruction();
}

void RetInstruction::execute(){
    TraceList * traceList = VM_MY_THREAD_LIST();
    executeAndPop(traceList->traces, traceList->current, traceList->current->stack);
}

Variable * RetInstruction::executeAndPop(std::vector <Trace*> * traces, Trace * current, Stack * stack){    
    TraceList * traceList = VM_MY_THREAD_LIST();
    traces->pop_back();        
        
    Variable * var = NULL;
    if(!traces->empty()){        
        if(stack->pos > 0){
            var = POP(stack);
        }
                
        if(var == NULL){
            var = FactoryVariable::produceUndefined();
        }
                        
        if(var->type() == NAME){
            Variable * tmp = ((NameVariable*)var)->produceFromLocal();            
            if(tmp != NULL){
                FREE(&var);
                var = tmp;
            }
        }
                                
        //is not a constructor
        if(current->getMethod()->getName() != std::string("constructor")){  
            PUSH(traces->back()->stack, var);
        }        
    }
                       
    traceList->size--;
    //delete current; 
    return var;
}

std::string RetInstruction::toString(){
    return "RET";
}