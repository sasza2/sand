package compiler.condition.transform.before;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.condition.element.bracket.BracketCloseElement;
import compiler.condition.element.bracket.BracketOpenElement;
import compiler.condition.transform.Transform;
import java.util.List;

/**
 *
 * @author sasza
 */
public class AssignmentTransform implements Transform {

    @Override
    public List <Element> transform(List <Element> elements) throws TransformException {
        for(int i = 0; i < elements.size(); i++){
            Element element = elements.get(i);
            if(element.priority().equals(Priority.ASSIGNMENT)){
                elements.add(i + 1, new BracketOpenElement());
                elements.add(new BracketCloseElement());
                break;
            }
        }
        return elements;
    }
    
}
