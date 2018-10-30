#include "ImportInstruction.h"

Instruction * ImportInstruction::fromList(std::vector <std::string> mnemonics){
    ImportInstruction * instruction = new ImportInstruction();
    instruction->setName(mnemonics[1]);

    std::string path = "";
    path.reserve(1024);
    for(unsigned int i = 2; i < mnemonics.size(); i++){
        if(!path.empty()){
            path += std::string(" ");
        }
        path += mnemonics[i];
    }
    instruction->setPath(path);

    return instruction;
}

void ImportInstruction::execute(){

}

std::string ImportInstruction::getName(){
    return name;
}

void ImportInstruction::setName(std::string name){
    this->name = name;
}

std::string ImportInstruction::getPath(){
    return path;
}

void ImportInstruction::setPath(std::string path){
    this->path = path;
}

std::string ImportInstruction::toString(){
    return "IMPORT " + name + " FROM \"" + path + "\"";
}
