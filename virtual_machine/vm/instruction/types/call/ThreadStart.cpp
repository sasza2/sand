#include "IntSystem.h"

void ThreadStartCommand::call(std::vector <Variable*> arguments){    
    Variable * var = arguments[0];
    if(var->type() != OBJECT){
        std::cout<<"thread object error"<<std::endl;
        return;
    }
           
}
