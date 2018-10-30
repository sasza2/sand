package compiler.condition.element.equals;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class LowerElement implements Element, Instruction {

    @Override
    public Priority priority() {
        return Priority.LESS_GREATER_EQ;
    }
    
    @Override
    public String toString(){
        return "<";
    }

    @Override
    public String toAssembly() {
        return "LT";
    }
    
}
