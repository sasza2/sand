#ifndef METHOD_INSTRUCTION_H
#define METHOD_INSTRUCTION_H

#include "./../Instruction.h"

class MethodInstruction : public Instruction {
        
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

