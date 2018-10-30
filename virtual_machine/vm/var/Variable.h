#ifndef VARIABLE_H
#define VARIABLE_H

#define INT 0
#define UNDEFINED 1
#define STRING 2
#define OBJECT 3
#define NEXT 4
#define NAME 5
#define DOUBLE 6
#define DATA 7
#define CLASS 8
#define BOOLEAN 9

#include <string>
#include <iostream>
#include <math.h>

class Variable;

class Number {

    public:
        bool _null;
        double _value;
            
        bool isNull();
        double value();

        bool eq(Number * number);
        bool neq(Number * number);
        bool gt(Number * number);
        bool lt(Number * number);
        bool gte(Number * number);
        bool lte(Number * number);

        Variable * div(Number * number);
        Variable * mod(Number * number);
        Variable * mul(Number * number);
        Variable * _pow(Number * number);
        Variable * sub(Number * number);

};

class Variable {

    private:
        Number number;

    public:
        int usage = 1;
        bool readOnly = false;

        virtual int type() = 0;
        virtual Variable * copy();

        virtual Variable * sum(Variable * variable) = 0;
        virtual Variable * div(Variable * variable);
        virtual Variable * mod(Variable * variable);
        virtual Variable * mul(Variable * variable);
        virtual Variable * pow(Variable * variable);
        virtual Variable * sub(Variable * variable);

        virtual Variable * _and() = 0;
        virtual Variable * _or() = 0;
        virtual Variable * inc();

        virtual Variable * eq(Variable * variable);
        virtual Variable * neq(Variable * variable);
        virtual Variable * gt(Variable * variable);
        virtual Variable * lt(Variable * variable);
        virtual Variable * gte(Variable * variable);
        virtual Variable * lte(Variable * variable);

        virtual std::string toString() = 0;
        virtual Number * toNumber();
        virtual ~Variable();

};

long str_to_int_hash(const std::string & str);

#include "IntegerVariable.h"
#include "./factory/FactoryVariable.h"

#endif
