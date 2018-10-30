#ifndef TRACE_LIST_H
#define TRACE_LIST_H

#include <vector>

class Trace;
class Stack;
class Variable;

class TraceList {
  
    public:        
        int size; //traces size
        Stack * stack;
        Trace * current;
        std::vector <Trace*> * traces;
        Variable * exception;
        
};

#include "./Trace.h"

#endif