#include "./InstructionPosFinder.h"

InstructionPosFinder::InstructionPosFinder(){
    moveable  = false;
    direction = 1;
    level     = -1;
}

InstructionPosFinder & InstructionPosFinder::addType(std::string type){
    types.push_back(type);
    return *this;
}

InstructionPosFinder & InstructionPosFinder::addLevel(int level){
    this->level = level;
    return *this;
}

InstructionPosFinder & InstructionPosFinder::addPosition(int position){
    this->position = position;
    return *this;
}

InstructionPosFinder & InstructionPosFinder::addDirection(int direction){
    this->direction = direction;
    return *this;
}

InstructionPosFinder & InstructionPosFinder::addMoveable(bool moveable){
    this->moveable = moveable;
    return *this;
}

InstructionPosFinder & InstructionPosFinder::addMethod(Method * method){
    this->method = method;
    return *this;
}

bool InstructionPosFinder::instructionHasType(Instruction * instruction){
    for(unsigned int i = 0; i < types.size(); i++){
        if(types[i] == instruction->type()){
            return true;
        }
    }
    return false;
}

InstructionPosFinder & InstructionPosFinder::clear(){
    moveable  = false;
    direction = 1;
    level     = -1;
    types.clear();
    return *this;
}

int InstructionPosFinder::find(){
    std::vector <Instruction*> * instructions = method->getInstructions();
    for(unsigned int i = position + direction; i < instructions->size() && i >= 0; i += direction){
        Instruction * instruction = instructions->at(i);
        if(level >= 0 && instruction->getLevel() != level){
            continue;
        }

        if(!instructionHasType(instruction) && !(moveable && instruction->isMoveable())){
            continue;
        }

        return i;
    }
    return -1;
}
