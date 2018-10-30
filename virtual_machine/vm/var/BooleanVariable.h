#ifndef BOOLEAN_VARIABLE_H
#define BOOLEAN_VARIABLE_H

#include <sstream>
#include <string>
#include <iostream>
#include "./Variable.h"

class BooleanVariable : public Variable {
    
    private:
        bool _value;
        
    public:
        BooleanVariable(bool value);
        int type();
        
        virtual Variable * copy();
        
        Variable * sum(Variable * variable);
        bool getValue();
        std::string toString();
        
        Variable * _and();
        Variable * _or();
        
        Variable * inc();
        
};

#include "./StringVariable.h"
#include "./UndefinedVariable.h"
#include "./DoubleVariable.h"
#include "./NameVariable.h"
#include "./factory/FactoryVariable.h"

#endif
