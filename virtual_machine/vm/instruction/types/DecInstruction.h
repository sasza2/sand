#ifndef DEC_INSTRUCTION_H
#define DEC_INSTRUCTION_H

#include <string>
#include <vector>
#include "./../Instruction.h"

class DecInstruction : public Instruction {

    private:
        bool beforeUse; //decrement before use

    public:
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();

        bool getBeforeUse();
        void setBeforeUse(bool beforeUse);

};

#endif
