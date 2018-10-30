package compiler.readers.body;

import compiler.Script;
import compiler.helpers.SkipWhiteChar;
import compiler.instruction.Instruction;
import compiler.logger.CompilerLogger;
import compiler.readers.CommentReader;
import compiler.readers.EndReader;
import compiler.readers.StandardReader;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.ConditionPattern;
import compiler.selector.pattern.StringPattern;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;

/**
 *
 * @author sasza
 */
public class BodyReader implements StandardReader {

    private boolean withEnding;

    private BodyReader() {

    }

    @Override
    public List <Instruction> read(Script script) {
        SkipWhiteChar.skip(script);
        ScriptSelector scriptSelector = ScriptSelector.create();
        
        CompilerLogger.get()
                      .log(Level.INFO, "BodyReader");

        if (withEnding) {
            scriptSelector.add(new StringPattern("}"), new BodyCloseReader());
        }
        
        scriptSelector.add(new StringPattern("/*"), new CommentReader())
                .add(new StringPattern("return "), new ReturnReader())
                .add(new StringPattern("if"), new IfReader())
                .add(new StringPattern("for"), new ForReader())
                .add(new StringPattern("try"), new TryReader())
                .add(new StringPattern("throw"), new ThrowReader())
                .add(new ConditionPattern(), new ConditionStatementReader());
        
        if(withEnding){
            scriptSelector.orElse(new EndReader());                        
        } 
        
        List <Instruction> instructions = new ArrayList();
        instructions.addAll(scriptSelector.run(script));
        SkipWhiteChar.skip(script);
        
        CompilerLogger.get()
                      .log(Level.INFO, "BodyReader: " + instructions.size());
        
        return instructions;
    }

    public static BodyReader nonEnding() {
        BodyReader body = new BodyReader();
        return body;
    }

    public static BodyReader withEnding() {
        BodyReader body = new BodyReader();
        return body;
    }

}
