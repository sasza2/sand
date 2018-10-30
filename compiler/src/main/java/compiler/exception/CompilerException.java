package compiler.exception;

import compiler.Script;

/**
 *
 * @author sasza
 */
public class CompilerException extends RuntimeException {
    
    private Script script;
    
    public CompilerException(Script script){
        this.script = script;
    }
    
    @Override
    public String toString(){
        return "error on " + script.getLine() + ":" + script.getLinePos() + " -> " + script.next(3);
    }
    
}
