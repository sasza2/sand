package compiler.condition.element.number;

import compiler.condition.element.Priority;

/**
 *
 * @author sasza
 */
public class BooleanElement implements NumberElement <Boolean> {
    
    private boolean value;
    
    public BooleanElement(boolean value){
        this.value = value;
    }

    @Override
    public Boolean get() {
        return value;
    }

    @Override
    public BooleanElement changeSign() {
        value = !value;
        return this;
    }

    @Override
    public Priority priority() {
        return Priority.OTHER;
    }

    @Override
    public String toAssembly() {
        return "PUSH B " + value;
    }
    
    @Override
    public String toString(){
        return value ? "true" : "false";
    }
    
}
