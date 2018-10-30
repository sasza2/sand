#ifndef INC_INSTRUCTION_H
#define INC_INSTRUCTION_H

#include <string>
#include <vector>
#include "./../Instruction.h"

class IncInstruction : public Instruction {
    
    private:
        bool beforeUse; //increment before use
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        
        bool getBeforeUse();
        void setBeforeUse(bool beforeUse);
        
};

#endif
