package compiler.condition.element.logical;

import compiler.condition.element.Priority;

/**
 *
 * @author sasza
 */
public class AndElement implements LogicalElement {

    @Override
    public Priority priority() {
        return Priority.AND;
    }
    
    @Override
    public boolean isSeparator(){
        return true;
    }    
    
    @Override
    public String toString(){
        return "&&";
    }

    @Override
    public String toAssembly() {
        return "AND";
    }
    
}
