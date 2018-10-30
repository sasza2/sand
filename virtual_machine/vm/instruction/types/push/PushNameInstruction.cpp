#include "PushNameInstruction.h"

PushNameInstruction::PushNameInstruction(std::string value){
    this->value = value;
    hash = str_to_int_hash(value);    
    _thisHash = str_to_int_hash(std::string("this"));    
    isThis = hash == _thisHash;
}

void PushNameInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;
        
    if(isThis){ //value == "this"
        current->getThis()->usage++;
        PUSH(stack, current->getThis());        
    } else {        
        PUSH(stack, ret);
    }
        
    current->position++;
}

std::string PushNameInstruction::toString(){
    return "PUSH S " + value;
}

void PushNameInstruction::refresh(Method * method){
    this->method = method;
    Class * cls = vm->getClass(value);
    if(cls == NULL){
        ret = FactoryVariable::produceName(value);
    } else {
        ret = FactoryVariable::produceClass(cls);
    }
    ret->readOnly = true;
}

PushNameInstruction::~PushNameInstruction(){
    delete ret;
}