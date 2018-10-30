package compiler.condition.transform.before;

import compiler.condition.element.bracket.DotElement;
import compiler.condition.element.Element;
import compiler.condition.element.bracket.SquareBracketCloseElement;
import compiler.condition.element.bracket.SquareBracketOpenElement;
import compiler.condition.element.string.TemporaryStringElement;
import compiler.condition.transform.Transform;
import java.util.List;

/**
 *
 * @author sasza
 */
public class DotsTransform implements Transform {

    private List <Element> elements;

    @Override
    public List <Element> transform(List <Element> elements) throws TransformException {
        this.elements = elements;

        for(int i = 1; i < elements.size() - 1; i++){
            Element curr = elements.get(i);
            Element next = elements.get(i + 1);

            if(!(curr instanceof DotElement)){
                continue;
            }

            if(next instanceof TemporaryStringElement){
                nextString(next, curr, i);
            } else {
                throw new TransformException();
            }


            i = 1;
        }

        return elements;
    }

    private void nextString(Element next, Element curr, int i){
        elements.remove(next);
        elements.add(i, new SquareBracketOpenElement());
        elements.add(i + 1, next);
        elements.add(i + 2, new SquareBracketCloseElement(true));
        elements.remove(curr);
    }
    
}
