package compiler.selector.pattern;

import compiler.Script;

/**
 *
 * @author sasza
 */
public interface Pattern {
    
    public boolean match(Script script);
    
    public String value();
    
}
