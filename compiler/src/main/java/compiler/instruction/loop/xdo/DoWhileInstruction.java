package compiler.instruction.loop.xdo;

import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class DoWhileInstruction implements Instruction {

    @Override
    public String toAssembly() {
        return "DOWHILE";
    }

}
