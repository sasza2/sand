#ifndef NOT_INSTRUCTION_H
#define NOT_INSTRUCTION_H

#include <string>
#include <vector>
#include "./../../Instruction.h"

class NotInstruction : public Instruction {

    public:
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();

};

#endif
