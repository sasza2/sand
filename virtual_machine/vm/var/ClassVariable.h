#ifndef CLASS_VARIABLE_H
#define CLASS_VARIABLE_H

#include "./Variable.h"
#include "./../class/Class.h"

class ClassVariable : public Variable {
    
    private:
        Class * cls;
        
    public:        
        ClassVariable(Class * cls);
        Class * getClass();
        int type();
        Variable * sum(Variable * variable);
        std::string toString();
        
        Variable * _and();        
        Variable * _or();        
};

#endif