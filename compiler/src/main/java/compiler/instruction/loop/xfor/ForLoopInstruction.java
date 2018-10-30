package compiler.instruction.loop.xfor;

import compiler.instruction.level.LevelInstruction;

/**
 *
 * @author sasza
 */
public class ForLoopInstruction extends LevelInstruction {

    public ForLoopInstruction(int lvl) {
        super(lvl);
    }

    @Override
    public String toAssembly() {
        return "FORLOOP " + lvl;
    }
    
}
