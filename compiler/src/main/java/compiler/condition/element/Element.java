package compiler.condition.element;

/**
 *
 * @author sasza
 */
public interface Element {
    
    public Priority priority();
    
    default public boolean isRemoveable(){
        return false;
    }
        
}
