package compiler.readers;

import compiler.Script;
import compiler.helpers.SkipWhiteChar;
import compiler.instruction.Instruction;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.Pattern;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author sasza
 */
public class EmptyReader implements SelectorReader {

    @Override
    public List <Instruction> read(Script script, Pattern pattern, ScriptSelector selector) {
        SkipWhiteChar.skip(script);
        return new ArrayList();
    }
    
}
