#include "NextInstruction.h"

Instruction * NextInstruction::fromList(std::vector <std::string> mnemonics){
    NextInstruction * instruction = new NextInstruction();
    if(mnemonics.size() > 1){
        instruction->setIn(true);
    } else {
        instruction->setIn(false);
    }
    return instruction;

}

void NextInstruction::execute(){
    TraceList * traceList = VM_MY_THREAD_LIST()
    executeEmptyName(traceList);
    if(traceList->current != NULL){
        traceList->current->position++;
    }
}

void NextInstruction::executeEmptyName(TraceList * traceList){
    Stack * stack = traceList->stack;

    Variable * name = POP(stack);
    Variable * obj  = POP(stack);

    Variable * nameOld = name;

    Variable * tmp;

    switch(obj->type()){
        case OBJECT:
            break;
        case CLASS:
            obj = ((ClassVariable*)obj)->getClass()->_static;
            break;
        case NAME:
            tmp = ((NameVariable*)obj)->produceFromLocal();
            if(tmp == NULL){
                traceList->exception = FactoryVariable::produceException("next", "local variable " + obj->toString() + " does not exist");
                TraceException::catchIt(traceList);
                return;
            } else {
                FREE(&obj);
            }
            obj = tmp;
            break;
        case NEXT:
            tmp = ((NextVariable*)obj)->produce();
            if(tmp == NULL || tmp->type() != OBJECT){
                traceList->exception = FactoryVariable::produceException("next", "local variable " + obj->toString() + " does not exist");
                TraceException::catchIt(traceList);
                return;
            } else {
                FREE(&obj);
                tmp->usage++;
            }
            obj = tmp;
            break;
        case STRING:
            obj = FactoryVariable::produceFromPrimitive(obj);
            break;
        default:
            traceList->exception = FactoryVariable::produceException("next", "call is not object");
            TraceException::catchIt(traceList);
            return;
    }

    ObjectVariable * objectVariable = (ObjectVariable*)obj;

    if(!in){
        if(name->type() == NAME){
            Variable * tmp = ((NameVariable*)name)->produceFromLocal();
            if(tmp != NULL){
                FREE(&name);
                name = tmp;
            }
        }
    }

    name = name->copy();

    NextVariable * next = FactoryVariable::produceNext(name->toString(), objectVariable);
    FREE(&name);
    PUSH(stack, next);

    FREE(&nameOld);
}

bool NextInstruction::isIn(){
    return in;
}

void NextInstruction::setIn(bool in){
    this->in = in;
}

std::string NextInstruction::toString(){
    return "NEXT" + std::string(in ? " IN" : "");
}
