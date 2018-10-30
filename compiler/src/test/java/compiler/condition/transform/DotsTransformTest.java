package compiler.condition.transform;

import compiler.condition.transform.before.DotsTransform;
import compiler.condition.ElementsPrinter;
import compiler.condition.element.bracket.DotElement;
import compiler.condition.element.Element;
import compiler.condition.element.bracket.SquareBracketCloseElement;
import compiler.condition.element.bracket.SquareBracketOpenElement;
import compiler.condition.element.string.TemporaryStringElement;
import java.util.ArrayList;
import java.util.List;
import org.junit.Test;

/**
 *
 * @author sasza
 */
public class DotsTransformTest {
    
    @Test
    public void test1() throws Exception {
        DotsTransform transform = new DotsTransform();
        List <Element> elements = new ArrayList();
        elements.add(new TemporaryStringElement("a"));
        elements.add(new DotElement());
        elements.add(new TemporaryStringElement("b"));
        elements.add(new DotElement());
        elements.add(new TemporaryStringElement("c"));
        elements.add(new DotElement());
        elements.add(new TemporaryStringElement("d"));
        
        elements = transform.transform(elements);
        ElementsPrinter.print(elements);
    }
    
    @Test
    public void test2() throws Exception {
        DotsTransform transform = new DotsTransform();
        List <Element> elements = new ArrayList();
        elements.add(new TemporaryStringElement("this"));
        elements.add(new DotElement());
        elements.add(new TemporaryStringElement("user"));
        elements.add(new SquareBracketOpenElement());
        elements.add(new TemporaryStringElement("name"));        
        elements.add(new SquareBracketCloseElement());
        
        elements = transform.transform(elements);
        ElementsPrinter.print(elements);
    }
    
}
