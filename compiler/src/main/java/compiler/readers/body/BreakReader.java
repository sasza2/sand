
package compiler.readers.body;

import compiler.Script;
import compiler.helpers.SkipWhiteChar;
import compiler.helpers.VerifyNext;
import compiler.instruction.Instruction;
import compiler.instruction.loop.BreakInstruction;
import compiler.readers.SelectorReader;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.Pattern;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author sasza
 */
public class BreakReader implements SelectorReader {
    
    @Override
    public List <Instruction> read(Script script, Pattern pattern, ScriptSelector selector) {
        SkipWhiteChar.skip(script);
        VerifyNext.verify(script, ';');
        
        List <Instruction> instructions = new ArrayList();
        instructions.add(new BreakInstruction());
        return instructions;
    }

}
