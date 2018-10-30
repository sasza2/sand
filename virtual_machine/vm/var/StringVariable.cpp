#include "StringVariable.h"
#include "IntegerVariable.h"
#include "UndefinedVariable.h"

StringVariable::StringVariable(std::string value){
    this->_value = value;
}

int StringVariable::type(){
    return STRING;
}

std::string StringVariable::value(){
    return _value;
}

Variable * StringVariable::sum(Variable * variable){
    if(variable->type() == STRING){
        StringVariable * stringVariable = (StringVariable*)variable;
        return FactoryVariable::produceString(stringVariable->value() + _value);
    } else if(variable->type() == INT){
        IntegerVariable * integerVariable = (IntegerVariable*)variable;
        std::ostringstream ss;
        ss << integerVariable->getValue();
        return FactoryVariable::produceString(ss.str() + _value);
    }
    return FactoryVariable::produceUndefined();
}

Variable * StringVariable::_and(){
    return FactoryVariable::produceUndefined();
}

Variable * StringVariable::_or(){
    return FactoryVariable::produceUndefined();
}
    
std::string StringVariable::toString(){
    return _value;
}