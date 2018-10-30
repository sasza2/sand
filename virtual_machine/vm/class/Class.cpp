#include "Class.h"

Class::Class(){
    _static = FactoryVariable::produceObject(this);
    _static->readOnly = true;
}

std::string Class::name(){
    return this->_name;
}

void Class::setName(std::string name){
    this->_name = name;
}

void Class::pushMethod(Method * method){
    methods[method->getName()] = method;
}

Method * Class::getMethod(std::string name){
    return methods[name];
}

std::vector <Method*> Class::getAllMethods(){
    std::vector <Method*> all;
    std::map<std::string, Method*>::iterator i;
    for(i = methods.begin(); i != methods.end(); i++){
        all.push_back(i->second);
    }
    return all;
}

void Class::pushImportRelation(std::string path, std::string name){
    importsRelation[path] = name;
}

void Class::updateRelations(){
    VM * vm = VM::getInstance();
    
    std::map<std::string, std::string>::iterator i; //path -> name
    for(i = importsRelation.begin(); i != importsRelation.end(); i++){
        imports[i->second] = vm->getClass(i->first);
    }
}

Class * Class::getImport(std::string name){
    return imports[name];
}

Class::~Class(){
    for (std::map<std::string,Method*>::iterator it=methods.begin(); it!=methods.end(); ++it){
        delete it->second;
    }
    delete _static;
}