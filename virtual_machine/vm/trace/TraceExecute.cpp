#include "TraceExecute.h"

std::string TraceExecute::all(TraceList * traceList){
    Trace * last = traceList->current;
    Method * method = last->getMethod();
    Instruction ** instructions = method->getInstructions()->data();

    std::string ret = "";

    std::vector <Trace*> * traces = traceList->traces;

    int sizes = traceList->traces->size();
    while(sizes > 0){
        #if DEBUG == 1
            print(last, instructions[last->position]);
        #endif

        instructions[last->position]->execute();

        if(sizes != traceList->size){
            if(traceList->exception != NULL){
                ret = traceList->exception->toString();
                last = traceList->current;
                if(last != NULL){
                    method = last->getMethod();
                    instructions = method->getInstructions()->data();
                }
            } else if(traceList->size > 0){
                if(traceList->size < sizes){
                    delete last;
                }
                last   = traces->back();
                traceList->current = last;
                traceList->stack = last->stack;
                method = last->getMethod();
                instructions = method->getInstructions()->data();
            } else if(traceList->current != NULL){
                Variable * retVar = last->stack->pos <= 0 ? FactoryVariable::produceUndefined() : POP(last->stack);
                if(retVar->type() == NAME){
                    Variable * tmp = ((NameVariable*)retVar)->produceFromLocal();
                    retVar = tmp == NULL ? retVar : tmp;
                }
                if(retVar->change){
                    retVar->inc();
                }
                ret = retVar->toString();
                delete last;
                last = NULL;
            }
            sizes = traceList->size;
        }
    }

    delete last;
    delete traceList->traces;

    return ret;
}

Variable * TraceExecute::once(std::vector <Trace*> * traces){
    Trace * current;
    Stack * stack;
    if(!traces->empty()){
        current = traces->back();
        stack = current->stack;
    }
    while(!traces->empty()){
        Trace * last = traces->back();
        Instruction * instruction = last->getMethod()->getInstruction(last->getPosition());
        print(last, instruction);
        if(current == last && instruction->type() == "RET"){
            RetInstruction * retInstruction = (RetInstruction*)instruction;
            return retInstruction->executeAndPop(traces, last, stack);
        } else {
            instruction->execute();
        }
    }

    return NULL;
}

void TraceExecute::print(Trace * trace, Instruction * instruction){
    std::cout<<"* "<<trace->getMethod()->getClass()->name()<<"->"<<trace->getMethod()->getName()<<": "<<instruction->toString()<<std::endl;
}
