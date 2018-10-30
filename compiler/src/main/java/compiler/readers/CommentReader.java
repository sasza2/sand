package compiler.readers;

import compiler.Script;
import compiler.helpers.SkipWhiteChar;
import compiler.instruction.Instruction;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.Pattern;
import java.util.Arrays;
import java.util.List;

/**
 *
 * @author sasza
 */
public class CommentReader implements SelectorReader {

    @Override
    public List<Instruction> read(Script script, Pattern pattern, ScriptSelector selector) {
        script.next(parser -> {
            if(parser.last("*/")){
                parser.stopAndInc();
            } else {
                parser.inc();
            }
        });
        SkipWhiteChar.skip(script);
        return Arrays.asList();
    }
    
}
