package compiler.readers.body;

import compiler.Script;
import compiler.helpers.SkipWhiteChar;
import compiler.instruction.Instruction;
import compiler.instruction.ReturnInstruction;
import compiler.readers.SelectorReader;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.Pattern;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author sasza
 */
public class ReturnReader implements SelectorReader {

    @Override
    public List <Instruction> read(Script script, Pattern pattern, ScriptSelector selector) {
        List <Instruction> instructions = new ArrayList();
        
        ConditionStatementReader conditionStatementReader = new ConditionStatementReader();
        instructions.addAll(conditionStatementReader.read(script));
        instructions.add(new ReturnInstruction());
        
        SkipWhiteChar.skip(script);
                
        return instructions;
    }
    
}
