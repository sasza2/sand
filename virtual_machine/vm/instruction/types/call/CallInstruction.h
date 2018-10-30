#ifndef CALL_INSTRUCTION_H
#define CALL_INSTRUCTION_H

#include <string>
#include <vector>
#include <algorithm>
#include "./../../Instruction.h"
#include "./../../../var/NextVariable.h"
#include "./../../../var/StringVariable.h"
#include "./../../../var/NameVariable.h"
#include "IntSystem.h"

class CallInstruction : public Instruction {
    
    private:
        int arguments;
        std::string name;        
        
    public:     
        CallInstruction();
        CallInstruction(int arguments, std::string name);
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        
        Trace * rewriteArguments(Trace * current, std::vector <Variable*> argumentsList);
        std::vector <Variable*> produceArguments(Trace * current);
    
        std::string toString();
                
};

#endif