package compiler.condition.element.arthmetic;

/**
 *
 * @author sasza
 */
public class IncElement extends IncDecElement {
    
    @Override
    public String toString(){
        return "++";
    }

    @Override
    public String toAssembly() {
        return "INC " + (prefix ? 1 : 0);
    }
    
}
