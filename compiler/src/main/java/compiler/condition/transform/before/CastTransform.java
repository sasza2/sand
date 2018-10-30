package compiler.condition.transform.before;

import compiler.condition.element.Element;
import compiler.condition.element.bracket.BracketCloseElement;
import compiler.condition.element.bracket.BracketOpenElement;
import compiler.condition.element.function.CastElement;
import compiler.condition.element.function.FunctionElement;
import compiler.condition.element.string.TemporaryStringElement;
import compiler.condition.transform.Transform;
import java.util.List;

/**
 *
 * @author sasza
 */
public class CastTransform implements Transform {

    @Override
    public List <Element> transform(List <Element> elements) throws TransformException {
        for(int i = 1; i < elements.size() - 2; i++){
            Element prev = elements.get(i - 1);
            Element curr = elements.get(i);
            Element next = elements.get(i + 1);
            
            if(isCast(prev, curr, next) && !isAfterFunction(elements, i)){
                elements.set(i, new CastElement(((TemporaryStringElement)elements.get(i)).value()));
                elements.remove(prev);
                elements.remove(next);
                i = 1;                
            }
        }
        return elements;
    }
    
    private boolean isCast(Element prev, Element curr, Element next){
        return prev instanceof BracketOpenElement && curr instanceof TemporaryStringElement && next instanceof BracketCloseElement;
    }
    
    private boolean isAfterFunction(List <Element> elements, int current){
        if(current < 2){
            return false;
        }
        
        Element element = elements.get(current - 2);
        return element instanceof FunctionElement;
    }
    
}
