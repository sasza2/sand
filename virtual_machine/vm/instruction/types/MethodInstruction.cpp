#include "MethodInstruction.h"

Instruction * MethodInstruction::fromList(std::vector <std::string> mnemonics){    
    ClassInstruction * instruction = new ClassInstruction();
    instruction->setName(mnemonics[1]);    
    return instruction;
}

std::string MethodInstruction::getName(){
    return this->name;
}

void MethodInstruction::setName(std::string name){
    this->name = name;
}

void MethodInstruction::execute(){
    
}

std::string MethodInstruction::toString(){
    return "METHOD " + name;
}