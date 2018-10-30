package compiler.condition.element.logical;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class NotElement implements Element, Instruction {

    @Override
    public Priority priority() {
        return Priority.NOT;
    }
    
    @Override
    public String toString(){
        return "!";
    }

    @Override
    public String toAssembly() {
        return "NOT";
    }
    
}
