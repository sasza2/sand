package compiler.instruction;

import compiler.instruction.level.LevelInstruction;

/**
 *
 * @author sasza
 * 
 * jump if condition is false to first ( else / else if) or end of if
 */
public class IfJumpInstruction extends LevelInstruction {

    public IfJumpInstruction(int lvl) {
        super(lvl);
    }       

    @Override
    public String toAssembly() {
        return "JMP " + lvl;
    }
    
}
