package compiler.readers.body;

import compiler.instruction.IfEndInstruction;
import compiler.Script;
import compiler.helpers.SkipWhiteChar;
import compiler.helpers.VerifyNext;
import compiler.instruction.IfEndAllInstruction;
import compiler.instruction.IfInstruction;
import compiler.instruction.IfJumpInstruction;
import compiler.instruction.Instruction;
import compiler.instruction.level.LevelGenerator;
import compiler.readers.CommentReader;
import compiler.readers.SelectorReader;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.Pattern;
import compiler.selector.pattern.StringPattern;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author sasza
 */
public class IfReader implements SelectorReader {
    
    private int lvl;

    @Override
    public List<Instruction> read(Script script, Pattern pattern, ScriptSelector selector) {        
        lvl = LevelGenerator.next();
        
        List <Instruction> instructions = new ArrayList();
        instructions.add(new IfInstruction(lvl));        
        
        ConditionStatementReader conditionStatementReader = new ConditionStatementReader();
        instructions.addAll(conditionStatementReader.read(script));
        
        instructions.add(new IfJumpInstruction(lvl));

        SkipWhiteChar.skip(script);

        instructions.addAll(BodyReader.nonEnding().read(script));
        VerifyNext.verify(script, '}');

        instructions.add(new IfEndInstruction(lvl)); 
        
        instructions.addAll(ScriptSelector.create()
                .add(new StringPattern("/*"), new CommentReader())
                .add(new StringPattern("else"), new ElseReader(lvl))
                .run(script));
        
        SkipWhiteChar.skip(script);
        
        instructions.add(new IfEndAllInstruction(lvl));

        return instructions;
    }

}
