#include "IntSystem.h"

std::map <std::string, IntCommand*> * IntSystem::commands = NULL;

void IntSystem::init(){
    commands = new std::map<std::string, IntCommand*>();
    commands->insert(std::pair<std::string,IntCommand*>(std::string("console+writeln"),  new ConsoleWritelnCommand()));
    commands->insert(std::pair<std::string,IntCommand*>(std::string("thread+start"),     new ThreadStartCommand()));
    commands->insert(std::pair<std::string,IntCommand*>(std::string("thread+sleep"),     new ThreadSleepCommand()));
    commands->insert(std::pair<std::string,IntCommand*>(std::string("thread+id"),        new ThreadIdCommand()));
    commands->insert(std::pair<std::string,IntCommand*>(std::string("thread+wait"),      new ThreadWaitCommand()));
    commands->insert(std::pair<std::string,IntCommand*>(std::string("math+random"),      new MathRandomCommand()));
    commands->insert(std::pair<std::string,IntCommand*>(std::string("console+readln"),   new ConsoleReadlnCommand()));
    commands->insert(std::pair<std::string,IntCommand*>(std::string("date+time"),        new DateUnixMsCommand()));
    commands->insert(std::pair<std::string,IntCommand*>(std::string("string+length"),    new StringLengthCommand()));
}

void IntSystem::call(std::vector <Trace*> * traces, std::vector <Variable*> arguments){
    Trace * trace = traces->back();
    if(arguments.size() < 2){
        PUSH(trace->stack, FactoryVariable::produceUndefined());
        return;
    }

    if(arguments[0]->type() != STRING || arguments[1]->type() != STRING){
        PUSH(trace->stack, FactoryVariable::produceUndefined());
        return;
    }

    IntCommand * command = commands->find(((StringVariable*)arguments[0])->value() + "+" + ((StringVariable*)arguments[1])->value())->second;
    if(command == NULL){
        PUSH(trace->stack, FactoryVariable::produceUndefined());
        return;
    }

    std::vector <Variable*> commandArguments;
    for(unsigned int i = 2; i < arguments.size(); i++){
        commandArguments.push_back(arguments[i]);
    }

    command->call(commandArguments);

    for(unsigned int i = 0; i < arguments.size(); i++){
        FREE(&arguments[i]);
    }
}

void IntSystem::clear(){
    for (std::map<std::string,IntCommand*>::iterator it=commands->begin(); it!=commands->end(); ++it){
        delete it->second;
    }

    delete commands;
}

IntCommand::~IntCommand(){

}
