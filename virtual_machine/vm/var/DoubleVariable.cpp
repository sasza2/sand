#include "DoubleVariable.h"

DoubleVariable::DoubleVariable(double value){
    this->_value = value;
}

int DoubleVariable::type(){
    return DOUBLE;
}

double DoubleVariable::getValue(){
    return _value;
}

Variable * DoubleVariable::sum(Variable * variable){
    if(variable->type() == INT){
        IntegerVariable * integerVariable = (IntegerVariable*)variable;
        return FactoryVariable::produceDouble((double)integerVariable->_value + _value);
    } else if(variable->type() == DOUBLE){
        DoubleVariable * doubleVariable = (DoubleVariable*)variable;
        return FactoryVariable::produceDouble(doubleVariable->getValue());
    } else if(variable->type() == STRING){
        std::ostringstream ss;
        ss << _value;
        StringVariable * stringVariable = (StringVariable*)variable;
        return FactoryVariable::produceString(stringVariable->value() + ss.str());
    } else if(variable->type() == NAME){
        return ((NameVariable*)variable)->sum(this);
    } else if(variable->type() == BOOLEAN){
        Number * number = variable->toNumber();
        return FactoryVariable::produceDouble(_value + number->value());
    }
    
    return FactoryVariable::produceUndefined();
}

Variable * DoubleVariable::_and(){
    return (long)_value == 0 ? FactoryVariable::produceFalse() : FactoryVariable::produceTrue();
}

Variable * DoubleVariable::_or(){
    return (long)_value == 0 ? FactoryVariable::produceFalse() : FactoryVariable::produceTrue();
}

std::string DoubleVariable::toString(){
    std::ostringstream ss;
    ss << _value;
    return ss.str();
}

Variable * DoubleVariable::copy(){
    return FactoryVariable::produceDouble(_value);
}