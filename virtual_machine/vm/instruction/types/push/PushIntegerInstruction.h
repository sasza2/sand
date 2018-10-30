#ifndef PUSH_INTEGER_INSTRUCTION_H
#define PUSH_INTEGER_INSTRUCTION_H

#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include "./PushInstruction.h"
#include "./../../../var/IntegerVariable.h"

class PushIntegerInstruction : public PushInstruction {
        
    private:
        long value;
        IntegerVariable * ret;
    
    public:     
        PushIntegerInstruction(long value);    
        void execute();
        std::string toString();
        
        ~PushIntegerInstruction();
        
};

#endif