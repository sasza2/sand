#ifndef TRACE_EXECUTE_H
#define TRACE_EXECUTE_H

#include <string>
#include <vector>
#include <map>
#include "./../trace/TraceList.h"
#include "./../var/ObjectVariable.h"

class TraceExecute {

    private:
        static void print(Trace * trace, Instruction * instruction);

    public:
        static std::string all(TraceList * traceList);
        static Variable * once(std::vector <Trace*> * traces);

};

#include "./../instruction/types/RetInstruction.h"

#endif
