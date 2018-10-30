#ifndef NEXT_INSTRUCTION_H
#define NEXT_INSTRUCTION_H

#include <string>
#include <vector>
#include "./../Instruction.h"
#include "./../../var/NextVariable.h"
#include "./../../trace/TraceException.h"
#include "./../../var/factory/FactoryVariable.h"

class NextInstruction : public Instruction {
    
    private:
        bool in;
        long hash;
        void executeNotEmptyName(TraceList * traceList);
        void executeEmptyName(TraceList * traceList);
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        
        bool isIn();
        void setIn(bool in);
        
        std::string toString();
};

#endif