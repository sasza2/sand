package compiler.condition.element.arthmetic;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class IncElement implements Element, Instruction {
    
    private boolean prefix;

    @Override
    public Priority priority() {
        return Priority.INC_DEC;
    }
    
    public void setPrefix(boolean prefix){
        this.prefix = prefix;
    }
    
    @Override
    public String toString(){
        return "++";
    }

    @Override
    public String toAssembly() {
        return "INC " + (prefix ? 1 : 0);
    }
    
}
