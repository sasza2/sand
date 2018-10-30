#ifndef ARGS_INSTRUCTION_H
#define ARGS_INSTRUCTION_H

#include "./../Instruction.h"
#include <iostream>
#include <string>
#include <vector>

class ArgsInstruction : public Instruction {
    
    private:
        int count;
        std::string args;
        
    public:        
        ArgsInstruction();
        ArgsInstruction(int count, std::string args);
        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        
        int getCount();
        std::string getArgs();
        
        std::string toString();
};

#endif 

