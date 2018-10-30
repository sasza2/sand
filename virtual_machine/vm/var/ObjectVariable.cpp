#include "ObjectVariable.h"

ObjectVariable::ObjectVariable(Class * cls){
    this->cls = cls;
    size = 0;
    this->keys = new long[64];
    this->variables = new Variable * [64];
}

int ObjectVariable::keyPosition(long name){
    for(int i = 0; i < size; i++){
        if(keys[i] == name){
            return i;
        }
    }
    return -1;
}

Variable * ObjectVariable::get(long name){
    int r = keyPosition(name);
    return r < 0 ? NULL : variables[r];
}

ObjectVariable * ObjectVariable::set(long name, Variable * variable){
    int pos = keyPosition(name);
    if(pos < 0){
        keys[size] = name;
        variables[size] = variable;
        size++;
    } else {
        variables[pos] = variable;
    }
    return this;
}

int ObjectVariable::type(){
    return OBJECT;
}

Class * ObjectVariable::getClass(){
    return cls;
}

Variable * ObjectVariable::sum(Variable * variable){
    if(variable->type() == STRING){
        return FactoryVariable::produceString(toString() + variable->toString());
    }
    return FactoryVariable::produceUndefined();
}

Variable * ObjectVariable::eq(Variable * variable){
    return NULL;
}

Variable * ObjectVariable::neq(Variable * variable){
    return NULL;
}

Variable * ObjectVariable::_and(){
    return FactoryVariable::produceUndefined();
}

Variable * ObjectVariable::_or(){
    return FactoryVariable::produceUndefined();
}

std::string ObjectVariable::toString(){
    return "object " + cls->name();
}

ObjectVariable::~ObjectVariable(){
    for(int i = 0; i < size; i++){
        FREE(&variables[i]);
    }

    delete keys;
    delete [] variables;

    #if DEBUG == 1
        std::cout<<"variable remove "<<this<<std::endl;
    #endif
}
