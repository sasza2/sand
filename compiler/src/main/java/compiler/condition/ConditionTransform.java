package compiler.condition;

import compiler.condition.transform.before.DeleteTransform;
import compiler.condition.transform.before.*;
import compiler.condition.element.Element;
import compiler.condition.transform.Transform;
import compiler.condition.transform.after.*;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author sasza
 */
public class ConditionTransform {
    
    public static List <Element> before(List <Element> elements) throws TransformException {
        List <Transform> transforms = new ArrayList();
        transforms.add(new DeleteTransform());
        transforms.add(new IncDecTransform());
        transforms.add(new DotsTransform());
        transforms.add(new FunctionTransform());       
        transforms.add(new UnaryMinusTransform());
        transforms.add(new CastTransform());
        transforms.add(new ClassTransform());
        transforms.add(new AttributeTransform());
        transforms.add(new FunctionBracketsTransform());             
        transforms.add(new AssignmentTransform());    
        return loop(elements, transforms);
    }    
    
    public static List <Element> after(List <Element> elements) throws TransformException {
        List <Transform> transforms = new ArrayList();
        transforms.add(new ClassArrayTransform());
        transforms.add(new BracketOpenRemoveTransform());        
        return loop(elements, transforms);
    }
    
    private static List <Element> loop(List <Element> elements, List <Transform> transforms) throws TransformException {
        for(Transform transform : transforms){
            transform.transform(elements);
        }
        
        return elements;
    }
    
}
