package compiler.instruction.loop.xfor;

import compiler.instruction.level.LevelInstruction;

/**
 *
 * @author sasza
 */
public class ForIfInstruction extends LevelInstruction {

    public ForIfInstruction(int lvl) {
        super(lvl);
    }

    @Override
    public String toAssembly() {
        return "FORIF " + lvl;
    }
    
}
