package compiler.instruction.loop.xwhile;

import compiler.instruction.level.LevelInstruction;

/**
 *
 * @author sasza
 */
public class WhileInstruction extends LevelInstruction {

    public WhileInstruction(int lvl) {
        super(lvl);
    }

    @Override
    public String toAssembly() {
        return "WHILE " + lvl;
    }
    
}
