package compiler.instruction;

import compiler.instruction.level.LevelInstruction;

/**
 *
 * @author sasza
 */
public class ElseIfEndInstruction extends LevelInstruction {

    public ElseIfEndInstruction(int lvl) {
        super(lvl);
    }       

    @Override
    public String toAssembly() {
        return "ELIFEND " + lvl;
    }    
    
}
