#include "PushInstruction.h"

Instruction * PushInstruction::fromList(std::vector <std::string> mnemonics){
    std::string arg = "";
    for(unsigned int i = 2; i < mnemonics.size(); i++){
        if(i > 2){
            arg += " ";
        }
        arg += mnemonics[i];
    }
    char type = mnemonics[1][0];
    switch(type){
        case 'D': //double
            return new PushDoubleInstruction(atof(arg.c_str()));
        case 'I': //int
            return new PushIntegerInstruction(atol(arg.c_str()));
        case 'C': //string
            return new PushStringInstruction(arg);
        case 'B':
            return new PushBooleanInstruction(arg == std::string("true"));
        case 'S':
        default:
            return new PushNameInstruction(arg);
    }
}

std::string PushInstruction::type(){
    return "PUSH";
}

void PushInstruction::execute(){

}

std::string PushInstruction::toString(){
    return "PUSH";
}

PushInstruction::~PushInstruction(){

}
