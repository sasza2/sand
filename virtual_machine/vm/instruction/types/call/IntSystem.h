#ifndef INT_SYSTEM_H
#define INT_SYSTEM_H

#include <string>
#include <vector>
#include <map>
#include <unistd.h>
#include <sys/time.h>
#include "./../../../trace/Trace.h"
#include "./../../../var/StringVariable.h"
#include "./../../../var/ObjectVariable.h"
#include "./../../../var/IntegerVariable.h"
#include "./../../../trace/TraceExecute.h"
#include <pthread.h>
#include "./../../../var/factory/FactoryVariable.h"

class IntCommand {

    public:
        virtual void call(std::vector <Variable*> arguments) = 0;
        virtual ~IntCommand();
        
};

class IntSystem {

    private:
        static std::map <std::string, IntCommand*> * commands;

    public:
        static void init();
        static void call(std::vector <Trace*> * traces, std::vector <Variable*> arguments);
        static void clear();

};

class ConsoleWritelnCommand : public IntCommand {

    public:
        void call(std::vector <Variable*> arguments);

};

class ThreadStartCommand : public IntCommand {

    public:
        void call(std::vector <Variable*> arguments);

};

class ThreadSleepCommand : public IntCommand {

    public:
        void call(std::vector <Variable*> arguments);

};

class ThreadIdCommand : public IntCommand {

    public:
        void call(std::vector <Variable*> arguments);

};

class ThreadWaitCommand : public IntCommand {

    public:
        void call(std::vector <Variable*> arguments);

};

class MathRandomCommand : public IntCommand {

    public:
        void call(std::vector <Variable*> arguments);

};

class ConsoleReadlnCommand : public IntCommand {

    public:
        void call(std::vector <Variable*> arguments);

};

class DateUnixMsCommand : public IntCommand {

    public:
        void call(std::vector <Variable*> arguments);

};

class StringLengthCommand : public IntCommand {

    public:
        void call(std::vector <Variable*> arguments);

};

#endif
