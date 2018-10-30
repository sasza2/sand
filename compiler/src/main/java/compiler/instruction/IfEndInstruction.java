package compiler.instruction;

import compiler.instruction.level.LevelInstruction;

/**
 *
 * @author sasza
 */
public class IfEndInstruction extends LevelInstruction {

    public IfEndInstruction(int lvl) {
        super(lvl);
    }

    @Override
    public String toAssembly() {
        return "IFEND " + lvl;
    }
    
}
