#include "NewInstruction.h"

Instruction * NewInstruction::fromList(std::vector <std::string> mnemonics){
    NewInstruction * instruction = new NewInstruction();
    instruction->setArguments(atoi(mnemonics[1].c_str()));
    instruction->setName(mnemonics[2]);
    return instruction;
}

void NewInstruction::execute(){
    TraceList * traceList = VM_MY_THREAD_LIST();
    std::vector <Trace*> * traces = traceList->traces;
    Trace * current = traceList->current;
    Stack * stack = current->stack;
    
    Class * cls = current->getMethod()->getClass()->getImport(getName());
    if(cls == NULL){
        cls = VM::getInstance()->getClass(getName());
    }
    
    if(cls == NULL){
        traceList->exception = FactoryVariable::produceException("new", "no such class " + getName());
        TraceException::catchIt(traceList);
        return;
    }
        
    ObjectVariable * object = FactoryVariable::produceObject(cls);
    
    Method * method = cls->getMethod("constructor");
    if(method != NULL){
        /*
         * NULL 'cause it's constructor method
         * to create this (ObjectVariable*)
         */
        Trace * trace = new Trace(method, NULL, object); 
        traceList->size++;
        CallInstruction call(getArguments(), "");
        traces->push_back(call.rewriteArguments(trace, call.produceArguments(current)));        
    } 
        
    PUSH(stack, object);
    current->position++;
}
    
int NewInstruction::getArguments(){
    return arguments;
}
  
void NewInstruction::setArguments(int arguments){
    this->arguments = arguments;
}
        
std::string NewInstruction::getName(){
    return name;
}

void NewInstruction::setName(std::string name){
    this->name = name;
}

std::string NewInstruction::toString(){   
    return "NEW " + std::to_string(arguments) + std::string(" ") + name;
}