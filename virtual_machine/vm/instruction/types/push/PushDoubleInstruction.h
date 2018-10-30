#ifndef PUSH_DOUBLE_INSTRUCTION_H
#define PUSH_DOUBLE_INSTRUCTION_H

#include <string>
#include <vector>
#include "./PushInstruction.h"

class DoubleVariable;


class PushDoubleInstruction : public PushInstruction {
        
    private:
        double value;
        DoubleVariable * ret;
    
    public:     
        PushDoubleInstruction(double value);
        void execute();
        std::string toString();
        
        ~PushDoubleInstruction();
};

#include "./../../../var/DoubleVariable.h"

#endif