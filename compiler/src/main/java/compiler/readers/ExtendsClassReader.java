package compiler.readers;

import compiler.Script;
import compiler.condition.element.string.TemporaryStringElement;
import compiler.exception.CompilerException;
import compiler.helpers.ReadDigitsAndLetters;
import compiler.helpers.SkipWhiteChar;
import compiler.instruction.ExtendsInstruction;
import compiler.instruction.Instruction;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.Pattern;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author sasza
 */
public class ExtendsClassReader implements SelectorReader {

    @Override
    public List <Instruction> read(Script script, Pattern pattern, ScriptSelector selector){
        List <Instruction> instructions = new ArrayList();
                
        SkipWhiteChar.skip(script);
        TemporaryStringElement cls = ReadDigitsAndLetters.read(script);
        instructions.add(new ExtendsInstruction(cls.value()));
        SkipWhiteChar.skip(script);
        
        if(script.next() != '{'){
            throw new CompilerException(script);
        }
        
        return instructions;
    }
    
}
