#ifndef STRING_VARIABLE_H
#define STRING_VARIABLE_H

#include "./Variable.h"
#include <sstream>
#include <string>
#include <iostream>

class StringVariable : public Variable {
    
    private:
        std::string _value;
        
    public:
        StringVariable(std::string value);
        int type();
        
        std::string value();
        
        Variable * sum(Variable * variable);
        
        std::string toString();
        
        Variable * _and();
        Variable * _or();
    
};

#endif
