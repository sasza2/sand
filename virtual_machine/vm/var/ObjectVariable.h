#ifndef OBJECT_VARIABLE_H
#define OBJECT_VARIABLE_H

#include <map>
#include <vector>
#include <string>
#include "./Variable.h"
#include "./../class/Class.h"

class ObjectVariable : public Variable {
    
    private:
        Class * cls;                
        int keyPosition(long);
        
    public:
        long * keys;
        Variable ** variables;        
        int size;
        
        ObjectVariable(Class * cls);
        Variable * get(long name);
        ObjectVariable * set(long name, Variable * variable);
        int type();
        Class * getClass();
        Variable * sum(Variable * variable);
        
        virtual Variable * eq(Variable * variable);
        virtual Variable * neq(Variable * variable);
        
        std::string toString();
        
        Variable * _and();
        Variable * _or();
        
        ~ObjectVariable();
};

inline int object_key_position(ObjectVariable * obj, long key){    
    int size = obj->size;
    long * keys = obj->keys;
    for(int i = 0; i < size; i++){
        if(keys[i] == key){
            return i;
        }
    }
    return -1;
}

inline Variable * object_get(ObjectVariable * obj, long key){
    int size = obj->size;        
    long * keys = obj->keys;    
    
    int i;    
    for(i = 0; i < size && keys[i] != key; i++);
                
    return i == size ? NULL : obj->variables[i];
}

#endif