package compiler.instruction.loop.xfor;

import compiler.instruction.level.LevelInstruction;

/**
 *
 * @author sasza
 */
public class ForInstruction extends LevelInstruction {

    public ForInstruction(int lvl) {
        super(lvl);
    }

    @Override
    public String toAssembly() {
        return "FOR " + lvl;
    }
    
}
