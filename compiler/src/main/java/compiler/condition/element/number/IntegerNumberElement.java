package compiler.condition.element.number;

import compiler.condition.element.Priority;

/**
 *
 * @author sasza
 */
public class IntegerNumberElement implements NumberElement <Integer> {

    private int number;
    
    public IntegerNumberElement(int number){
        this.number = number;
    }
    
    @Override
    public Integer get() {
        return number;
    }
    
    @Override
    public String toString(){
        return Integer.toString(number);
    }
    
    @Override
    public Priority priority() {
        return Priority.OTHER;
    }

    @Override
    public IntegerNumberElement changeSign() {
        number = -number;
        return this;
    }

    @Override
    public String toAssembly() {
        return "PUSH I " + number;
    }
    
}
