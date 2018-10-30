#ifndef FACTORY_VARIABLE_H
#define FACTORY_VARIABLE_H

#include <string>
#include <vector>

class UndefinedVariable;
class IntegerVariable;
class DoubleVariable;
class ObjectVariable;
class BooleanVariable;
class StringVariable;
class ClassVariable;
class NextVariable;
class Class;
class NameVariable;
class Variable;

class FactoryVariable {

    private:
        static UndefinedVariable * undefined;
        static BooleanVariable * _true;
        static BooleanVariable * _false;

    public:
        static void init();

        static ObjectVariable * produceException(std::string name, std::string message);
        static ObjectVariable * produceObject(Class * cls);

        static UndefinedVariable * produceUndefined();

        static IntegerVariable * produceInteger(long value);

        static BooleanVariable * produceFalse();
        static BooleanVariable * produceTrue();
        static BooleanVariable * produceBoolean(bool value);

        static DoubleVariable * produceDouble(double value);

        static StringVariable * produceString(std::string value);

        static NextVariable * produceNext(std::string name, ObjectVariable * obj);

        static ClassVariable * produceClass(Class * cls);

        static NameVariable * produceName(std::string name);

        static ObjectVariable * produceFromPrimitive(Variable * variable);

        static void clear();

};

#include "./../../VM.h"
#include "./../UndefinedVariable.h"
#include "./../IntegerVariable.h"
#include "./../DoubleVariable.h"
#include "./../ObjectVariable.h"
#include "./../StringVariable.h"
#include "./../BooleanVariable.h"
#include "./../ClassVariable.h"
#include "./../NextVariable.h"
#include "./../NameVariable.h"

#endif
