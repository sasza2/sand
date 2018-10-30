#include "TraceException.h"

void TraceException::catchIt(TraceList * traceList){    
    while(traceList->size > 0){
        Trace * trace = traceList->current;
        int position = trace->getExceptions().last();
        if(position == -1){
            traceList->traces->pop_back();
            delete trace;
            traceList->size--;
            if(traceList->size == 0){
                traceList->current = NULL;
                traceList->stack   = NULL;
            } else {                
                traceList->current = traceList->traces->back();
                traceList->stack   = traceList->current->stack;
            }
        } else {
            break;
        }
    }            
}
