package compiler.instruction;

import compiler.helpers.argument.Arguments;

/**
 *
 * @author sasza
 */
public class ArgumentsInstruction implements Instruction {
    
    private final Arguments arguments;

    public ArgumentsInstruction(Arguments arguments){
        this.arguments = arguments;
    }

    @Override
    public String toAssembly() {
        return "ARGS " + arguments.size() + " " + arguments.toAssembly();
    }
    
}
