package compiler.readers.body;

import compiler.Script;
import compiler.helpers.VerifyNext;
import compiler.instruction.Instruction;
import compiler.instruction.level.LevelGenerator;
import compiler.instruction.loop.xwhile.WhileEndInstruction;
import compiler.instruction.loop.xwhile.WhileIfInstruction;
import compiler.instruction.loop.xwhile.WhileInstruction;
import compiler.readers.SelectorReader;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.Pattern;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author sasza
 */
public class WhileReader implements SelectorReader {
    
    private int lvl;

    @Override
    public List <Instruction> read(Script script, Pattern pattern, ScriptSelector selector) {
        VerifyNext.verify(script, '(');
        
        lvl = LevelGenerator.next();
        
        List <Instruction> instructions = new ArrayList();        
        
        instructions.add(new WhileInstruction(lvl));
        ConditionStatementReader conditionStatementReader = new ConditionStatementReader();        
        instructions.addAll(conditionStatementReader.read(script));        
        instructions.add(new WhileIfInstruction(lvl));
        
        VerifyNext.verify(script, '{');
        instructions.addAll(BodyReader.nonEnding().read(script));
        instructions.add(new WhileEndInstruction(lvl));        
                
        VerifyNext.verify(script, '}');
        return instructions;
    }

}
