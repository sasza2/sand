#include "ArgsInstruction.h"

Instruction * ArgsInstruction::fromList(std::vector <std::string> mnemonics){
    return mnemonics.size() == 2 ? new ArgsInstruction(2, "") : new ArgsInstruction(3, mnemonics[2]);
}

ArgsInstruction::ArgsInstruction(){
    
}

ArgsInstruction::ArgsInstruction(int count, std::string args){
    this->count = count;
    this->args  = args;
}

int ArgsInstruction::getCount(){
    return this->count;
}


std::string ArgsInstruction::getArgs(){
    return this->args;
}

void ArgsInstruction::execute(){
    
}

std::string ArgsInstruction::toString(){
    std::string result = "ARGS ";
    result += count;
    result += " ";
    result += args;
    return result;
}