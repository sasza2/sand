package compiler.instruction;

/**
 *
 * @author sasza
 */
public class MethodInstruction implements Instruction {
    
    private final String value;
    
    public MethodInstruction(String value){
        this.value = value.substring(0, value.length() - 1);
    }

    @Override
    public String toAssembly() {
        return "METHOD " + value;
    }
    
}
