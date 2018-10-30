#ifndef DIV_INSTRUCTION_H
#define DIV_INSTRUCTION_H

#include <string>
#include <vector>
#include "./../../Instruction.h"

class DivInstruction : public Instruction {
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        
};

#endif