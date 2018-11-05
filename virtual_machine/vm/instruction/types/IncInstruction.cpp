#include "./IncInstruction.h"

Instruction * IncInstruction::fromList(std::vector <std::string> mnemonics){
    IncInstruction * instruction = new IncInstruction();
    instruction->setBeforeUse(mnemonics[1] == "1");
    return instruction;
}

void IncInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack = current->stack;

    Variable * var = POP(stack);

    if(var->type() == NAME){
        NameVariable * name = (NameVariable*)var;
        Variable * tmp = name->produceFromLocal();
        if(tmp != NULL){
            FREE(&name);
            var = tmp;
        }
    }

    PUSH(stack, var);

    if(beforeUse || var->change){
        if(var->type() == INT){
            ((IntegerVariable*)var)->_value++;
        } else if(var->type() == DOUBLE){
            ((DoubleVariable*)var)->_value++;
        }
    } else {
        var->change = 1;
    }

    var->usage++;
    current->position++;
}

std::string IncInstruction::toString(){
    return beforeUse ? "INC 1" : "INC 0";
}

bool IncInstruction::getBeforeUse(){
    return beforeUse;
}

void IncInstruction::setBeforeUse(bool beforeUse){
    this->beforeUse = beforeUse;
}
