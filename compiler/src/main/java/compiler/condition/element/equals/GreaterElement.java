package compiler.condition.element.equals;

import compiler.condition.element.Priority;
import compiler.condition.element.logical.LogicalElement;

/**
 *
 * @author sasza
 */
public class GreaterElement implements LogicalElement {

    @Override
    public Priority priority() {
        return Priority.LESS_GREATER_EQ;
    }
    
    @Override
    public String toString(){
        return ">";
    }

    @Override
    public String toAssembly() {
        return "GT";
    }
    
}
