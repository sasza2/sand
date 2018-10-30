package compiler.helpers;

import compiler.ParserConsumer;
import compiler.Script;
import compiler.condition.element.string.TemporaryStringElement;
import java.util.Arrays;
import java.util.List;

/**
 *
 * @author sasza
 */
public class ReadDigitsAndLetters {
    
    public static TemporaryStringElement read(Script script){
        return read(script, new Character[]{});
    }
    
    public static TemporaryStringElement read(Script script, Character ... extra){        
        List <Character> with = Arrays.asList(extra);
        
        SkipWhiteChar.skip(script);
        
        ParserConsumer pc = script.next(parser -> {
            char c = parser.current();
            if(Character.isLetterOrDigit(c) || with.contains(c)){
                parser.helperAdd(c);
                parser.inc();
            } else {
                parser.stop();                
            }
        });       
                
        return new TemporaryStringElement(pc.helper());
    }
    
}
