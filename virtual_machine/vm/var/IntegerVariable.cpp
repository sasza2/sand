#include "IntegerVariable.h"

IntegerVariable::IntegerVariable(long value){
    this->_value = value;
}

int IntegerVariable::type(){
    return INT;
}

long IntegerVariable::getValue(){
    return _value;
}

Variable * IntegerVariable::sum(Variable * variable){
    int _type = variable->type();
    if(_type == INT){
        IntegerVariable * integerVariable = (IntegerVariable*)variable;
        return FactoryVariable::produceInteger(_value + integerVariable->getValue());
    } else if(_type == STRING){
        std::ostringstream ss;
        ss << _value;
        StringVariable * stringVariable = (StringVariable*)variable;
        return FactoryVariable::produceString(stringVariable->value() + ss.str());
    } else if(_type == DOUBLE){
        DoubleVariable * doubleVariable = (DoubleVariable*)variable;
        return FactoryVariable::produceDouble((double)_value + doubleVariable->getValue());
    } else if(_type == NAME){
        return ((NameVariable*)variable)->sum(this);
    } else if(_type == NEXT){
        NextVariable * next = (NextVariable*)variable;
        Variable * tmp = next->produce();
        if(tmp == NULL){
            return FactoryVariable::produceUndefined();
        }
        return sum(tmp);
    }

    return FactoryVariable::produceUndefined();
}

Variable * IntegerVariable::_and(){
    return _value == 0 ? FactoryVariable::produceFalse() : FactoryVariable::produceTrue();
}

Variable * IntegerVariable::_or(){
    return _value == 0 ? FactoryVariable::produceFalse() : FactoryVariable::produceTrue();
}

Variable * IntegerVariable::inc(){
    if(change > 0){
        _value++;
    }
    change = 0;
    return this;
}

std::string IntegerVariable::toString(){
    std::ostringstream ss;
    ss << _value;
    return ss.str();
}

Variable * IntegerVariable::copy(){
    return FactoryVariable::produceInteger(_value);
}
