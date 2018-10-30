package compiler.condition.transform.before;

import compiler.condition.element.bracket.BracketCloseElement;
import compiler.condition.element.bracket.BracketOpenElement;
import compiler.condition.element.function.CommaElement;
import compiler.condition.element.Element;
import compiler.condition.element.function.FunctionElement;
import compiler.condition.element.bracket.SquareBracketCloseElement;
import compiler.condition.element.string.TemporaryStringElement;
import compiler.condition.transform.Transform;
import java.util.List;

/**
 *
 * @author sasza
 */
public class FunctionTransform implements Transform {

    private List<Element> elements;

    @Override
    public List<Element> transform(List<Element> elements) throws TransformException {
        this.elements = elements;

        updateStandard();
        updateSquare();

        return updateArgumentsCount();
    }

    private void updateStandard(){
        for (int i = 1; i < elements.size(); i++) {
            Element prev = elements.get(i - 1);
            Element curr = elements.get(i);

            if (prev instanceof TemporaryStringElement && curr instanceof BracketOpenElement) {
                elements.set(i - 1, new FunctionElement(prev.toString()));
            }
        }
    }

    private void updateSquare(){
        for(int i = 2; i < elements.size(); i++){
            Element curr = elements.get(i);
            Element prev = elements.get(i - 1);

            if(prev instanceof SquareBracketCloseElement && curr instanceof BracketOpenElement){
                elements.add(i, new FunctionElement("()"));
                i = 0;
            }
        }
    }

    private List<Element> updateArgumentsCount() {
        for (int i = 0; i < elements.size(); i++) {
            Element curr = elements.get(i);
            if (curr instanceof FunctionElement) {
                updateEach((FunctionElement) curr, i + 1);
            }
        }

        return elements;
    }

    private void updateEach(FunctionElement func, int from) {
        int level = 0;
        int args = 0;
        for (int c = from; c < elements.size(); c++) {
            Element e = elements.get(c);
            if (e instanceof BracketOpenElement) {
                level++;
            } else if (e instanceof BracketCloseElement) {
                level--;
                if (level == 0) {
                    if(from + 1 != c || args > 0){
                        args++;
                    }
                    func.setArgs(args);
                    break;
                }
            } else if (e instanceof CommaElement && level == 1) {
                args++;
            }
        }
    }

}
