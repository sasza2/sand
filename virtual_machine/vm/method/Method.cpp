#include "Method.h"

Method::Method(std::string name, Class * cls){
    this->name = name;
    this->cls  = cls;
    instructions = new std::vector<Instruction*>();
}

void Method::pushArguments(std::string str){
    std::string arg = "";
    for(unsigned int i = 0; i < str.length(); i++){
        char c = str[i];
        if(c == ','){
            arguments.push_back(arg);
            arg.clear();
        } else {
            arg += c;
            if(i + 1 == str.length()){
                arguments.push_back(arg);
            }
        }
    }
}

std::vector <std::string> Method::getArguments(){
    return arguments;
}

void Method::pushInstruction(Instruction * instruction){
    this->instructions->push_back(instruction);
}

std::string Method::getName(){
    return name;
}

Instruction * Method::getInstruction(size_t position){
    return instructions->at(position);
}

std::vector <Instruction*> * Method::getInstructions(){
    return instructions;
}

Class * Method::getClass(){
    return cls;
}

void Method::refresh(){
    for(unsigned int i = 0; i < instructions->size(); i++){
        Instruction * instruction = instructions->at(i);
        instruction->setPositionInMethod(i);
        instruction->refresh(this);
    }
}

Method::~Method(){
    for(unsigned int i = 0; i < instructions->size(); i++){
        delete instructions->at(i);
    }
    delete instructions;
}
