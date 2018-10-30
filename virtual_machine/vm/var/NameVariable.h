#ifndef NAME_VARIABLE_H
#define NAME_VARIABLE_H

#include "./Variable.h"
#include <string>

class NameVariable : public Variable {
    
    private:
        std::string _value;     
        long hash;
        
    public:
        NameVariable(std::string value);
        int type();
        std::string value();
        
        long getHash();
        
        Variable * produceFromLocal();
        
        Variable * sum(Variable * variable);
        std::string toString();
        
        Variable * _and();
        Variable * _or();
        
        virtual Variable * eq(Variable * variable);
        virtual Variable * neq(Variable * variable);
        virtual Variable * gt(Variable * variable);
        virtual Variable * lt(Variable * variable);
        virtual Variable * gte(Variable * variable);
        virtual Variable * lte(Variable * variable); 
                
};

#include "./../VM.h"

#endif
