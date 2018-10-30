#ifndef AND_INSTRUCTION_H
#define AND_INSTRUCTION_H

#include <string>
#include <vector>
#include "./../Instruction.h"

class AndInstruction : public Instruction {
    
    private:
        int posOnFalse;
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        
        void refresh(Method * method);
        
};

#endif