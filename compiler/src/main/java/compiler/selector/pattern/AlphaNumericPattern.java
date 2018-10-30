package compiler.selector.pattern;

import compiler.ParserConsumer;
import compiler.Script;

/**
 *
 * @author sasza
 */
public class AlphaNumericPattern implements Pattern {
    
    private String value = "";

    @Override
    public boolean match(Script script) {        
        if(!Character.isLetterOrDigit(script.next())){
            return false;
        }
        ParserConsumer pc = script.next(parser -> {
            if(!Character.isLetterOrDigit(parser.current())){
                parser.stopAndInc();
            } else {
                parser.inc();
            }
        });
        value = pc.all();
        return true;
    }

    @Override
    public String value() {
        return value;
    }
    
}
