package compiler.condition.element.string;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class StringElement implements Element, Instruction { 
    
    private final String value;
    
    public StringElement(String value){
        this.value = value;
    }
    
    public String value(){
        return value;
    }

    @Override
    public Priority priority() {
        return Priority.OTHER;
    }

    @Override
    public String toAssembly() {
        return "PUSH C " + value;
    }
    
    @Override
    public String toString(){
        return "\"" + value + "\"";
    }
    
}
