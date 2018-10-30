package compiler.condition.transform.before;

import compiler.condition.element.Element;
import compiler.condition.element.bracket.BracketCloseElement;
import compiler.condition.element.bracket.BracketOpenElement;
import compiler.condition.element.function.FunctionElement;
import compiler.condition.element.function.NewClassElement;
import compiler.condition.transform.Transform;
import java.util.List;

/**
 *
 * @author sasza
 */
public class FunctionBracketsTransform implements Transform {

    @Override
    public List <Element> transform(List <Element> elements) throws TransformException {
        for(int i = 0; i < elements.size(); i++){
            Element e = elements.get(i);
            if(e instanceof FunctionElement || e instanceof NewClassElement){
                proceed(elements, i);
                i += 2;
            }
        }
        return elements;
    }
    
    private void proceed(List <Element> elements, int from){
        elements.add(from, new BracketOpenElement());
        int level = 0;
        for(int i = from + 1; i < elements.size(); i++){
            Element e = elements.get(i);
            if(e instanceof BracketOpenElement){
                level++;
            } else if(e instanceof BracketCloseElement){
                level--;
                if(level <= 0){
                    elements.add(i, new BracketCloseElement());
                    break;
                }
            }
        }
    }
    
}
