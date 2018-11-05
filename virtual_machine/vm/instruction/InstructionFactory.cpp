#include "InstructionFactory.h"

std::map <std::string, Instruction*> * InstructionFactory::instructions = NULL;

Instruction * InstructionFactory::produce(std::vector <std::string> mnemonics){
    if(instructions == NULL){
        instructions = new std::map<std::string, Instruction*>;
        instructions->insert(std::pair<std::string,Instruction*>(std::string("CLASS"),    new ClassInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("METHOD"),   new MethodInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("ARGS"),     new ArgsInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("PUSH"),     new PushInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("MOV"),      new MovInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("CEND"),     new CendInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("NEXT"),     new NextInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("CALL"),     new CallInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("RET"),      new RetInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("IMPORT"),   new ImportInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("NEW"),      new NewInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("ADD"),      new AddInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("AND"),      new AndInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("OR"),       new OrInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("IF"),       new IfInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("JMP"),      new JmpInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("EQ"),       new EqInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("NEQ"),      new NeqInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("GT"),       new GtInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("GTE"),      new GteInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("LT"),       new LtInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("LTE"),      new LteInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("IFEND"),    new IfEndInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("ELIFEND"),  new ElifEndInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("ELIF"),     new ElifInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("ELSE"),     new ElseInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("IFENDALL"), new IfEndAllInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("FOR"),      new ForInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("FORIF"),    new ForIfInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("FORBODY"),  new ForBodyInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("FORLOOP"),  new ForLoopInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("FOREND"),   new ForEndInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("INC"),      new IncInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("DEC"),      new DecInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("MUL"),      new MulInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("SUB"),      new SubInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("POW"),      new PowInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("DIV"),      new DivInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("TRY"),      new TryInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("CATCH"),    new CatchInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("CATCHEND"), new CatchEndInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("THROW"),    new ThrowInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("WHILE"),    new WhileInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("WHILEIF"),  new WhileIfInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("WHILEEND"), new WhileEndInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("BREAK"),    new BreakInstruction()));
        instructions->insert(std::pair<std::string,Instruction*>(std::string("CONTINUE"), new ContinueInstruction()));
    }

    Instruction * instruction = instructions->find(mnemonics[0])->second;
    if(instruction == NULL){
        std::cout<<"no such instruction "<<mnemonics[0]<<std::endl;
        return NULL;
    }

    instruction = instruction->fromList(mnemonics);
    instruction->setType(mnemonics[0]);

    return instruction;
}

void InstructionFactory::free(){
    std::map<std::string, Instruction*>::iterator i;
    for(i = instructions->begin(); i != instructions->end(); i++){
        delete i->second;
    }

    delete instructions;
}
