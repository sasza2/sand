#ifndef CLASS_INSTRUCTION_H
#define CLASS_INSTRUCTION_H

#include "./../Instruction.h"
#include <iostream>

class ClassInstruction : public Instruction {
    
    private:
        std::string name;
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        
        std::string getName();
        void setName(std::string name);
        
        std::string toString();
};

#endif 

