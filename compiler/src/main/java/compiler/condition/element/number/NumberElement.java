package compiler.condition.element.number;

import compiler.condition.element.Element;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public interface NumberElement <E> extends Element, Instruction {
    
    public E get();
    
    public NumberElement changeSign();
            
}
