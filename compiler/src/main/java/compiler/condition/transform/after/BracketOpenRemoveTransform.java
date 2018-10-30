package compiler.condition.transform.after;

import compiler.condition.element.Element;
import compiler.condition.element.bracket.SquareBracketOpenElement;
import compiler.condition.transform.Transform;
import compiler.condition.transform.before.TransformException;
import java.util.List;
import java.util.stream.Collectors;

/**
 *
 * @author sasza
 */
public class BracketOpenRemoveTransform implements Transform {

    @Override
    public List<Element> transform(List<Element> elements) throws TransformException {
        List <Element> elementsWithoutBracket = elements.stream()
                       .filter(element -> {                           
                            return !(element instanceof SquareBracketOpenElement);
                       })
                       .collect(Collectors.toList());        
        
        elements.clear();
        elements.addAll(elementsWithoutBracket);
        return elements;
    }
    
}
