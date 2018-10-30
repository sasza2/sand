#ifndef OR_INSTRUCTION_H
#define OR_INSTRUCTION_H

#include <string>
#include <vector>
#include "./../Instruction.h"

class OrInstruction : public Instruction {
    
    private:
        int posOnTrue;
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        
        void refresh(Method * method);
        
};

#endif