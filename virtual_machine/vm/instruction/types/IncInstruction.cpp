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
    var->inc();
    current->position++;
}

std::string IncInstruction::toString(){
    return "INC";
}

bool IncInstruction::getBeforeUse(){
    return beforeUse;
}

void IncInstruction::setBeforeUse(bool beforeUse){
    this->beforeUse = beforeUse;
}
