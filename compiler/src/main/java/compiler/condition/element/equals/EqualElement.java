package compiler.condition.element.equals;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class EqualElement implements Element, Instruction {

    @Override
    public Priority priority() {
        return Priority.EQUAL;
    }        
    
    @Override
    public String toString(){
        return "==";
    }

    @Override
    public String toAssembly() {
        return "EQ";
    }
    
}
