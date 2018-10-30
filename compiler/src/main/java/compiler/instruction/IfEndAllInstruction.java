package compiler.instruction;

import compiler.instruction.level.LevelInstruction;

/**
 *
 * @author sasza
 */
public class IfEndAllInstruction extends LevelInstruction {

    public IfEndAllInstruction(int lvl) {
        super(lvl);
    }

    @Override
    public String toAssembly() {
        return "IFENDALL " + lvl;
    }
    
}
