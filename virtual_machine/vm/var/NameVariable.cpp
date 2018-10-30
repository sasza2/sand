#include "NameVariable.h"

NameVariable::NameVariable(std::string value){
    this->_value = value;
    hash = str_to_int_hash(value);
}

int NameVariable::type(){
    return NAME;
}

std::string NameVariable::value(){
    return _value;
}

long NameVariable::getHash(){
    return hash;
}

Variable * NameVariable::produceFromLocal(){
    Trace * trace = VM_MY_TRACE();
    return object_get(trace->local, hash);
}

Variable * NameVariable::sum(Variable * variable){
    Variable * current = produceFromLocal();
    return current == NULL ? FactoryVariable::produceUndefined() : current->sum(variable);
}

Variable * NameVariable::_and(){
    Variable * current = produceFromLocal();
    return current == NULL ? FactoryVariable::produceUndefined() : current->_and();    
}

Variable * NameVariable::_or(){
    Variable * current = produceFromLocal();
    return current == NULL ? FactoryVariable::produceUndefined() : current->_or();    
}

Variable * NameVariable::eq(Variable * variable){
    Variable * current = produceFromLocal();
    return current == NULL ? FactoryVariable::produceUndefined() : current->eq(variable);    
}

Variable * NameVariable::neq(Variable * variable){
    Variable * current = produceFromLocal();
    return current == NULL ? FactoryVariable::produceUndefined() : current->neq(variable);    
}

Variable * NameVariable::gt(Variable * variable){
    Variable * current = produceFromLocal();
    return current == NULL ? FactoryVariable::produceUndefined() : current->gt(variable);    
}

Variable * NameVariable::lt(Variable * variable){
    Variable * current = produceFromLocal();
    return current == NULL ? FactoryVariable::produceUndefined() : current->lt(variable);    
}

Variable * NameVariable::gte(Variable * variable){
    Variable * current = produceFromLocal();
    return current == NULL ? FactoryVariable::produceUndefined() : current->gte(variable);    
}

Variable * NameVariable::lte(Variable * variable){
    Variable * current = produceFromLocal();
    return current == NULL ? FactoryVariable::produceUndefined() : current->lte(variable);    
}

std::string NameVariable::toString(){
    return _value;
}