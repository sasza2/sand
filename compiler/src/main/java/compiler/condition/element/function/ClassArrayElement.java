package compiler.condition.element.function;

/**
 *
 * @author sasza
 */
public class ClassArrayElement extends NewClassElement {

    public ClassArrayElement(FunctionElement function) {
        super(function);
    }
    
    @Override
    public String toString(){
        return "new[]:" + args;
    }
    
}
