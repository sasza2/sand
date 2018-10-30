package compiler.condition.element.string;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class TemporaryStringElement implements Element, Instruction {
    
    private String value;
    
    public TemporaryStringElement(String value){
        this.value = value;
    }
    
    public String value(){
        return value;
    }
    
    @Override
    public String toString(){
        return value;
    }
    
    @Override
    public Priority priority() {
        return Priority.OTHER;
    }   

    @Override
    public String toAssembly() {
        return "PUSH S " + value;
    }
    
}
