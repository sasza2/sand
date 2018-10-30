#ifndef ADD_INSTRUCTION_H
#define ADD_INSTRUCTION_H

#include <string>
#include <vector>
#include "./../../Instruction.h"

class AddInstruction : public Instruction {
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        
};

#endif