package compiler.instruction;

/**
 *
 * @author sasza
 */
public class ConditionEndInstruction implements Instruction {

    @Override
    public String toAssembly() {
        return "CEND";
    }
    
}
