package compiler.instruction;

/**
 *
 * @author sasza
 */
public class ImportInstruction implements Instruction {

    private final String name;
    private final String path;
    
    public ImportInstruction(String name, String path){
        this.name = name;
        this.path = path;
    }
    
    @Override
    public String toAssembly() {
        return "IMPORT " + name + " " + path;
    }
    
}
