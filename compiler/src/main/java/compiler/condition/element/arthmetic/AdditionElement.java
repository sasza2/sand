package compiler.condition.element.arthmetic;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class AdditionElement implements Element, Instruction {
    
    @Override
    public String toString(){
        return "+";
    }

    @Override
    public Priority priority() {
        return Priority.ADD_SUB;
    }

    @Override
    public String toAssembly() {
        return "ADD";
    }
    
}
