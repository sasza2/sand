#ifndef BREAK_INSTRUCTION_H
#define BREAK_INSTRUCTION_H

#include <string>
#include <vector>
#include "./../Instruction.h"

class BreakInstruction : public Instruction {

    private:
        int nextPosition;

    public:
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        void refresh(Method * method);
};

#endif
