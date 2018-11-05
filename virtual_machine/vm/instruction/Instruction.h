#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <vector>

class Trace;
class Method;

class Instruction {

    private:
        std::string _type;
        int level = -1;

    protected:
        Method * method;
        int positionInMethod;

    public:
        virtual Instruction * fromList(std::vector <std::string> mnemonics) = 0;
        virtual void execute() = 0;
        virtual std::string toString() = 0;
        std::string type();
        void setType(std::string type);
        virtual bool isMoveable();
        virtual bool isComparision();

        int getLevel();
        void setLevel(int level);

        void setPositionInMethod(int position);
        virtual void refresh(Method * method);

        virtual ~Instruction();
};

#include "./../trace/Trace.h"
#include "./../instruction/InstructionPosFinder.h"
#include "./../method/Method.h"
#include "./../VM.h"

#endif
