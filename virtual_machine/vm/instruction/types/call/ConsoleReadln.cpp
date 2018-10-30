#include "IntSystem.h"

void ConsoleReadlnCommand::call(std::vector <Variable*> arguments) {
    VM::getInstance()->getMutex().lock(LOCK_CONSOLE);
    
    char buffer[256];
    scanf("%256s", buffer);
    while(getchar() != '\n'){
        continue;
    }
    
    std::string str = std::string(buffer);
    
    Trace * trace = VM_MY_TRACE();
    Stack * stack = trace->stack;
    PUSH(stack, FactoryVariable::produceString(str));       
    
    VM::getInstance()->getMutex().unlock(LOCK_CONSOLE);
}


