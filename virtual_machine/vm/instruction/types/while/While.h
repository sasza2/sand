#ifndef WHILE_H
#define WHILE_H

#include <string>
#include <vector>
#include "./../../Instruction.h"

class WhileInstruction : public Instruction {

    public:
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();

};

class WhileIfInstruction : public Instruction {

    private:
        size_t positionOnFalse;

    public:
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        void refresh(Method * method);

};

class WhileEndInstruction : public Instruction {

    private:
        size_t nextPosition;

    public:
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        void refresh(Method * method);

};

#endif
