package compiler.condition.transform.before;

import compiler.condition.element.Element;
import compiler.condition.element.assignment.EqualAssignmentElement;
import compiler.condition.element.other.DeleteElement;
import compiler.condition.element.other.UndefinedElement;
import compiler.condition.transform.Transform;
import java.util.List;

/**
 *
 * @author sasza
 */
public class DeleteTransform implements Transform {

    @Override
    public List <Element> transform(List <Element> elements) throws TransformException {       
        for(int i = 0; i < elements.size(); i++){
            Element element = elements.get(i);            
            if(!(element instanceof DeleteElement)){
                continue;
            }            
            
            elements.remove(element);
            elements.add(new EqualAssignmentElement()); 
            elements.add(new UndefinedElement());                      
        }
        
        return elements;
    }

}
