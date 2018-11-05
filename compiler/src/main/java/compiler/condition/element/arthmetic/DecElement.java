package compiler.condition.element.arthmetic;

/**
 *
 * @author sasza
 */
public class DecElement extends IncDecElement {
    
    @Override
    public String toString(){
        return "--";
    }

    @Override
    public String toAssembly() {
        return "DEC " + (prefix ? 1 : 0);
    }
    
}
