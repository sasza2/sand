#include "IntSystem.h"

void ConsoleWritelnCommand::call(std::vector <Variable*> arguments){
    VM::getInstance()->getMutex().lock(LOCK_CONSOLE);    
    Variable * text = arguments[0];
        
    if(text->type() == STRING){
        StringVariable * str = (StringVariable*)text;
        std::cout<<str->value()<<std::endl;
    } else if(text->type() == OBJECT){
        TraceList * traceList = VM_MY_THREAD_LIST();
        std::vector <Trace*> * traces = traceList->traces;
        ObjectVariable * object = (ObjectVariable*)text;
        
        Method * toString;
        if(object->getClass()->name() == "Exception" && traces->empty()){
            toString = object->getClass()->getMethod("print");
        } else {
            toString = object->getClass()->getMethod("toString");
        }
                
        if(toString == NULL){
            std::cout<<text->type()<<std::endl;
        } else {
            Trace * trace = new Trace(toString, NULL, object);
            traces->push_back(trace);
            traceList->size++;
            TraceExecute::once(traces);            
            
            std::vector <Trace*> * traces = VM::getInstance()->getCurrentThreadTraces()->traces;
            if(traces->empty()){                
                return;
            }
            
            trace = traces->back();
            if(trace == NULL){
                return;
            }

            Variable * variableFromString = POP(trace->stack);
            std::cout<<variableFromString->toString()<<std::endl;
            FREE(&variableFromString);
        }
    } else if(text->type() == INT){
        IntegerVariable * integerVariable = (IntegerVariable*)text;
        std::cout<<integerVariable->getValue()<<std::endl;
    } else {        
        std::cout<<text->toString()<<std::endl;
    }
    VM::getInstance()->getMutex().unlock(LOCK_CONSOLE);
}
