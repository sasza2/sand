package compiler.readers.body;

import compiler.Script;
import compiler.helpers.SkipWhiteChar;
import compiler.instruction.Instruction;
import compiler.instruction.exceptions.ThrowInstruction;
import compiler.readers.SelectorReader;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.Pattern;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author sasza
 */
public class ThrowReader implements SelectorReader {

    @Override
    public List <Instruction> read(Script script, Pattern pattern, ScriptSelector selector) {
        List <Instruction> instructions = new ArrayList();
        SkipWhiteChar.skip(script);
        ConditionStatementReader conditionStatementReader = new ConditionStatementReader();
        instructions.addAll(conditionStatementReader.read(script));
        instructions.add(new ThrowInstruction());
        return instructions;
    }
    
}
