package compiler.condition.transform.before;

import compiler.condition.element.Element;
import compiler.condition.element.function.FunctionElement;
import compiler.condition.element.function.NewClassElement;
import compiler.condition.element.function.NewElement;
import compiler.condition.transform.Transform;
import java.util.List;

/**
 *
 * @author sasza
 */
public class ClassTransform implements Transform {

    @Override
    public List <Element> transform(List <Element> elements) throws TransformException {
        for(int i = 0; i < elements.size() - 1; i++){
            Element curr = elements.get(i);
            Element next = elements.get(i + 1);
            
            if(curr instanceof NewElement && next instanceof FunctionElement){
                elements.set(i + 1, new NewClassElement((FunctionElement)next));
                elements.remove(curr);
                i = 0;
            }
        }
        return elements;
    }
    
}
