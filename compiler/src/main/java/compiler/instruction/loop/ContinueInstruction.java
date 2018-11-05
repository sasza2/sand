package compiler.instruction.loop;

import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class ContinueInstruction implements Instruction {

    @Override
    public String toAssembly() {
        return "CONTINUE";
    }

}
