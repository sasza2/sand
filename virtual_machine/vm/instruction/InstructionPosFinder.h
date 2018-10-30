#ifndef INSTRUCTION_LEVEL_FINDER_H
#define INSTRUCTION_LEVEL_FINDER_H

#include <string>
#include <vector>
#include "./../method/Method.h"

class InstructionPosFinder {
    
    private:
        std::vector <std::string> types;
        int level;
        int position;
        int direction;
        bool moveable;
        Method * method;
        
        bool instructionHasType(Instruction * instruction);
  
    public:
        InstructionPosFinder();
        InstructionPosFinder & addType(std::string type);
        InstructionPosFinder & addLevel(int level);
        InstructionPosFinder & addPosition(int position);
        InstructionPosFinder & addDirection(int direction);
        InstructionPosFinder & addMoveable(bool moveable);
        InstructionPosFinder & addMethod(Method * method);
        InstructionPosFinder & clear();
        int find();
        
};

#endif