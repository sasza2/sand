#ifndef CATCH_H
#define CATCH_H

#include <string>
#include <vector>
#include "./../../Instruction.h"
#include "./../../../var/NameVariable.h"
#include "./../../../trace/TraceException.h"

class ThrowInstruction : public Instruction {
    
    private:
        Variable * exceptionRead(Variable * variable);
    
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
                
};

class TryInstruction : public Instruction {
    
    private:
        int catchPosition;
            
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        void refresh(Method * method);
        
};

class CatchInstruction : public Instruction {
    
    private:
        std::string variableName;
        int catchEndPosition;
            
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
        void refresh(Method * method);
        
        void setVariableName(std::string variableName);
                
};

class CatchEndInstruction : public Instruction {
                
    public:        
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        std::string toString();
                
};

#endif