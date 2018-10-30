#ifndef TRACE_EXCEPTION_H
#define TRACE_EXCEPTION_H

#include <vector>
#include "./TraceList.h"

class TraceException {
 
    public:
        static void catchIt(TraceList * traceList);
    
};

#endif
