package compiler.instruction.exceptions;

import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class CatchInstruction implements Instruction {
    
    private int lvl;
    private String name;
    
    public CatchInstruction(int lvl, String name){
        this.lvl  = lvl;
        this.name = name;
    }

    @Override
    public String toAssembly() {
        return "CATCH " + lvl + " " + name;
    }
    
}
