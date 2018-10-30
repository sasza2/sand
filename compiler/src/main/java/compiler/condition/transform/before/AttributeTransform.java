package compiler.condition.transform.before;

import compiler.condition.element.Element;
import compiler.condition.element.bracket.SquareBracketCloseElement;
import compiler.condition.element.bracket.SquareBracketOpenElement;
import compiler.condition.element.function.AttributeElement;
import compiler.condition.transform.Transform;
import java.util.List;

/**
 *
 * @author sasza
 */
public class AttributeTransform implements Transform {

    @Override
    public List<Element> transform(List<Element> elements) throws TransformException {
        for (int i = 1; i < elements.size() - 1; i++) {
            Element prev = elements.get(i - 1);
            Element curr = elements.get(i);
            Element next = elements.get(i + 1);

            if (!isBetweenSquare(prev, next)) {
                continue;
            }

            elements.add(i + 1, new AttributeElement(((SquareBracketCloseElement) next).isNext()));

            elements.remove(prev);
            elements.remove(next);
            i = 0;
        }
        return elements;
    }

    private boolean isBetweenSquare(Element prev, Element next) {
        return prev instanceof SquareBracketOpenElement && next instanceof SquareBracketCloseElement;
    }

}
