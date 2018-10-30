#include <iostream>
#include <vector>
#include <string>
#include "vm/instruction/InstructionFactory.h"
#include "vm/instruction/Instruction.h"
#include "vm/instruction/types/MovInstruction.h"
#include "vm/class/ClassReader.h"
#include "vm/VM.h"
#include <time.h>

int main(int argc, char ** argv){
    if(argc < 4){
        puts("Empty arguments: path to library, path to project, main class");
        return 1;
    }

    struct timespec ts;
    timespec_get(&ts, TIME_UTC);

    srand(ts.tv_nsec);

    VM::init();
    vm = VM::getInstance();
    if(vm->loadLibrary(std::string(argv[1]) + std::string("target/")) < 0){
        std::cout<<"Library path does not exist"<<std::endl;
        return 1;
    }

    if(vm->loadProject(std::string(argv[2]) + std::string("target/")) < 0){
        std::cout<<"Project path does not exist"<<std::endl;
        return 2;
    }
    vm->pushCommandLineArguments(argc, argv);
    vm->runThreadMain(std::string(argv[3]), "main");

    delete vm;

    return 0;
}
