#ifndef RET_INSTRUCTION_H
#define RET_INSTRUCTION_H

#include <string>
#include <vector>
#include "./../Instruction.h"
#include "./../../var/UndefinedVariable.h"

class RetInstruction : public Instruction {
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        Variable * executeAndPop(std::vector <Trace*> *, Trace * current, Stack * stack);
        
};

#endif