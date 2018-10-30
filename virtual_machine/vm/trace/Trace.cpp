#include "Trace.h"

Trace::Trace(Method * method, Trace * from, ObjectVariable * _this){
    this->stack    = new Stack();
    this->method   = method;
    this->position = 0;
    this->local   = FactoryVariable::produceObject(method->getClass());
    
    if(_this == NULL){
        if(from == NULL){
            this->_this = FactoryVariable::produceObject(method->getClass());
        } else {
            this->_this = from->getThis();
            this->_this->usage++;
        }
    } else {
        this->_this = _this;
        _this->usage++;
    }
}

ObjectVariable * Trace::getThis(){
    return _this;
}

void Trace::setThis(ObjectVariable * _this){
    this->_this = _this;
}

ObjectVariable * Trace::getLocal(){
    return local;
}

size_t Trace::getPosition(){
    return this->position;
}

void Trace::nextPosition(int position){
    this->position = position;
}

void Trace::nextPosition(){
    position++;
}

Method * Trace::getMethod(){
    return method;
}

Exceptions & Trace::getExceptions(){
    return exceptions;
}

Trace::~Trace(){
    FREE(&_this);
    delete local;
    delete stack;
}