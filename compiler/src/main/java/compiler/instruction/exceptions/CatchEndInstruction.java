package compiler.instruction.exceptions;

import compiler.instruction.level.LevelInstruction;

/**
 *
 * @author sasza
 */
public class CatchEndInstruction extends LevelInstruction {

    public CatchEndInstruction(int lvl) {
        super(lvl);
    }

    @Override
    public String toAssembly() {
        return "CATCHEND " + lvl;
    }
    
}
