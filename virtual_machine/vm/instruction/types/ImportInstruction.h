#ifndef IMPORT_INSTRUCTION_H
#define IMPORT_INSTRUCTION_H

#include "./../Instruction.h"

class ImportInstruction : public Instruction {
    
    private:
        std::string name;
        std::string path;
    
    public:
        Instruction * fromList(std::vector <std::string> mnemonics);
        void execute();
        
        std::string getName();
        void setName(std::string name);
        
        std::string getPath();
        void setPath(std::string path);
        
        std::string toString();
                
};

#endif