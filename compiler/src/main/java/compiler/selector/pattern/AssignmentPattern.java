package compiler.selector.pattern;

import compiler.Script;

/**
 *
 * @author sasza
 */
public class AssignmentPattern implements Pattern {

    private String value; //variable name
    
    @Override
    public boolean match(Script script) {
        return false;
    }

    @Override
    public String value() {
        return value;
    }
    
}
