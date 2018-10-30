#ifndef NEW_INSTRUCTION_H
#define NEW_INSTRUCTION_H

#include "./../Instruction.h"
#include "./../../var/factory/FactoryVariable.h"
#include "../../trace/TraceException.h"

class NewInstruction : public Instruction {
    
    private:
        int arguments;
        std::string name;
        
    public:
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
    
        int getArguments();
        void setArguments(int arguments);
        
        std::string getName();
        void setName(std::string name);
        
        std::string toString();
        
};

#endif