#ifndef METHOD_H
#define METHOD_H

#include <string>
#include <vector>

class Class;
class Instruction;

class Method {
  
    private:
        std::string name;
        std::vector <Instruction*> * instructions;
        std::vector <std::string> arguments;
        Class * cls;
        
    public:
        Method(std::string name, Class * cls);
        
        void pushArguments(std::string);
        std::vector <std::string> getArguments();
        
        void pushInstruction(Instruction * instruction);
        std::string getName();
        void executeInstruction(size_t position);       
        Instruction * getInstruction(size_t position);        
        std::vector <Instruction*> * getInstructions();
        Class * getClass();
        
        void refresh();
        
        ~Method();
};

#include "./../instruction/Instruction.h"
#include "./../class/Class.h"

#endif