package compiler.helpers;

import compiler.Script;

/**
 *
 * @author sasza
 */
public class SkipWhiteChar {
    
    public static void skip(Script script){
        while(script.getPos() + 1 < script.getCode().length()){
            int c = script.next();
            switch(c){
                case ' ':
                case '\n':
                case '\r':
                case '\t':
                    script.incPos();
                    break;
                default:
                    return;
            }
        }
    }
    
}
