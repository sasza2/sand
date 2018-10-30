package compiler.helpers;

import compiler.ParserConsumer;
import compiler.Script;
import compiler.condition.element.number.DoubleNumberElement;
import compiler.condition.element.number.IntegerNumberElement;
import compiler.condition.element.number.NumberElement;
import compiler.exception.CompilerException;

/**
 *
 * @author sasza
 */
public class ReadNumber {
    
    public static NumberElement read(Script script){
        ParserConsumer pc = script.next(parser -> {
            char c = parser.current();
            if(Character.isDigit(c) || c == '.'){
                parser.helperAdd(c);
                if(parser.helper().split("\\.").length > 2){
                    throw new CompilerException(script);
                }
                parser.inc();
            } else {
                parser.stop();                
            }
        });
        
        String number = pc.helper();
        if(number.contains(".")){
            try {
                return new DoubleNumberElement(Double.parseDouble(number));
            } catch(NumberFormatException e){
                throw new CompilerException(script);
            }
        } else {
            try {
                return new IntegerNumberElement(Integer.parseInt(number));
            } catch(NumberFormatException e){
                throw new CompilerException(script);
            }
        }
    }
    
}
