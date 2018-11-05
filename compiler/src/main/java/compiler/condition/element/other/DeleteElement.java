
package compiler.condition.element.other;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class DeleteElement implements Element, Instruction {
    
    @Override
    public Priority priority() {
        return Priority.DELETE;
    }

    @Override
    public String toAssembly() {
        return "DELETE";
    }
    
    @Override
    public String toString(){
        return "~";
    }
    
}
