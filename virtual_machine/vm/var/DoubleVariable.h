#ifndef DOUBLE_VARIABLE_H
#define DOUBLE_VARIABLE_H

#include <sstream>
#include <string>
#include <iostream>
#include "./Variable.h"

class DoubleVariable : public Variable {
        
    public:
        double _value;
        
        DoubleVariable(double value);
        int type();
        
        virtual Variable * copy();
        
        double getValue();
        Variable * sum(Variable * variable);
        std::string toString();
        
        Variable * _and();
        Variable * _or();
        
};

#include "./IntegerVariable.h"
#include "./UndefinedVariable.h"

#endif
