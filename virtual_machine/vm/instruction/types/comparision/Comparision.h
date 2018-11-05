#ifndef COMPARISION_H
#define COMPARISION_H

#include <string>
#include <vector>
#include "./../../Instruction.h"

class EqInstruction : public Instruction {

    public:
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        virtual bool isComparision();

};

class GtInstruction : public Instruction {

    public:
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        virtual bool isComparision();

};

class GteInstruction : public Instruction {

    public:
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        virtual bool isComparision();

};

class LtInstruction : public Instruction {

    public:
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        virtual bool isComparision();

};

class LteInstruction : public Instruction {

    public:
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        virtual bool isComparision();

};

class NeqInstruction : public Instruction {

    public:
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        virtual bool isComparision();

};

#endif
