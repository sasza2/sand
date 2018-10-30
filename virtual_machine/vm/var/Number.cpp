#include "Variable.h"

bool Number::isNull(){
    return _null;
}

double Number::value(){
    return _value;
}

bool Number::eq(Number * number){
    return !_null && !number->_null && number->_value == _value;
}

bool Number::neq(Number * number){
    return !eq(number);
}

bool Number::gt(Number * number){
    return !_null && !number->_null && number->_value > _value;
}

bool Number::lt(Number * number){
    return !_null && !number->_null && number->_value < _value;
}

bool Number::gte(Number * number){
    return !_null && !number->_null && number->_value >= _value;
}

bool Number::lte(Number * number){
    return !_null && !number->_null && number->_value <= _value;
}

Variable * Number::div(Number * number){
    if(_null || number->_null){
        return FactoryVariable::produceUndefined();
    }
    if(_value == 0){
        return NULL;
    }

    double p = number->_value / _value;
    if(p == (long)p){
        return FactoryVariable::produceInteger((long)p);
    } else {
        return FactoryVariable::produceDouble(p);
    }
}

Variable * Number::mod(Number * number){
    if(_null || number->_null){
        return FactoryVariable::produceUndefined();
    }

    long mod = (long)_value;
    if(mod == 0){
        return NULL;
    }

    return FactoryVariable::produceInteger((long)number->_value % mod);
}

Variable * Number::mul(Number * number){
    if(_null || number->_null){
        return FactoryVariable::produceUndefined();
    }

    double p = number->_value * _value;
    if(p == (long)p){
        return FactoryVariable::produceInteger((long)p);
    } else {
        return FactoryVariable::produceDouble(p);
    }
}

Variable * Number::_pow(Number * number){
    if(_null || number->_null){
        return FactoryVariable::produceUndefined();
    }

    double p = pow(number->_value, _value);
    if(p == (long)p){
        return FactoryVariable::produceInteger((long)p);
    } else {
        return FactoryVariable::produceDouble(p);
    }
}

Variable * Number::sub(Number * number){
    if(_null || number->_null){
        return FactoryVariable::produceUndefined();
    }

    double p = number->_value - _value;
    if(p == (long)p){
        return FactoryVariable::produceInteger((long)p);
    } else {
        return FactoryVariable::produceDouble(p);
    }
}
