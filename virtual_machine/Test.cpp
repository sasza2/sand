#include <iostream>
#include <vector>
#include <string>
#include "vm/instruction/InstructionFactory.h"
#include "vm/instruction/Instruction.h"
#include "vm/instruction/types/MovInstruction.h"
#include "vm/class/ClassReader.h"
#include "vm/VM.h"
#include <time.h>

class Assert {
    public:
        std::string clsName;
        std::string expected;
};

std::string libraryPath;
std::string testingPath;

int test(Assert & as){
    VM::init();
    vm = VM::getInstance();
    vm->loadLibrary(libraryPath);
    vm->loadProject(testingPath);
    std::string ret = vm->runThreadMain(as.clsName, "main");

    //delete vm;

    if(as.expected != ret){
        std::cout<<"test for " + as.clsName + " failed: "<<ret<<std::endl;
        return 1;
    }

    return 0;
}

std::vector <Assert> tests_read(std::string testsFilePath){
    std::vector <Assert> tests;

    FILE * handle = fopen(testsFilePath.c_str(), "r");
    if(handle == NULL){
        std::cout<<"file "<<testsFilePath<<" does not exist"<<std::endl;
        return tests;
    }

    bool toAdd = false;

    std::string clsName  = "";
    std::string expected = "";

    char c;
    do {
        c = fgetc (handle);
        if(c == ':'){
            toAdd = !toAdd;
            continue;
        }

        if(c == '\n'){
            Assert as;
            as.clsName  = clsName;
            as.expected = expected;
            tests.push_back(as);
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

    fclose(handle);

    return tests;
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

    std::vector <Assert> tests = tests_read(argv[3]);
    for(unsigned int i = 0; i < tests.size(); i++){
        if(test(tests[i])){
            return 1;
        }
    }

    return 0;
}
