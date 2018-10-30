#include "CallInstruction.h"

CallInstruction::CallInstruction(){

}

CallInstruction::CallInstruction(int arguments, std::string name){
    this->arguments = arguments;
    this->name = name;
}

Instruction * CallInstruction::fromList(std::vector <std::string> mnemonics){
    return new CallInstruction(atoi(mnemonics[1].c_str()), mnemonics[2]);
}

void CallInstruction::execute(){
    TraceList * traceList = VM_MY_THREAD_LIST();
    std::vector <Trace*> * traces = traceList->traces;
    Trace * current = traceList->current;

    std::vector <Variable*> argumentsList = produceArguments(current);
    if(name == "()"){
        Variable * var = POP(current->stack);
        NextVariable * next = (NextVariable*)var;
        if(!next->emptyValue()){
            Method * method = next->getObject()->getClass()->getMethod(next->value());
            if(method == NULL){
                traceList->exception = FactoryVariable::produceException("call", "no such method " +
                    next->value() + " in class " + next->getObject()->getClass()->name());
                TraceException::catchIt(traceList);
                return;
            }
            Trace * newTrace = new Trace(method, NULL, next->getObject());
            traces->push_back(rewriteArguments(newTrace, argumentsList));
            traceList->size++;
        }
        FREE(&var);
    } else {
        if(name == "system"){
            IntSystem::call(traces, argumentsList);
        } else {
            Trace * newTrace = new Trace(current->getMethod()->getClass()->getMethod(name), current, NULL);
            traces->push_back(rewriteArguments(newTrace, argumentsList));
            traceList->size++;
        }
    }

    current->position++;
}

std::vector <Variable*> CallInstruction::produceArguments(Trace * current){
    Stack * stack = current->stack;

    std::vector <Variable*> argumentsList;
    int i;
    for(i = 0; i < arguments; i++){
        Variable * variable = POP(stack);
        int type = variable->type();
        if(type == NEXT){
            NextVariable * next = (NextVariable*)variable;
            Variable * tmp = next->produce();
            variable = tmp == NULL ? variable : tmp;
            FREE(&next);
        } else if(type == NAME){
            NameVariable * name = (NameVariable*)variable;
            Variable * tmp = name->produceFromLocal();
            variable = (tmp == NULL) ? variable : tmp;
            FREE(&name);
        }
        argumentsList.push_back(variable->copy());

        switch(type){
            case INT:
            case STRING:
            case DOUBLE:
            case CLASS:
            case BOOLEAN:
                FREE(&variable);
                break;
        }
    }

    std::reverse(argumentsList.begin(),argumentsList.end());
    return argumentsList;
}

Trace * CallInstruction::rewriteArguments(Trace * current, std::vector <Variable*> argumentsList){
    Method * method = current->getMethod();
    for(unsigned int i = 0; i < argumentsList.size(); i++){
        if(method->getArguments().size() <= i){
            break;
        }
        std::string arg = method->getArguments()[i];
        current->getLocal()->set(str_to_int_hash(arg), argumentsList[i]);
    }
    return current;
}

std::string CallInstruction::toString(){
    return "CALL " + std::to_string(arguments) + std::string(" ") + name;
}
