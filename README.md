# Sand
Sand is object-oriented programming language.

## Installing
We need to build virtual machine (c++) and compiler (java, maven).

### Compiler
```
cd compiler
mvn clean install
cd target
alias sandc="java -jar ${PWD}/compiler-1.0.jar"
```

or add it to ~/.bashrc

### Virtual machine
sand_lib/ provides classes like String, Array, Console etc.

```
cd virtual_machine
make
alias sand="${PWD}/app ${PWD}/../sand_lib/"
```

## Running example
Hello world program App.sa:
```
/*
    hello world in Sand
*/
class App {

    main(args){
        Console.writeln("Hello world!");
    }

}
```

Commands to run program:
```
sandc -P /ABSOLUTE_PATH/sand_example/
sand /ABSOLUTE_PATH/sand_example/ App
```

output:
```
Hello world!
```

## Testing
To run test programs from sand_test/ you must first compile virtual_machine/ with parameter DEBUG=1.

```
cd virtual_machine
make DEBUG=1
./test $PWD/../sand_lib/ $PWD/../sand_tests/ $PWD/../sand_tests/tests
```

File sand_tests/tests contains pair of class name to test and expected value on return of main() method.
