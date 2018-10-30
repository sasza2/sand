package compiler.instruction;

import compiler.instruction.level.LevelInstruction;

/**
 *
 * @author sasza
 */
public class IfInstruction extends LevelInstruction {

    public IfInstruction(int lvl) {
        super(lvl);
    }
        
    @Override
    public String toAssembly() {
        return "IF " + lvl;
    }
    
}
