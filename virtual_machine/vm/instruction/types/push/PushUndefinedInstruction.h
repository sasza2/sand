#ifndef PUSH_UNDEFINED_INSTRUCTION_H
#define PUSH_UNDEFINED_INSTRUCTION_H

#include <string>
#include <vector>
#include "./PushInstruction.h"

class UndefinedVariable;

class PushUndefinedInstruction : public PushInstruction {

    private:
        UndefinedVariable * variable;

    public:
        PushUndefinedInstruction();
        void execute();
        std::string toString();

};

#include "./../../../var/StringVariable.h"

#endif
