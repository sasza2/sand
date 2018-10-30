#ifndef POW_INSTRUCTION_H
#define POW_INSTRUCTION_H

#include <string>
#include <vector>
#include "./../../Instruction.h"

class PowInstruction : public Instruction {
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        
};

#endif