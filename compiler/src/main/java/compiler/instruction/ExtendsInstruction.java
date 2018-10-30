package compiler.instruction;

/**
 *
 * @author sasza
 */
public class ExtendsInstruction implements Instruction {
    
    private final String clsName;
    
    public ExtendsInstruction(String clsName){
        this.clsName = clsName;
    }

    @Override
    public String toAssembly() {
        return "EXTENDS " + clsName;
    }
    
}
