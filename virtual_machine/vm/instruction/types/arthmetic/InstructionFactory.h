#ifndef INSTRUCTION_FACTORY_H
#define INSTRUCTION_FACTORY_H 1

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "./Instruction.h"
#include "./types/ClassInstruction.h"
#include "./types/MethodInstruction.h"
#include "./types/ArgsInstruction.h"
#include "./types/push/PushInstruction.h"
#include "./types/MovInstruction.h"
#include "./types/CendInstruction.h"
#include "./types/NextInstruction.h"
#include "./types/call/CallInstruction.h"
#include "./types/RetInstruction.h"
#include "./types/ImportInstruction.h"
#include "./types/NewInstruction.h"
#include "./types/arthmetic/AddInstruction.h"
#include "./types/arthmetic/MulInstruction.h"
#include "./types/arthmetic/SubInstruction.h"
#include "./types/AndInstruction.h"
#include "./types/OrInstruction.h"
#include "./types/comparision/Comparision.h"
#include "./types/conditions/Conditions.h"
#include "./types/for/For.h"
#include "./types/IncInstruction.h"

class InstructionFactory {

    private:
        static std::map <std::string, Instruction*> * instructions;

    public:        
        static Instruction * produce(std::vector <std::string> mnemonics);
        static void free();

};

#endif
