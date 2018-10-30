package compiler.condition.transform.before;

import compiler.condition.element.Element;
import compiler.condition.element.arthmetic.SubtractionElement;
import compiler.condition.element.bracket.BracketOpenElement;
import compiler.condition.element.bracket.SquareBracketOpenElement;
import compiler.condition.element.number.NumberElement;
import compiler.condition.transform.Transform;
import java.util.List;

/**
 *
 * @author sasza
 */
public class UnaryMinusTransform implements Transform {

    @Override
    public List <Element> transform(List <Element> elements) throws TransformException {
        for(int i = 0; i < elements.size() - 1; i++){                                    
            if(isStartingFromBracket(elements, i)){
                elements.set(i + 2, ((NumberElement)elements.get(i + 2)).changeSign());
                elements.remove(elements.get(i + 1));
                i = 0;
            } else if (isStartingFrom(elements, i)){
                elements.set(i + 1, ((NumberElement)elements.get(i + 1)).changeSign());
                elements.remove(elements.get(0));
            }
        }
        return elements;
    }
    
    private boolean isStartingFromBracket(List <Element> elements, int current){
        if(current + 2 >= elements.size()){
            return false;
        }
        
        return isBracketOpen(elements.get(current)) && isMinus(elements.get(current + 1)) && isNumber(elements.get(current + 2));
    }
    
    private boolean isStartingFrom(List <Element> elements, int current){
        Element curr = elements.get(current);
        Element next = elements.get(current + 1);
        return current == 0 && isMinus(curr) && isNumber(next);
    }
    
    private boolean isNumber(Element element){
        return element instanceof NumberElement;
    }
    
    private boolean isBracketOpen(Element element){
        return element instanceof BracketOpenElement || element instanceof SquareBracketOpenElement; 
    }
    
    private boolean isMinus(Element element){
        return element instanceof SubtractionElement;
    }
    
}
