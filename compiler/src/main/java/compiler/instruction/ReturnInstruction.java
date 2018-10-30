package compiler.instruction;

/**
 *
 * @author sasza
 */
public class ReturnInstruction implements Instruction {

    @Override
    public String toAssembly() {
        return "RET";
    }
    
}
