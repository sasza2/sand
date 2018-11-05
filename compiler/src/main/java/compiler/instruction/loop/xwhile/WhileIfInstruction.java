package compiler.instruction.loop.xwhile;

import compiler.instruction.level.LevelInstruction;

/**
 *
 * @author sasza
 */
public class WhileIfInstruction extends LevelInstruction {

    public WhileIfInstruction(int lvl) {
        super(lvl);
    }

    @Override
    public String toAssembly() {
        return "WHILEIF " + lvl;
    }
    
}
