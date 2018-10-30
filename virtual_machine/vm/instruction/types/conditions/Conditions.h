#ifndef CONDITIONS_H
#define CONDITIONS_H

#include <string>
#include <vector>
#include "./../../Instruction.h"

class IfInstruction : public Instruction {
            
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
                
};

class JmpInstruction : public Instruction {
    
    private:
        int nextPosition;
            
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        void refresh(Method * method);
        
};

class IfEndInstruction : public Instruction {
    
    private:
        int nextPosition;
            
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        void refresh(Method * method);
        
};

class ElifEndInstruction : public Instruction {
    
    private:
        int nextPosition;
            
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        void refresh(Method * method);
        
};

class ElifInstruction : public Instruction {
            
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
                
};

class ElseInstruction : public Instruction {
            
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
                
};

class IfEndAllInstruction : public Instruction {
            
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
                
};

#endif