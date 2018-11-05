#ifndef PUSH_INSTRUCTION_H
#define PUSH_INSTRUCTION_H

#include <string>
#include <vector>
#include "./../../Instruction.h"

class PushInstruction : public Instruction {

    public:
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string type();
        std::string toString();

        virtual ~PushInstruction();
};

#include "./PushBooleanInstruction.h"
#include "./PushDoubleInstruction.h"
#include "./PushIntegerInstruction.h"
#include "./PushStringInstruction.h"
#include "./PushNameInstruction.h"
#include "./PushUndefinedInstruction.h"
#include "./../../../var/factory/FactoryVariable.h"

#endif
