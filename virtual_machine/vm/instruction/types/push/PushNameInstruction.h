#ifndef PUSH_NAME_INSTRUCTION_H
#define PUSH_NAME_INSTRUCTION_H

#include <string>
#include <vector>
#include "./PushInstruction.h"
#include "./../../../var/ClassVariable.h"

class NameVariable;
class Trace;

class PushNameInstruction : public PushInstruction {
        
    private:
        std::string value;
        long hash;
        long _thisHash;
        Variable * ret;
        bool isThis;
    
    public:     
        PushNameInstruction(std::string value);    
        void execute();
        std::string toString();
        void refresh(Method * method);
        ~PushNameInstruction();
        
};

#include "./../../../var/NameVariable.h"
#include "./../../../trace/Trace.h"

#endif