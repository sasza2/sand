#ifndef MOV_INSTRUCTION_H
#define MOV_INSTRUCTION_H

#include <string>
#include <vector>
#include "./../Instruction.h"
#include "./../../var/NameVariable.h"

class MovInstruction : public Instruction {
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
    
        std::string toString();
        virtual bool isMoveable();
        
};

#endif