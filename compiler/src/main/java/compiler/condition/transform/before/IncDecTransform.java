package compiler.condition.transform.before;

import compiler.condition.element.Element;
import compiler.condition.element.arthmetic.IncDecElement;
import compiler.condition.element.string.TemporaryStringElement;
import compiler.condition.transform.Transform;
import java.util.List;

/**
 *
 * @author sasza
 */
public class IncDecTransform implements Transform {

    @Override
    public List <Element> transform(List <Element> elements) throws TransformException {
        for(int i = 0; i < elements.size() - 1; i++){
            Element current = elements.get(i);
            Element next    = elements.get(i + 1);
            if(current instanceof IncDecElement && next instanceof TemporaryStringElement){
                ((IncDecElement)current).setPrefix(true);
            }
        }
        return elements;
    }
    
}
