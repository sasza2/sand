#ifndef NEXT_VARIABLE_H
#define NEXT_VARIABLE_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "./Variable.h"
#include "./ObjectVariable.h"

class NextVariable : public Variable {
    
    private:
        std::string _value;
        long hash;
        ObjectVariable * object;
        
    public:
        NextVariable(std::string value, ObjectVariable * object);
        int type();
        std::string value();
        
        long getHash();
        
        bool emptyValue();
        ObjectVariable * getObject();
        Variable * produce();
        Variable * sum(Variable * variable);
        std::string toString();
        
        Variable * _and();
        Variable * _or();
        
        virtual Variable * eq(Variable * variable);
        virtual Variable * neq(Variable * variable);
        
        ~NextVariable();
};


#endif
