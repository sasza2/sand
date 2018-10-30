#ifndef CLASS_READER_H
#define CLASS_READER_H

#include "Class.h"
#include "./../method/Method.h"
#include "./../instruction/Instruction.h"
#include "./../instruction/types/ClassInstruction.h"
#include "./../instruction/InstructionFactory.h"
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

class ClassReader {
    
private:
    std::vector <std::string> split(std::string code, char delimiter);    
    std::vector <Instruction*> produceInstructions(std::string code);    
    
public:
    Class * fromFile(std::string);
    Class * fromStr(std::string);
    static void refresh(Class * cls);

};

#endif