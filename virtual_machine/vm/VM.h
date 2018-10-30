#ifndef VM_H
#define VM_H

#include <map>
#include <string>
#include <iostream>
#include <pthread.h>
#include "./class/Class.h"
#include "./trace/TraceList.h"
#include "./class/ProjectReader.h"
#include "./trace/TraceExecute.h"
#include "./mutex/Mutex.h"

#define VM_MY_THREAD_LIST() vm->traces[vm->threadCurrentId];
#define VM_MY_TRACE() vm->traces[vm->threadCurrentId]->current;
#define VM_MY_TRACE_POS_INC() vm->traces[vm->threadCurrentId]->current->position++;

class VM {
    
    private:        
        std::map <std::string, Class*> classes;
        //built in classes like Array, Console, String
        std::map <std::string, Class*> sand; 
        //trace
        std::vector <std::string> commandLineArguments;     
        
        //mutex
        Mutex mutex;
        
        int loadDirectory(std::map <std::string, Class*> & map, std::string path);
        
    public:
        TraceList ** traces;
        int threadCurrentId;
        int threadSize;
        
        static void init();
        static VM * instance;
        std::string runThreadMain(std::string clsName, std::string methodName);
        //void runThread(ObjectVariable * thread);
        int loadProject(std::string path);
        int loadLibrary(std::string path);
        Class * getClass(std::string name);
        
        TraceList * getCurrentThreadTraces();
        
        void addTraces(TraceList * traceList);
        
        Mutex & getMutex();
        
        void pushCommandLineArgument(std::string argument);
        void pushCommandLineArguments(int argc, char ** argv);
        
        static VM * getInstance();
        
        ~VM();
};

extern VM * vm;

#endif
