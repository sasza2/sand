#include "Instruction.h"

void (Instruction::*instructionPointer)() const = NULL;

std::string Instruction::type(){
    return this->_type;
}

void Instruction::setType(std::string type){
    this->_type = type;
}

bool Instruction::isMoveable(){
    return false;
}

int Instruction::getLevel(){
    return level;
}

void Instruction::setLevel(int level){
    this->level = level;
}

void Instruction::refresh(Method * method){
    this->method = method;
}

void Instruction::setPositionInMethod(int position){
    this->positionInMethod = position;
}

Instruction::~Instruction(){
    
}