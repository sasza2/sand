package compiler.readers;

import compiler.Script;
import compiler.helpers.SkipWhiteChar;
import compiler.helpers.VerifyNext;
import compiler.instruction.Instruction;
import compiler.logger.CompilerLogger;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.AlphaNumericPattern;
import compiler.selector.pattern.Pattern;
import compiler.selector.pattern.StringPattern;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;

/**
 *
 * @author sasza
 */
public class ClassBodyReader implements SelectorReader {
    
    @Override
    public List <Instruction> read(Script script, Pattern pattern, ScriptSelector selector) {
        CompilerLogger.get()
                      .log(Level.INFO, "ClassBodyReader");
        
        List <Instruction> instructions;
        SkipWhiteChar.skip(script);   
        if(script.next() != '}'){
            instructions =
               ScriptSelector.create()
                             .add(new StringPattern("/*"), new CommentReader())
                             .add(new AlphaNumericPattern(), new MethodReader())                             
                             .orElse(new EndReader())
                             .run(script);
                
            VerifyNext.verify(script, '}');
        } else {
            instructions = new ArrayList();
        }
                
        CompilerLogger.get()
                      .log(Level.INFO, "ClassBodyReader: " + instructions.size());
        
        return instructions;
    }
    
}
