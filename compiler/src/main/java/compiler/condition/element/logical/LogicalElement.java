package compiler.condition.element.logical;

import compiler.condition.element.Element;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public interface LogicalElement extends Element, Instruction {
    
    default public boolean isSeparator(){
        return false;
    }
    
}
