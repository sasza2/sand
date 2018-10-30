#include "ClassInstruction.h"

Instruction * ClassInstruction::fromList(std::vector <std::string> mnemonics){    
    ClassInstruction * instruction = new ClassInstruction();
    instruction->setName(mnemonics[1]);    
    return instruction;
}

std::string ClassInstruction::getName(){
    return this->name;
}

void ClassInstruction::setName(std::string name){
    this->name = name;
}

void ClassInstruction::execute(){
    
}

std::string ClassInstruction::toString(){
    return "CLASS " + name;
}