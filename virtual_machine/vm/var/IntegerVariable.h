#ifndef INTEGER_VARIABLE_H
#define INTEGER_VARIABLE_H

#include <sstream>
#include <string>
#include <iostream>
#include "./Variable.h"

class IntegerVariable : public Variable {
        
    public:
        long _value;
        
        IntegerVariable(long value);
        int type();
        
        Variable * copy();
        
        Variable * sum(Variable * variable);
        long getValue();
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
