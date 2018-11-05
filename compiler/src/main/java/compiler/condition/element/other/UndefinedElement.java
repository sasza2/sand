
package compiler.condition.element.other;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class UndefinedElement implements Element, Instruction {
    
    @Override
    public Priority priority() {
        return Priority.OTHER;
    }

    @Override
    public String toAssembly() {
        return "PUSH U undefined";
    }
    
    @Override
    public String toString(){
        return "undefined";
    }
    
}