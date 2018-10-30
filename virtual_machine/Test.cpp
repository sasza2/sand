#include <iostream>
#include <vector>
#include <string>
#include "vm/instruction/InstructionFactory.h"
#include "vm/instruction/Instruction.h"
#include "vm/instruction/types/MovInstruction.h"
#include "vm/class/ClassReader.h"
#include "vm/VM.h"
#include <time.h>

std::string libraryPath;
std::string testingPath;

void test(std::string clsName, std::string expected){
    VM::init();
    vm = VM::getInstance();
    vm->loadLibrary(libraryPath);
    vm->loadProject(testingPath);
    std::string ret = vm->runThreadMain(clsName, "main");

    //delete vm;

    if(expected != ret){
        std::cout<<"test for " + clsName + " failed: "<<ret<<std::endl;
    }
}

int main(int argc, char ** argv){
    if(argc < 4){
        std::cout<<"test file in arguments list is required"<<std::endl;
        return 1;
    }

    struct timespec ts;
    timespec_get(&ts, TIME_UTC);

    srand(ts.tv_nsec);

    libraryPath = std::string(std::string(argv[1]) + std::string("target/"));
    testingPath = std::string(std::string(argv[2]) + std::string("target/"));

    FILE * tests = fopen(argv[3], "r");
    if(tests == NULL){
        std::cout<<"file "<<argv[3]<<" does not exist"<<std::endl;
        return 2;
    }

    bool toAdd = false;

    std::string clsName  = "";
    std::string expected = "";

    char c;
    do {
        c = fgetc (tests);
        if(c == ':'){
            toAdd = !toAdd;
            continue;
        }

        if(c == '\n'){
            std::cout<<clsName<<" "<<clsName.size()<<" "<<expected<<" "<<expected.size()<<std::endl;
            test(clsName, expected);
            clsName  = "";
            expected = "";
            toAdd = !toAdd;
            continue;
        }

        if(toAdd){
            expected = expected + c;
        } else {
            clsName  = clsName  + c;
        }
    } while(c != EOF);

    fclose(tests);

    return 0;
}
