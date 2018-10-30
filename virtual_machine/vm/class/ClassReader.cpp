#include "ClassReader.h"

Class * ClassReader::fromFile(std::string path){
    FILE * handle = fopen(path.c_str(), "r");
    if (handle == NULL) {
        return NULL;
    }

    fseek(handle, 0L, SEEK_END);
    long len = ftell(handle);
    fseek(handle, 0L, SEEK_SET);

    char * buff = (char*)malloc(len + 1);
    buff[len] = 0;
    fread(buff, 1, len, handle);

    Class * cls = fromStr(buff);

    free(buff);
    fclose(handle);

    return cls;
}

Class * ClassReader::fromStr(std::string code){
    Class * cls = new Class();
    std::vector <Instruction*> instructions = produceInstructions(code);

    Method * method;
    for(unsigned int i = 0; i < instructions.size(); i++){
        Instruction * instruction = instructions[i];
        if(instruction->type() == "CLASS"){
            cls->setName(((ClassInstruction*)instruction)->getName());
            delete instruction;
            continue;
        } else if(instruction->type() == "METHOD"){
            method = new Method(((MethodInstruction*)instruction)->getName(), cls);
            cls->pushMethod(method);
            delete instruction;
            continue;
        } else if(instruction->type() == "ARGS"){
            method->pushArguments(((ArgsInstruction*)instruction)->getArgs());
            delete instruction;
            continue;
        } else if(instruction->type() == "IMPORT"){
            ImportInstruction * importInstruction = (ImportInstruction*)instruction;
            cls->pushImportRelation(importInstruction->getPath(), importInstruction->getName());
            delete instruction;
            continue;
        } else {
            method->pushInstruction(instruction);
        }
    }

    cls->pushImportRelation(cls->name(), cls->name());
    return cls;
}

std::vector <Instruction*> ClassReader::produceInstructions(std::string code){
    std::vector <Instruction*> instructions;

    std::vector <std::string> lines = split(code, '\n');
    for(unsigned int i = 0; i < lines.size(); i++){
        Instruction * instruction = InstructionFactory::produce(split(lines[i], ' '));
        if(instruction != NULL){
            instructions.push_back(instruction);
        }
    }

    return instructions;
}

std::vector <std::string> ClassReader::split(std::string code, char delimiter){
    std::vector <std::string> lines;

    std::string cur;
    int len = code.length();
    for(int i = 0; i < len; i++){
        char c = code[i];
        if(c == delimiter){
            lines.push_back(cur);
            cur.clear();
            continue;
        } else if(i + 1 == len){
            cur.push_back(c);
            lines.push_back(cur);
            continue;
        }

        cur.push_back(c);
    }
    cur.clear();

    if(code[code.length() - 1] == ' '){
        lines.push_back("");
    }

    return lines;
}

void ClassReader::refresh(Class * cls){
    std::vector <Method*> methods = cls->getAllMethods();
    for(unsigned int i = 0; i < methods.size(); i++){
        methods[i]->refresh();
    }
}
