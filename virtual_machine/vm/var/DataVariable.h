#ifndef DATA_VARIABLE_H
#define DATA_VARIABLE_H

#include <string>
#include "UndefinedVariable.h"

class DataVariable : public UndefinedVariable {
    
    private:
        void * data;
    
    public:
        DataVariable(void * data);
        int type();
        std::string toString();
        void * getData();
        
};

#endif