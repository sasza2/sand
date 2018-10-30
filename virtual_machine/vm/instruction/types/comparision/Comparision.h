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
        
};

class GtInstruction : public Instruction {
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        
};

class GteInstruction : public Instruction {
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        
};

class LtInstruction : public Instruction {
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        
};

class LteInstruction : public Instruction {
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        
};

class NeqInstruction : public Instruction {
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        
};

#endif