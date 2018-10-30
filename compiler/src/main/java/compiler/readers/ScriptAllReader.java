package compiler.readers;

import compiler.Script;
import compiler.selector.ScriptSelector;
import compiler.helpers.SkipWhiteChar;
import compiler.instruction.Instruction;
import compiler.logger.CompilerLogger;
import compiler.selector.pattern.StringPattern;
import java.util.List;
import java.util.logging.Level;

/**
 *
 * @author sasza
 */
public class ScriptAllReader implements StandardReader {

    @Override
    public List <Instruction> read(Script script) {
        CompilerLogger.get()
                      .log(Level.INFO, "ScriptAllReader");
        
        SkipWhiteChar.skip(script);
        
        return ScriptSelector.create()
                             .add(new StringPattern("/*"), new CommentReader())
                             .add(new StringPattern("class "), new ClassReader())
                             .add(new StringPattern("import "), new ImportReader())
                             .add(new StringPattern(";"), new EmptyReader())
                             .orElse(new EndReader())
                             .run(script);
                      
    }
    
}
