#ifndef TRACE_H
#define TRACE_H

#include <map>
#include "./../method/Method.h"
#include "./Exceptions.h"

class ObjectVariable;
class Variable;
class Stack;

class Trace {
    
    private:
        Method * method;                   
        Exceptions exceptions;
        
    public:
        ObjectVariable * _this;
        ObjectVariable * local;
        
        Stack * stack;
        size_t position;
        
        Trace(Method * method, Trace * from, ObjectVariable * _this);
    
        ObjectVariable * getThis();
        void setThis(ObjectVariable * _this);
        ObjectVariable * getLocal();
        
        size_t getPosition();
        void nextPosition(int position);
        void nextPosition();
        
        Method * getMethod();                
                
        Exceptions & getExceptions();
                
        ~Trace();
        
};

#include "./../var/ObjectVariable.h"
#include "./Stack.h"

#endif