package compiler.condition.element.bitwise;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class ShiftRightElement implements Element, Instruction {
    
    @Override
    public Priority priority() {
        return Priority.BITWISE;
    }
    
    @Override
    public String toString(){
        return ">>";
    }

    @Override
    public String toAssembly() {
        return "SHR";
    }
    
}
