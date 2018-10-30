#ifndef PUSH_BOOLEAN_INSTRUCTION_H
#define PUSH_BOOLEAN_INSTRUCTION_H

#include <string>
#include "./PushInstruction.h"

class BooleanVariable;

class PushBooleanInstruction : public PushInstruction {
        
    private:
        bool value;
        BooleanVariable * ret;
    
    public:     
        PushBooleanInstruction(bool value);
        void execute();
        std::string toString();
        
};

#include "./../../../var/BooleanVariable.h"

#endif