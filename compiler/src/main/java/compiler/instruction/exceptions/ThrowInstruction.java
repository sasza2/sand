package compiler.instruction.exceptions;

import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class ThrowInstruction implements Instruction {

    @Override
    public String toAssembly() {
        return "THROW";
    }
    
}
