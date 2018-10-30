package compiler.condition.element.function;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class NewElement implements Element, Instruction {

    @Override
    public Priority priority() {
        return Priority.FUNCTION;
    }
    
    @Override
    public String toString(){
        return "new";
    }

    @Override
    public String toAssembly() {
        throw new UnsupportedOperationException();
    }
    
}
