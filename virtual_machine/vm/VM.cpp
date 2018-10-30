#include "VM.h"
#include "./var/DataVariable.h"
#include "trace/TraceList.h"

VM * vm = NULL;
VM * VM::instance = NULL;

void VM::init(){
    instance = new VM();
    instance->getMutex().init();
    instance->threadSize = 10;
    instance->traces = new TraceList * [instance->threadSize];
    for(int i = 0; i < instance->threadSize; i++){
        instance->traces[i] = NULL;
    }

    IntSystem::init();
    FactoryVariable::init();
}

std::string VM::runThreadMain(std::string clsName, std::string methodName){
    Class * cls = this->classes[clsName];
    Method * method = cls->getMethod("main");

    threadCurrentId  = 0;

    TraceList * list = new TraceList();
    list->traces     = new std::vector<Trace*>();
    list->current    = new Trace(method, NULL, NULL);
    list->stack      = list->current->stack;
    list->size       = 1;
    list->exception  = NULL;

    addTraces(list);
    list->traces->push_back(list->current);

    if(!commandLineArguments.empty() && !method->getArguments().empty()){
        ObjectVariable * array = FactoryVariable::produceObject(getClass(std::string("Array")));
        for(unsigned int i = 0; i < commandLineArguments.size(); i++){
            StringVariable *arg = FactoryVariable::produceString(commandLineArguments[i]);
            array->set(str_to_int_hash(std::to_string(i)), arg);
        }
        list->current->getLocal()->set(str_to_int_hash(method->getArguments()[0]), array);
    }

    std::string ret = TraceExecute::all(list);

    return ret;
}

int VM::loadDirectory(std::map <std::string, Class*> & map, std::string path){
    if(access(path.c_str(), F_OK) == -1){
        return -1;
    }

    ProjectReader projectReader;
    std::map <std::string, Class*> classesFromDir = projectReader.read(path);
    map.insert(classesFromDir.begin(), classesFromDir.end());
    projectReader.refreshRelations(map);
    return classesFromDir.size();
}

int VM::loadProject(std::string path){
    return loadDirectory(classes, path);
}

int VM::loadLibrary(std::string path){
    return loadDirectory(sand, path);
}

Mutex & VM::getMutex(){
    return mutex;
}

VM * VM::getInstance(){
    return instance;
}

Class * VM::getClass(std::string name){
    Class * cls = NULL;
    auto it = sand.find(name);
    if(it == sand.end()){
        it = classes.find(name);
        if(it != classes.end()){
            cls = it->second;
        }
    } else {
        cls = it->second;
    }

    return cls;
}

TraceList * VM::getCurrentThreadTraces(){
    return this->traces[0];
}

void VM::addTraces(TraceList * traceList){
    this->traces[0] = traceList;
}

void VM::pushCommandLineArgument(std::string argument){
    commandLineArguments.push_back(argument);
}

void VM::pushCommandLineArguments(int argc, char ** argv){
    for(int i = 0; i < argc; i++){
        pushCommandLineArgument(std::string(argv[i]));
    }
}

VM::~VM(){
    for (std::map<std::string,Class*>::iterator it=classes.begin(); it!=classes.end(); ++it){
        Class * cls = it->second;
        delete cls;
    }

    for (std::map<std::string,Class*>::iterator it=sand.begin(); it!=sand.end(); ++it){
        Class * cls = it->second;
        delete cls;
    }

    for(int i = 0; i < threadSize; i++){
        TraceList * traceList = traces[i];
        if(traceList != NULL){
            delete traces[i];
        }
    }

    delete [] traces;

    FactoryVariable::clear();
    InstructionFactory::free();
    IntSystem::clear();
}
