package compiler.instruction.exceptions;

import compiler.instruction.level.LevelInstruction;

/**
 *
 * @author sasza
 */
public class TryInstruction extends LevelInstruction {

    public TryInstruction(int lvl) {
        super(lvl);
    }

    @Override
    public String toAssembly() {
        return "TRY " + lvl;
    }
    
}
