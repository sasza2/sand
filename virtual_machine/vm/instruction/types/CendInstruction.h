#ifndef CEND_INSTRUCTION_H
#define CEND_INSTRUCTION_H

#include <string>
#include <vector>
#include "./../Instruction.h"

class CendInstruction : public Instruction {

    private:
        bool shouldNotPop;

    public:
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        void refresh(Method * method);
};

#endif
