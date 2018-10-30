#ifndef SUB_INSTRUCTION_H
#define SUB_INSTRUCTION_H

#include <string>
#include <vector>
#include "./../../Instruction.h"

class SubInstruction : public Instruction {
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        
};

#endif