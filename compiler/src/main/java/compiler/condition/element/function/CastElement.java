package compiler.condition.element.function;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class CastElement implements Element, Instruction {

    private final String to;
    
    public CastElement(String to){
        this.to = to;
    }
    
    public String to(){
        return to;
    }
    
    @Override
    public Priority priority() {
        return Priority.FUNCTION;
    }
    
    @Override
    public String toString(){
        return "(" + to + ")";
    }

    @Override
    public String toAssembly() {
        return "CAST " + to;
    }
    
}
