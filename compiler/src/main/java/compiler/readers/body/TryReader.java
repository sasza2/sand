package compiler.readers.body;

import compiler.Script;
import compiler.condition.element.string.TemporaryStringElement;
import compiler.helpers.ReadDigitsAndLetters;
import compiler.helpers.SkipWhiteChar;
import compiler.helpers.VerifyNext;
import compiler.instruction.Instruction;
import compiler.instruction.exceptions.CatchEndInstruction;
import compiler.instruction.exceptions.CatchInstruction;
import compiler.instruction.exceptions.TryInstruction;
import compiler.instruction.level.LevelGenerator;
import compiler.readers.SelectorReader;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.Pattern;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author sasza
 */
public class TryReader implements SelectorReader {

    private int lvl;
    
    @Override
    public List <Instruction> read(Script script, Pattern pattern, ScriptSelector selector) {
        lvl = LevelGenerator.next();
        
        List <Instruction> instructions = new ArrayList();
        instructions.add(new TryInstruction(lvl));
        SkipWhiteChar.skip(script);        
        VerifyNext.verify(script, '{');
        
        instructions.addAll(BodyReader.nonEnding().read(script));        
        VerifyNext.verify(script, '}');
        SkipWhiteChar.skip(script);
                        
        VerifyNext.verify(script, "catch");
        SkipWhiteChar.skip(script);
        VerifyNext.verify(script, "(");
        TemporaryStringElement name = ReadDigitsAndLetters.read(script);
        instructions.add(new CatchInstruction(lvl, name.value()));
        VerifyNext.verify(script, "){");
        
        instructions.addAll(BodyReader.nonEnding().read(script));
        VerifyNext.verify(script, '}');
        instructions.add(new CatchEndInstruction(lvl));
                
        return instructions;
    }
    
}
