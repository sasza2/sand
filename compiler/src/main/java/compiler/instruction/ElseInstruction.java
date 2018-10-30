package compiler.instruction;

import compiler.instruction.level.LevelInstruction;

/**
 *
 * @author sasza
 */
public class ElseInstruction extends LevelInstruction {

    public ElseInstruction(int lvl) {
        super(lvl);
    }
    
    @Override
    public String toAssembly() {
        return "ELSE " + lvl;
    }
    
}
