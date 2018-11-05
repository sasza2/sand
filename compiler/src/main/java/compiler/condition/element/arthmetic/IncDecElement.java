package compiler.condition.element.arthmetic;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
abstract public class IncDecElement implements Element, Instruction {
    
    protected boolean prefix;

    @Override
    public Priority priority() {
        return Priority.INC_DEC;
    }
    
    public void setPrefix(boolean prefix){
        this.prefix = prefix;
    }
    
}
