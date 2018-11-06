#ifndef DOWHILE_INSTRUCTION_H
#define DOWHILE_INSTRUCTION_H

#include <string>
#include <vector>
#include "./../../Instruction.h"

class DoWhileInstruction : public Instruction {

    private:
        size_t nextPosition;

    public:
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        void refresh(Method * method);

};

#endif
