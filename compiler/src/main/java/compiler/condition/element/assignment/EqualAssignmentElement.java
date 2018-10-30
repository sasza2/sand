package compiler.condition.element.assignment;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class EqualAssignmentElement implements Element, Instruction {

    @Override
    public Priority priority() {
        return Priority.ASSIGNMENT;
    }
    
    @Override
    public String toString(){
        return "=";
    }

    @Override
    public String toAssembly() {
        return "MOV";
    }
    
}
