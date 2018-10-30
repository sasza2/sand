#ifndef PUSH_STRING_INSTRUCTION_H
#define PUSH_STRING_INSTRUCTION_H

#include <string>
#include <vector>
#include "./PushInstruction.h"

class StringVariable;

class PushStringInstruction : public PushInstruction {
        
    private:
        std::string value;
        StringVariable * variable;
    
    public:     
        PushStringInstruction(std::string value);   
        void execute();
        std::string toString();
        
        ~PushStringInstruction();
        
};

#include "./../../../var/StringVariable.h"

#endif