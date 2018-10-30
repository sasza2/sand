package compiler.condition.element.bracket;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class SquareBracketCloseElement implements Element, Instruction {
    
    private boolean next;
    
    public SquareBracketCloseElement(){
        
    }
    
    public SquareBracketCloseElement(boolean next){
        this.next = next;
    }
    
    @Override
    public String toString(){
        return "]";
    }    

    public boolean isNext(){
        return next;
    }
    
    @Override
    public Priority priority() {
        return Priority.BRACKET;
    }    

    @Override
    public String toAssembly() {
        return "NEXT";
    }
    
}
