#include "NextVariable.h"

NextVariable::NextVariable(std::string value, ObjectVariable * object){
    this->_value = value;
    hash = str_to_int_hash(value);
    this->object = object;
}

int NextVariable::type(){
    return NEXT;
}

long NextVariable::getHash(){
    return hash;
}

std::string NextVariable::value(){
    return _value;
}

bool NextVariable::emptyValue(){
    return _value.empty();
}

ObjectVariable * NextVariable::getObject(){
    return object;
}

Variable * NextVariable::produce(){
    return object->get(hash);
}

Variable * NextVariable::sum(Variable * variable){
    Variable * current = produce();
    if(current == NULL){
        return FactoryVariable::produceUndefined();
    }

    return current->sum(variable);
}

Variable * NextVariable::_and(){
    return FactoryVariable::produceUndefined();
}

Variable * NextVariable::_or(){
    return FactoryVariable::produceUndefined();
}

Variable * NextVariable::eq(Variable * variable){
    Variable * current = produce();
    if(current == NULL){
        return FactoryVariable::produceUndefined();
    }

    return current->eq(variable);
}

Variable * NextVariable::neq(Variable * variable){
    Variable * current = produce();
    if(current == NULL){
        return FactoryVariable::produceUndefined();
    }

    return current->neq(variable);
}

std::string NextVariable::toString(){
    Variable * variable = object_get(object, hash);
    if(variable == NULL){
        return object->getClass()->name() + " " + _value;
    } else {
        return variable->toString();
    }
}

NextVariable::~NextVariable(){
    
}
