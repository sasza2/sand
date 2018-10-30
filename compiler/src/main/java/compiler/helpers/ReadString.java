package compiler.helpers;

import compiler.ParserConsumer;
import compiler.Script;
import compiler.condition.element.string.StringElement;
import compiler.exception.CompilerException;

/**
 *
 * @author sasza
 */
public class ReadString {
    
    public static StringElement read(Script script){        
        script.incPos();
        ParserConsumer pc = script.next(parser -> {
            char c = parser.current();
            if(c == '\n' || c == '\r'){
                throw new CompilerException(script);
            } else if(c == '"'){
                parser.stop();
            } else {
                parser.helperAdd(c);
                parser.inc();
            }            
        });
        script.incPos();
        return new StringElement(pc.all());
    }
    
}
