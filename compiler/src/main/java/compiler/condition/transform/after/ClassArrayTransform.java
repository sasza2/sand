package compiler.condition.transform.after;

import compiler.condition.element.Element;
import compiler.condition.element.function.ClassArrayElement;
import compiler.condition.element.function.FunctionElement;
import compiler.condition.element.function.NewElement;
import compiler.condition.transform.Transform;
import compiler.condition.transform.before.TransformException;
import java.util.List;

/**
 *
 * @author sasza
 */
public class ClassArrayTransform implements Transform {

    @Override
    public List <Element> transform(List <Element> elements) throws TransformException {        
        for(int i = 1; i < elements.size(); i++){
            Element prev = elements.get(i - 1);
            Element curr = elements.get(i);
            
            if(prev instanceof FunctionElement && curr instanceof NewElement){
                elements.set(i, new ClassArrayElement((FunctionElement)prev));
                elements.remove(prev);
                elements.remove(curr);
            }
        }
        return elements;
    }
    
}
