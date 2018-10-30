#ifndef CLASS_H
#define CLASS_H 1

#include <map>
#include <vector>
#include <iostream>
#include "./../method/Method.h"

class ObjectVariable;

class Class {

    private:
        std::string _name, nameExtends;
        Class * extends;
        std::map <std::string, Method*> methods;
        std::map <std::string, Class*> imports;
        std::map <std::string, std::string> importsRelation;
    public:
        ObjectVariable * _static;
        
        Class();
        
        std::string name();
        void setName(std::string name);
        
        void pushMethod(Method * method);
        Method * getMethod(std::string name);
        std::vector <Method*> getAllMethods();
        
        void pushImportRelation(std::string path, std::string name);
        void updateRelations();
        Class * getImport(std::string name);
        
        ~Class();
        
};

#include "./../VM.h"

#endif
