package compiler.condition.element.number;

import compiler.condition.element.Priority;

/**
 *
 * @author sasza
 */
public class DoubleNumberElement implements NumberElement <Double> {
    
    private double number;
    
    public DoubleNumberElement(double number){
        this.number = number;
    }

    @Override
    public Double get() {
        return number;
    }
    
    @Override
    public String toString(){
        return Double.toString(number);
    }
    
    @Override
    public Priority priority() {
        return Priority.OTHER;
    }

    @Override
    public DoubleNumberElement changeSign() {
        number = -number;
        return this;
    }

    @Override
    public String toAssembly() {
        return "PUSH D " + number;
    }
    
}
