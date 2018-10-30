package compiler.selector.pattern;

import compiler.Script;

/**
 *
 * @author sasza
 */
public class StringPattern implements Pattern {
    
    private final String value;
    
    public StringPattern(String value){
        this.value = value;
    }

    @Override
    public boolean match(Script script) {
        if(script.getPos() + value.length() >= script.getCode().length()){
            return false;
        }
        
        if(value.equals(script.next(value.length()))){
            script.incPos(value.length());
            return true;
        }
        return false;
    }

    @Override
    public String value() {
        return value;
    }
    
}
