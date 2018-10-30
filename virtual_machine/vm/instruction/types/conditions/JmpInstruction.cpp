#include "Conditions.h"

Instruction * JmpInstruction::fromList(std::vector <std::string> mnemonics){
    JmpInstruction * instruction = new JmpInstruction();
    instruction->setLevel(atoi(mnemonics[1].c_str()));
    return instruction;
}

void JmpInstruction::execute(){
    Trace * current = VM_MY_TRACE();
    Stack * stack   = current->stack;
    Variable * boolean = POP(stack);
    if(boolean->type() == BOOLEAN && ((BooleanVariable*)boolean)->getValue() > 0){        
        current->position++;
    } else {
        current->position = nextPosition;
    }
    FREE(&boolean);
}

std::string JmpInstruction::toString(){
    return "JMP " + std::to_string(getLevel());
}

void JmpInstruction::refresh(Method * method){
    InstructionPosFinder finder;
    nextPosition = finder.addMethod(method)
                         .addPosition(positionInMethod)
                         .addLevel(getLevel())
                         .addType("ELIF")
                         .addType("ELSE")
                         .addType("IFENDALL")                         
                         .find();
}