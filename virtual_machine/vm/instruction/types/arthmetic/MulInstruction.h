#ifndef MUL_INSTRUCTION_H
#define MUL_INSTRUCTION_H

#include <string>
#include <vector>
#include "./../../Instruction.h"

class MulInstruction : public Instruction {
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        
};

#endif