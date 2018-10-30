package compiler.condition.element.function;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class FunctionElement implements Element, Instruction {
    
    protected final String name;
    protected int args;
    
    public FunctionElement(String name){
        this.name = name;
    }
    
    public String getName(){
        return name;
    }

    public int getArgs() {
        return args;
    }

    public void setArgs(int args) {
        this.args = args;
    }
            
    @Override
    public String toString(){
        return name + ":" + args;
    }

    @Override
    public Priority priority() {
        return Priority.FUNCTION;
    }    

    @Override
    public String toAssembly() {
        return "CALL " + args + " " + name;
    }
    
}
