package compiler.condition.element.arthmetic;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class DecElement extends IncDecElement {
    
    @Override
    public String toString(){
        return "--";
    }

    @Override
    public String toAssembly() {
        return "DEC " + (prefix ? 1 : 0);
    }
    
}
