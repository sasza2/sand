package compiler.instruction.loop.xwhile;

import compiler.instruction.level.LevelInstruction;

/**
 *
 * @author sasza
 */
public class WhileEndInstruction extends LevelInstruction {

    public WhileEndInstruction(int lvl) {
        super(lvl);
    }

    @Override
    public String toAssembly() {
        return "WHILEEND " + lvl;
    }
    
}
