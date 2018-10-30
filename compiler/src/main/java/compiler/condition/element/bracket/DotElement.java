package compiler.condition.element.bracket;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class DotElement implements Element, Instruction {

    @Override
    public Priority priority() {
        return Priority.BRACKET;
    }    
    
    @Override
    public String toString(){
        return ".";
    }

    @Override
    public String toAssembly() {
        throw new UnsupportedOperationException(); 
    }
            
}
