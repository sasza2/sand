package compiler.readers;

import compiler.Script;
import compiler.condition.element.string.StringElement;
import compiler.condition.element.string.TemporaryStringElement;
import compiler.helpers.ReadDigitsAndLetters;
import compiler.helpers.ReadString;
import compiler.helpers.SkipWhiteChar;
import compiler.helpers.VerifyNext;
import compiler.instruction.ImportInstruction;
import compiler.instruction.Instruction;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.Pattern;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author sasza
 */
public class ImportReader implements SelectorReader {

    @Override
    public List <Instruction> read(Script script, Pattern pattern, ScriptSelector selector) {
        List <Instruction> instructions = new ArrayList();
        SkipWhiteChar.skip(script);
        TemporaryStringElement name = ReadDigitsAndLetters.read(script);
        
        SkipWhiteChar.skip(script);
        VerifyNext.verify(script, "from");
        SkipWhiteChar.skip(script);
        
        VerifyNext.verify(script, '"');
        script.decPos(1);
        StringElement path = ReadString.read(script);
                
        SkipWhiteChar.skip(script);
        
        instructions.add(new ImportInstruction(name.value(), path.value()));        
        return instructions;
    }
    
}
