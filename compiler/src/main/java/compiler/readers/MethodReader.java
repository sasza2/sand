package compiler.readers;

import compiler.readers.body.BodyReader;
import compiler.Script;
import compiler.helpers.VerifyNext;
import compiler.instruction.Instruction;
import compiler.instruction.MethodInstruction;
import compiler.instruction.ReturnInstruction;
import compiler.logger.CompilerLogger;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.Pattern;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;

/**
 *
 * @author sasza
 */
public class MethodReader implements SelectorReader {

    @Override
    public List <Instruction> read(Script script, Pattern pattern, ScriptSelector selector) {
        List <Instruction> instructions = new ArrayList();
        instructions.add(new MethodInstruction(pattern.value()));
        
        CompilerLogger.get()
                      .log(Level.INFO, "MethodReader: " + pattern.value());
        
        MethodArgumentsReader arguments = new MethodArgumentsReader();
        instructions.addAll(arguments.read(script));
        
        VerifyNext.verify(script, '{');                                        
        instructions.addAll(BodyReader.withEnding().read(script));        
        VerifyNext.verify(script, '}');
        
        CompilerLogger.get()
                      .log(Level.INFO, "MethodReader: " + instructions.size());
        
        if(instructions.isEmpty() || !instructions.get(instructions.size() - 1).getClass().equals(ReturnInstruction.class)){
            instructions.add(new ReturnInstruction());
        }
        
        return instructions;
    }
    
}
