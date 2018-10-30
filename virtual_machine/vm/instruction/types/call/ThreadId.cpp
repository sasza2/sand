#include "IntSystem.h"

void ThreadIdCommand::call(std::vector <Variable*> arguments){    
    Trace * trace = VM::getInstance()->getCurrentThreadTraces()->current;
    Stack * stack = trace->stack;
    PUSH(stack, FactoryVariable::produceInteger((long)pthread_self()));    
}
