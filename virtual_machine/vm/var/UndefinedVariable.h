#ifndef UNDEFINED_VARIABLE_H
#define UNDEFINED_VARIABLE_H

#include "./Variable.h"

class UndefinedVariable : public Variable {
    
    public:        
        Variable * sum(Variable * variable);
        
        virtual Variable * eq(Variable * variable);
        virtual Variable * neq(Variable * variable);
        
        Variable * _and();
        Variable * _or();
        
        int type();
        std::string toString();
    
};

#endif