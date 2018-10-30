package compiler.condition.element.function;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class CommaElement implements Element, Instruction {
 
    @Override
    public String toString(){
        return ",";
    }

    @Override
    public Priority priority() {
        return Priority.OTHER;
    }
    
    @Override
    public boolean isRemoveable(){
        return true;
    }

    @Override
    public String toAssembly() {
        throw new UnsupportedOperationException();
    }
    
}
