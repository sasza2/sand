package compiler.condition.element.arthmetic;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class PowerElement implements Element, Instruction {

    @Override
    public Priority priority() {
        return Priority.POWER;
    }
    
    @Override
    public String toString(){
        return "^";
    }

    @Override
    public String toAssembly() {
        return "POW";
    }
    
}
