package compiler.helpers;

import compiler.Script;
import compiler.exception.CompilerException;

/**
 *
 * @author sasza
 */
public class VerifyNext {
    
    public static void verify(Script script, char next){
        SkipWhiteChar.skip(script);
        
        if(script.next() != next){
            throw new CompilerException(script);
        }
        
        script.incPos();
        SkipWhiteChar.skip(script);
    }
    
    public static void verify(Script script, String next){
        for(int i = 0; i < next.length(); i++){
            verify(script, next.charAt(i));
        }
    }
    
}
