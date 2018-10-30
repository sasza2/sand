package compiler.readers.body;

import compiler.Script;
import compiler.helpers.VerifyNext;
import compiler.instruction.Instruction;
import compiler.instruction.level.LevelGenerator;
import compiler.instruction.loop.xfor.ForBodyInstruction;
import compiler.instruction.loop.xfor.ForEndInstruction;
import compiler.instruction.loop.xfor.ForIfInstruction;
import compiler.instruction.loop.xfor.ForInstruction;
import compiler.instruction.loop.xfor.ForLoopInstruction;
import compiler.readers.SelectorReader;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.Pattern;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author sasza
 */
public class ForReader implements SelectorReader {
    
    private int lvl;
    
    @Override
    public List <Instruction> read(Script script, Pattern pattern, ScriptSelector selector) {
        VerifyNext.verify(script, '(');
        
        lvl = LevelGenerator.next();
        
        List <Instruction> instructions = new ArrayList();        
        ConditionStatementReader conditionStatementReader = new ConditionStatementReader();
        
        //declaration
        instructions.addAll(conditionStatementReader.read(script));
        instructions.add(new ForInstruction(lvl));
        
        //condition
        instructions.addAll(conditionStatementReader.read(script));
        instructions.add(new ForIfInstruction(lvl));
        
        //increment
        instructions.addAll(conditionStatementReader.read(script));
        instructions.add(new ForBodyInstruction(lvl));
        
        VerifyNext.verify(script, '{');
        instructions.addAll(BodyReader.nonEnding().read(script));
        instructions.add(new ForLoopInstruction(lvl));
        instructions.add(new ForEndInstruction(lvl));
                
        VerifyNext.verify(script, '}');        
        return instructions;
    }
    
}
