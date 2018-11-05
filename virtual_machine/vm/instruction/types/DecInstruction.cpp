#include "./DecInstruction.h"

Instruction * DecInstruction::fromList(std::vector <std::string> mnemonics){
    DecInstruction * instruction = new DecInstruction();
    instruction->setBeforeUse(mnemonics[1] == "1");
    return instruction;
}

void DecInstruction::execute(){
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
            ((IntegerVariable*)var)->_value--;
        } else if(var->type() == DOUBLE){
            ((DoubleVariable*)var)->_value--;
        }
    } else {
        var->change = -1;
    }

    var->usage++;
    current->position++;
}

std::string DecInstruction::toString(){
    return beforeUse ? "DEC 1" : "DEC 0";
}

bool DecInstruction::getBeforeUse(){
    return beforeUse;
}

void DecInstruction::setBeforeUse(bool beforeUse){
    this->beforeUse = beforeUse;
}
