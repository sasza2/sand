
package compiler.instruction.loop;

import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class BreakInstruction implements Instruction {

    @Override
    public String toAssembly() {
        return "BREAK";
    }

}
