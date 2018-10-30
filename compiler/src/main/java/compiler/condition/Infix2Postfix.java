package compiler.condition;

import compiler.condition.element.bracket.BracketCloseElement;
import compiler.condition.element.bracket.BracketOpenElement;
import compiler.condition.element.bracket.SquareBracketOpenElement;
import compiler.condition.element.bracket.SquareBracketCloseElement;
import compiler.condition.element.logical.LogicalElement;
import compiler.condition.element.function.CommaElement;
import compiler.condition.element.*;
import compiler.condition.element.function.AttributeElement;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Stack;
import java.util.stream.Collectors;

/**
 *
 * @author sasza
 */
public class Infix2Postfix {

    private Stack <Element> stack;
    private Stack <Element> output;

    public List <Element> convert(List <Element> elements){
        stack  = new Stack();
        output = new Stack();

        for(Element element : elements){
            if(element instanceof BracketOpenElement || element instanceof SquareBracketOpenElement){
                stack.add(element);
            } else if(element instanceof BracketCloseElement){
                popToClass(BracketOpenElement.class);
            } else if(element instanceof SquareBracketCloseElement){
                popToClass(SquareBracketOpenElement.class);
                output.push(element);
            } else if(element instanceof CommaElement){
                Element e = popToClass(BracketOpenElement.class, CommaElement.class);
                stack.push(e);
            } else if(element instanceof LogicalElement && ((LogicalElement)element).isSeparator()){
                popToClassPriority(element, SquareBracketOpenElement.class, BracketOpenElement.class);            
            } else if(element instanceof AttributeElement){
                output.push(element);
            } else if(element.priority().v() < 1){
                output.push(element);
            } else {
                popLowerThen(element);
            }
        }

        Collections.reverse(stack);
        output.addAll(stack);

        return removeNonImportant(output);
    }

    private List <Element> removeNonImportant(List <Element> elements){
        return elements.stream()
                       .filter(e -> {
                           return !e.isRemoveable();
                       })
                       .collect(Collectors.toList());
    }

    private Element popToClass(Class ... cls){
        if(stack.isEmpty()){
            return null;
        }

        List <Class> clsList = Arrays.asList(cls);
        Element e;
        for(e = stack.pop(); !clsList.contains(e.getClass()); e = stack.pop()){
            output.push(e);
            if(stack.isEmpty()){
                break;
            }
        }
        return e;
    }

    private void popToClassPriority(Element from, Class ... cls){
        List <Class> clsList = Arrays.asList(cls);
        for(int i = stack.size() - 1; !stack.isEmpty() && i >= 0; i--){
            Element e = stack.get(i);
            if(clsList.contains(e.getClass())){
                break;
            }
            output.push(stack.pop());
        }

        output.push(from);
    }

    private void popLowerThen(Element element){
        Element last = stack.isEmpty() ? null : stack.peek();
        if(last == null || element.priority().v() > last.priority().v()){
            stack.push(element);
        } else {
            for(Element e; !stack.isEmpty() && (e = stack.peek()).priority().v() >= element.priority().v(); stack.pop()){
                output.push(e);
            }
            stack.push(element);
        }
    }

}
