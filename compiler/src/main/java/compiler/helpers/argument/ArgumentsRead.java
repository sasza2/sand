package compiler.helpers.argument;

import compiler.ParserConsumer;
import compiler.Script;
import compiler.exception.CompilerException;

/**
 *
 * @author sasza
 */
public class ArgumentsRead {
    
    public static Arguments read(Script script){        
        Arguments arguments = new Arguments();
        
        ParserConsumer pc = script.next(parser -> {
            char c = parser.current();
            if(c == ' ' || c == '\n'){
                parser.inc();
            } else if(c == ')'){
                if(!parser.helper().isEmpty()){
                    arguments.add(new Argument(parser.helper()));
                }
                parser.stopAndInc();
            } else if(Character.isLetterOrDigit(c)){
                parser.helperAdd(c);
                parser.inc();
            } else if(c == ','){
                if(parser.helper().isEmpty()){
                    throw new CompilerException(script);
                }
                arguments.add(new Argument(parser.helper()));
                parser.helperClear();
                parser.inc();                
            } else {
                throw new CompilerException(script);
            }
        });
        /*
        if(pc.all().startsWith(",") || pc.all().endsWith(",")){
            throw new CompilerException(script);
        }
        
        int commas = pc.all().split(",").length;
        if(commas > 0 && arguments.size() > 0 && commas != arguments.size()){
            throw new CompilerException(script);
        }*/
        
        return arguments;
    }
    
}
