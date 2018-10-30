#include "ClassVariable.h"

ClassVariable::ClassVariable(Class * cls){
    this->cls = cls;    
}

Class * ClassVariable::getClass(){
    return cls;
}

int ClassVariable::type(){
    return CLASS;
}

Variable * ClassVariable::sum(Variable * variable){
    return FactoryVariable::produceUndefined();
}

Variable * ClassVariable::_and(){
    return FactoryVariable::produceUndefined();
}

Variable * ClassVariable::_or(){
    return FactoryVariable::produceUndefined();
}

std::string ClassVariable::toString(){
    return "class " + cls->name();
}