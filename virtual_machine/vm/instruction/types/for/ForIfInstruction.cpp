#include "For.h"

Instruction * ForIfInstruction::fromList(std::vector <std::string> mnemonics){
    ForIfInstruction * instruction = new ForIfInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));
    return instruction;
}

void ForIfInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;
    Variable * boolean = POP(stack);
    if(boolean->type() == BOOLEAN && ((BooleanVariable*)boolean)->getValue()){
        current->position = positionOnTrue;
    } else {
        current->position = positionOnFalse;
    }
    FREE(&boolean);
}

std::string ForIfInstruction::toString(){
    return "FORIF " + std::to_string(getLevel());
}

void ForIfInstruction::refresh(Method * method){
    InstructionPosFinder finder;
    positionOnTrue = finder.addMethod(method)
                           .addPosition(positionInMethod)
                           .addLevel(getLevel())
                           .addType("FORBODY")
                           .find() + 1;

    positionOnFalse = finder.clear()
                            .addMethod(method)
                            .addPosition(positionInMethod)
                            .addLevel(getLevel())
                            .addType("FOREND")
                            .find() + 1;
}
