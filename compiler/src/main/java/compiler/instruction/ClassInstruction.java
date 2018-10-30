package compiler.instruction;

/**
 *
 * @author sasza
 */
public class ClassInstruction implements Instruction {
    
    private final String name;
    
    public ClassInstruction(String name){
        this.name = name;
    }

    @Override
    public String toAssembly() {
        return "CLASS " + name;
    }
    
}
