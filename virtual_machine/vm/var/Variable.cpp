#include "Variable.h"

Variable * Variable::div(Variable * variable){
    return toNumber()->div(variable->toNumber());
}

Variable * Variable::mod(Variable * variable){
    return toNumber()->mod(variable->toNumber());
}

Variable * Variable::mul(Variable * variable){
    return toNumber()->mul(variable->toNumber());
}

Variable * Variable::pow(Variable * variable){
    return toNumber()->_pow(variable->toNumber());
}

Variable * Variable::sub(Variable * variable){
    return toNumber()->sub(variable->toNumber());
}

Variable * Variable::eq(Variable * variable){
    return FactoryVariable::produceBoolean(toNumber()->eq(variable->toNumber()));
}

Variable * Variable::neq(Variable * variable){
    return FactoryVariable::produceBoolean(toNumber()->neq(variable->toNumber()));
}

Variable * Variable::gt(Variable * variable){
    return FactoryVariable::produceBoolean(toNumber()->gt(variable->toNumber()));
}

Variable * Variable::lt(Variable * variable){
    return FactoryVariable::produceBoolean(toNumber()->lt(variable->toNumber()));
}

Variable * Variable::gte(Variable * variable){
    return FactoryVariable::produceBoolean(toNumber()->gte(variable->toNumber()));
}

Variable * Variable::lte(Variable * variable){
    return FactoryVariable::produceBoolean(toNumber()->lte(variable->toNumber()));
}

Variable * Variable::inc(){
    return FactoryVariable::produceUndefined();
}

Variable * Variable::copy(){
    usage++;
    return this;
}

Number * Variable::toNumber(){
    int _type = type();
    if(_type == INT){
        number._value = (double)((IntegerVariable*)this)->_value;
        number._null  = false;
        return &number;
    } else if(_type == DOUBLE){
        number._value = ((DoubleVariable*)this)->_value;
        number._null  = false;
        return &number;
    } else if(_type == NAME){
        NameVariable * nameVariable = (NameVariable*)this;
        Variable * var = nameVariable->produceFromLocal();
        if(var != NULL){
            return var->toNumber();
        }
    } else if(_type == BOOLEAN){
        BooleanVariable * booleanVariable = (BooleanVariable*)this;
        number._value = (long)(booleanVariable->getValue() ? 1 : 0);
        number._null  = false;
        return &number;
    }

    std::string str = toString();
    double v = atof(str.c_str());
    if(v != 0 || (v == 0 && str == "0")){
        number._value = v;
        number._null  = false;
        return &number;
    } else {
        number._value = v;
        number._null  = true;
        return &number;
    }
}

long str_to_int_hash(const std::string & str){
    long hash = 5381;
    for (size_t i = 0; i < str.size(); ++i){
        hash = 33 * hash + (unsigned char)str[i];
    }
    return hash;
}

Variable::~Variable(){
    #if DEBUG == 1
        std::cout<<"variable remove "<<this<<std::endl;
    #endif
}
