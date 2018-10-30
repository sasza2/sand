#include "FactoryVariable.h"

UndefinedVariable * FactoryVariable::undefined = NULL;
BooleanVariable   * FactoryVariable::_false    = NULL;
BooleanVariable   * FactoryVariable::_true     = NULL;

void FactoryVariable::init(){
    undefined = new UndefinedVariable();
    undefined->readOnly = true;

    _false    = new BooleanVariable(false);
    _false->readOnly = true;

    _true     = new BooleanVariable(true);
    _true->readOnly = true;

    #if DEBUG == 1
        std::cout<<"variable add undefined "<<undefined<<std::endl;
        std::cout<<"variable add boolean "<<_false<<std::endl;
        std::cout<<"variable add boolean "<<_true<<std::endl;
    #endif
}

ObjectVariable * FactoryVariable::produceException(std::string name, std::string message){
    ObjectVariable * exception = produceObject(VM::getInstance()->getClass("Exception"));
    exception->set(str_to_int_hash(std::string("name")), new StringVariable(name));
    exception->set(str_to_int_hash(std::string("message")), new StringVariable(message));
    return exception;
}

ObjectVariable * FactoryVariable::produceObject(Class * cls){
    ObjectVariable * variable = new ObjectVariable(cls);
    #if DEBUG == 1
        std::cout<<"variable add object "<<variable<<std::endl;
    #endif
    return variable;
}

UndefinedVariable * FactoryVariable::produceUndefined(){
    return undefined;
}

IntegerVariable * FactoryVariable::produceInteger(long value){
    IntegerVariable * variable = new IntegerVariable(value);
    #if DEBUG == 1
        std::cout<<"variable add integer "<<variable<<std::endl;
    #endif
    return variable;
}

BooleanVariable * FactoryVariable::produceFalse(){
    return _false;
}

BooleanVariable * FactoryVariable::produceTrue(){
    return _true;
}

BooleanVariable * FactoryVariable::produceBoolean(bool value){
    return value ? _true : _false;
}

DoubleVariable * FactoryVariable::produceDouble(double value){
    DoubleVariable * variable = new DoubleVariable(value);
    #if DEBUG == 1
        std::cout<<"variable add double "<<variable<<std::endl;
    #endif
    return variable;
}

StringVariable * FactoryVariable::produceString(std::string value){
    StringVariable * variable = new StringVariable(value);
    #if DEBUG == 1
        std::cout<<"variable add string "<<variable<<" "<<variable->toString()<<std::endl;
    #endif
    return variable;
}

NextVariable * FactoryVariable::produceNext(std::string name, ObjectVariable * obj){
    NextVariable * variable = new NextVariable(name, obj);
    #if DEBUG == 1
        std::cout<<"variable add next "<<variable<<std::endl;
    #endif
    return variable;
}

ClassVariable * FactoryVariable::produceClass(Class * cls){
    ClassVariable * variable = new ClassVariable(cls);
    #if DEBUG == 1
        std::cout<<"variable add class "<<variable<<std::endl;
    #endif
    return variable;
}

NameVariable * FactoryVariable::produceName(std::string name){
    NameVariable * variable = new NameVariable(name);
    #if DEBUG == 1
        std::cout<<"variable add name "<<variable<<std::endl;
    #endif
    return variable;
}

ObjectVariable * FactoryVariable::produceFromPrimitive(Variable * variable){
    Class * cls;
    int type = variable->type();
    switch(type){
        case INT:
            cls = vm->getClass("Integer");
            break;
        case STRING:
            cls = vm->getClass("String");
            break;
        case DOUBLE:
            cls = vm->getClass("Double");
            break;
        case BOOLEAN:
            cls = vm->getClass("Boolean");
            break;
        default:
            cls = NULL;
    }

    if(cls == NULL){
        return NULL;
    }

    ObjectVariable * obj = produceObject(cls);
    obj->set(str_to_int_hash("value"), variable);
    return obj;
}

void FactoryVariable::clear(){
    delete undefined;
    delete _true;
    delete _false;
}
