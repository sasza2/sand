package compiler.readers;

import compiler.Script;
import compiler.instruction.Instruction;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.Pattern;
import java.util.List;

/**
 *
 * @author sasza
 */
public class ClassCloseReader implements SelectorReader {
    
    @Override
    public List<Instruction> read(Script script, Pattern pattern, ScriptSelector selector) {
        script.incPos();
        selector.stop();        
        return null;
    }
    
}
