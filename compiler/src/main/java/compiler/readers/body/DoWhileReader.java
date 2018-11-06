package compiler.readers.body;

import compiler.Script;
import compiler.condition.element.logical.NotElement;
import compiler.condition.element.number.BooleanElement;
import compiler.helpers.SkipWhiteChar;
import compiler.helpers.VerifyNext;
import compiler.instruction.IfEndAllInstruction;
import compiler.instruction.IfEndInstruction;
import compiler.instruction.IfInstruction;
import compiler.instruction.IfJumpInstruction;
import compiler.instruction.Instruction;
import compiler.instruction.level.LevelGenerator;
import compiler.instruction.loop.BreakInstruction;
import compiler.instruction.loop.xdo.DoWhileInstruction;
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
public class DoWhileReader implements SelectorReader {
    
    private int lvl;

    @Override
    public List <Instruction> read(Script script, Pattern pattern, ScriptSelector selector){
        lvl = LevelGenerator.next();
        
        SkipWhiteChar.skip(script);
        VerifyNext.verify(script, '{');
        
        List <Instruction> body = BodyReader.nonEnding().read(script);
        SkipWhiteChar.skip(script);
        VerifyNext.verify(script, '}');
        SkipWhiteChar.skip(script);
        VerifyNext.verify(script, "while");
        SkipWhiteChar.skip(script);
        
        ConditionStatementReader conditionStatementReader = new ConditionStatementReader();
        
        List <Instruction> instructions = new ArrayList();
        instructions.add(new DoWhileInstruction());
        instructions.add(new WhileInstruction(lvl));        
        instructions.addAll(conditionStatementReader.read(script));        
        instructions.add(new WhileIfInstruction(lvl));                
        instructions.addAll(body);
        instructions.add(new WhileEndInstruction(lvl));       
                
        return instructions;
    }

}
