#include "IntSystem.h"

void ThreadWaitCommand::call(std::vector <Variable*> arguments){    
    Variable * var = arguments[0];
    if(var->type() != OBJECT){
        std::cout<<"thread data error"<<std::endl;
        return;
    }
           
}
