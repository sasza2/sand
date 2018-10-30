#ifndef FOR_H
#define FOR_H

#include <string>
#include <vector>
#include "./../../Instruction.h"

class ForInstruction : public Instruction {
            
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
                
};

class ForIfInstruction : public Instruction {
    
    private:
        size_t positionOnTrue, positionOnFalse;
            
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        void refresh(Method * method);
                
};

class ForBodyInstruction : public Instruction {
    
    private:
        size_t nextPosition;
            
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        void refresh(Method * method);
                
};

class ForLoopInstruction : public Instruction {
    
    private:
        size_t nextPosition;
            
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        void refresh(Method * method);
                
};

class ForEndInstruction : public Instruction {
            
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
                
};
        
#endif