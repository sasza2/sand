package compiler.instruction.loop.xfor;

import compiler.instruction.level.LevelInstruction;

/**
 *
 * @author sasza
 */
public class ForBodyInstruction extends LevelInstruction {

    public ForBodyInstruction(int lvl) {
        super(lvl);
    }

    @Override
    public String toAssembly() {
        return "FORBODY " + lvl;
    }
    
}
