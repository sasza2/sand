package compiler.readers;

import compiler.Script;
import compiler.condition.element.string.TemporaryStringElement;
import compiler.selector.ScriptSelector;
import compiler.helpers.ReadDigitsAndLetters;
import compiler.helpers.SkipWhiteChar;
import compiler.instruction.ClassInstruction;
import compiler.instruction.Instruction;
import compiler.logger.CompilerLogger;
import compiler.selector.pattern.Pattern;
import compiler.selector.pattern.StringPattern;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;


/**
 *
 * @author sasza
 */
public class ClassReader implements SelectorReader {

    @Override
    public List <Instruction> read(Script script, Pattern pattern, ScriptSelector selector) {
        TemporaryStringElement clsName = ReadDigitsAndLetters.read(script);        
        List <Instruction> instructions = new ArrayList();
        instructions.add(new ClassInstruction(clsName.value()));
        
        CompilerLogger.get()
                      .log(Level.INFO, "ClassReader: " + clsName.value());
        
        SkipWhiteChar.skip(script);
        
        instructions.addAll(
               ScriptSelector.create()
                             .add(new StringPattern("extends "), new ExtendsClassReader())
                             .add(new StringPattern("{"), new ClassBodyReader())                                
                             .orElse(new EndReader())
                             .run(script));
        
        CompilerLogger.get()
                      .log(Level.INFO, "ClassReader: " + instructions.size());
                        
        return instructions;
    }  
    
}
