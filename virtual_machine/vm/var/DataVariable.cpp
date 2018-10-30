#include "DataVariable.h"

DataVariable::DataVariable(void * data){
    this->data = data;
}

int DataVariable::type(){
    return DATA;
}

std::string DataVariable::toString(){
    return "data";
}

void * DataVariable::getData(){
    return data;
}