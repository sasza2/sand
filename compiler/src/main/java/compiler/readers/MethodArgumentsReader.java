package compiler.readers;

import compiler.Script;
import compiler.helpers.argument.ArgumentsRead;
import compiler.instruction.ArgumentsInstruction;
import compiler.instruction.Instruction;
import compiler.logger.CompilerLogger;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;

/**
 *
 * @author sasza
 */
public class MethodArgumentsReader implements StandardReader {

    @Override
    public List<Instruction> read(Script script) {
        CompilerLogger.get()
                      .log(Level.INFO, "MethodArgumentsReader");
        
        List <Instruction> instructions = new ArrayList();
        instructions.add(new ArgumentsInstruction(ArgumentsRead.read(script)));        
        
        return instructions;
    }
    
}
