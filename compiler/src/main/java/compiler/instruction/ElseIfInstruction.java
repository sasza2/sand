package compiler.instruction;

import compiler.instruction.level.LevelInstruction;

/**
 *
 * @author sasza
 */
public class ElseIfInstruction extends LevelInstruction {

    public ElseIfInstruction(int lvl) {
        super(lvl);
    }
    
    @Override
    public String toAssembly() {
        return "ELIF " + lvl;
    }
    
}
