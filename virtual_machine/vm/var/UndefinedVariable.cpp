#include "UndefinedVariable.h"

int UndefinedVariable::type(){
    return UNDEFINED;
}

Variable * UndefinedVariable::sum(Variable * variable){
    return this;
}

Variable * UndefinedVariable::_and(){
    return this;
}

Variable * UndefinedVariable::_or(){
    return this;
}

Variable * UndefinedVariable::eq(Variable * variable){
    return variable->type() == UNDEFINED ? FactoryVariable::produceTrue() : FactoryVariable::produceFalse();
}

Variable * UndefinedVariable::neq(Variable * variable){
    return variable->type() == UNDEFINED ? FactoryVariable::produceFalse() : FactoryVariable::produceTrue();
}

std::string UndefinedVariable::toString(){
    return "undefined";
}
