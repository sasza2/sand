#include "BooleanVariable.h"

BooleanVariable::BooleanVariable(bool value){
    this->_value = value;
}

int BooleanVariable::type(){
    return BOOLEAN;
}

bool BooleanVariable::getValue(){
    return _value;
}

Variable * BooleanVariable::sum(Variable * variable){
    if(variable->type() == INT){
        IntegerVariable * integerVariable = (IntegerVariable*)variable;
        return FactoryVariable::produceInteger(_value + integerVariable->getValue());
    } else if(variable->type() == STRING){
        std::ostringstream ss;
        ss << _value;
        StringVariable * stringVariable = (StringVariable*)variable;
        return FactoryVariable::produceString(stringVariable->value() + ss.str());
    } else if(variable->type() == DOUBLE){
        DoubleVariable * doubleVariable = (DoubleVariable*)variable;
        return FactoryVariable::produceDouble((double)_value + doubleVariable->getValue());
    } else if(variable->type() == NAME){
        return ((NameVariable*)variable)->sum(this);
    } else if(variable->type() == BOOLEAN){
        Number * number = variable->toNumber();
        return FactoryVariable::produceInteger(_value + number->value());
    }
    
    return FactoryVariable::produceUndefined();
}

Variable * BooleanVariable::_and(){
    return _value ? FactoryVariable::produceTrue() : FactoryVariable::produceFalse();
}

Variable * BooleanVariable::_or(){
    return _value ? FactoryVariable::produceTrue() : FactoryVariable::produceFalse();
}

Variable * BooleanVariable::inc(){
    return FactoryVariable::produceUndefined();
}

std::string BooleanVariable::toString(){
    return _value ? "true" : "false";
}

Variable * BooleanVariable::copy(){
    return this;
}