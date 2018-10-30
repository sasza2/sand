package compiler.instruction.loop.xfor;

import compiler.instruction.level.LevelInstruction;

/**
 *
 * @author sasza
 */
public class ForEndInstruction extends LevelInstruction {

    public ForEndInstruction(int lvl) {
        super(lvl);
    }

    @Override
    public String toAssembly() {
        return "FOREND " + lvl;
    }
    
}
