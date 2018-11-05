#include "MovInstruction.h"

Instruction * MovInstruction::fromList(std::vector <std::string> mnemonics){
    return new MovInstruction();
}

void MovInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;

    Variable * what  = POP(stack);
    Variable * where = POP(stack);
    Variable * whereOld = where;

    Variable * tmp;
    if(what->type() == NAME){
        tmp = ((NameVariable*)what)->produceFromLocal();
    } else if(what->type() == NEXT){
        tmp = ((NextVariable*)what)->produce();
    } else {
        tmp = NULL;
    }

    if(tmp != NULL && tmp != what){
        FREE(&what);
        what = tmp;
    }

    Variable * old = NULL;
    what = what->copy();

    if(where->type() == NAME){
        NameVariable * name = (NameVariable*)where;
        old = current->getLocal()->get(name->getHash());
        current->getLocal()->set(name->getHash(), what);
    } else if(where->type() == NEXT){
        NextVariable * next = (NextVariable*)where;
        old = next->getObject()->get(next->getHash());
        next->getObject()->set(next->getHash(), what);
    }

    where->usage++;
    PUSH(stack, where);

    if(tmp != old && old != NULL){
        FREE(&old);
    }

    FREE(&whereOld);

    current->position++;
}

std::string MovInstruction::toString(){
    return "MOV";
}

bool MovInstruction::isMoveable(){
    return true;
}
