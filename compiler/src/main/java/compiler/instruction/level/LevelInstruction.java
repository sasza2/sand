package compiler.instruction.level;

import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public abstract class LevelInstruction implements Instruction {

    protected final int lvl;

    public LevelInstruction(int lvl){
        this.lvl = lvl;
    }
    
}
