package compiler.condition.transform;

import compiler.condition.transform.before.TransformException;
import compiler.condition.element.Element;
import java.util.List;

/**
 *
 * @author sasza
 */
public interface Transform {
    
    public List <Element> transform(List <Element> elements) throws TransformException;
    
}
