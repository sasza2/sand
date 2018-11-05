package compiler.condition;

import compiler.condition.element.bracket.*;
import compiler.condition.element.logical.*;
import compiler.condition.element.arthmetic.*;
import compiler.condition.element.function.CommaElement;
import compiler.condition.element.equals.EqualElement;
import compiler.condition.element.Element;
import compiler.ParserConsumer;
import compiler.Script;
import compiler.condition.element.assignment.EqualAssignmentElement;
import compiler.condition.element.equals.*;
import compiler.condition.element.function.NewElement;
import compiler.condition.element.number.BooleanElement;
import compiler.exception.CompilerException;
import compiler.helpers.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.function.Supplier;

/**
 *
 * @author sasza
 */
public class ConditionRead {
    
    private final Map <String, Supplier<Element>> suppliers = createSuppliers();        
    private final List <Element> elements = new ArrayList();
    private int lvl = 0;
    
    public List <Element> read(Script script){                
        SkipWhiteChar.skip(script);
        
        ParserConsumer pc = script.next(parser -> {                
            char c = parser.current();
            if(c == '('){
                lvl++;
            } else if(c == ')'){
                lvl--;
            }
                        
            if(lvl < 0){
                parser.stopAndInc();
                return;
            }
            
            if(popSuppliers(parser)){
                return;
            }                                    
            
            if(c == ';' || c == '{'){
                parser.stopAndInc();
            } else if(c == '}'){
                parser.stop();
            } else if(c == ' ' || c == '\n'){                
                parser.inc();
            } else if(c == '"'){
                elements.add(ReadString.read(script));
            } else if(Character.isDigit(c)){
                elements.add(ReadNumber.read(script));
            } else if(Character.isLetter(c)){
                elements.add(ReadDigitsAndLetters.read(script, '_'));
            } else {
                throw new CompilerException(script);
            }
        });
        
        return elements;
    }
    
    private boolean popSuppliers(ParserConsumer parser){
        int s = elements.size();
        
        suppliers.entrySet()
                    .stream()
                    .filter(e -> {
                        return parser.next(e.getKey().length()).equals(e.getKey());
                    })
                    .findAny()
                    .ifPresent(e -> {
                        int len = e.getKey().length();
                        if(parser.couldInc(len)){
                            parser.inc(e.getKey().length());
                        } else {
                            parser.stop();
                        }
                        elements.add(e.getValue().get());
                    });
        
        return s != elements.size();
    }
    
    private Map <String, Supplier<Element>> createSuppliers(){
        Map <String, Supplier<Element>> elements = new HashMap();
        elements.put("false", () -> new BooleanElement(false));
        elements.put("true",  () -> new BooleanElement(true));
        elements.put("new ",  () -> new NewElement());
        elements.put("++",    () -> new IncElement());
        elements.put("--",    () -> new DecElement());
        elements.put("||",    () -> new OrElement());
        elements.put("&&",    () -> new AndElement());
        elements.put("==",    () -> new EqualElement());
        elements.put("!=",    () -> new NotEqualElement());
        elements.put(">=",    () -> new GreaterEqualElement());
        elements.put("<=",    () -> new LowerEqualElement());
        elements.put(">",     () -> new GreaterElement());
        elements.put("<",     () -> new LowerElement());
        elements.put("(",     () -> new BracketOpenElement());
        elements.put(")",     () -> new BracketCloseElement());
        elements.put("[",     () -> new SquareBracketOpenElement());
        elements.put("]",     () -> new SquareBracketCloseElement());
        elements.put(",",     () -> new CommaElement());
        elements.put("%",     () -> new ModElement());
        elements.put("*",     () -> new MultiplyElement());
        elements.put("+",     () -> new AdditionElement());
        elements.put("/",     () -> new DivisionElement());
        elements.put("-",     () -> new SubtractionElement());
        elements.put("^",     () -> new PowerElement());
        elements.put("!",     () -> new NotElement());        
        elements.put(".",     () -> new DotElement());
        elements.put("=",     () -> new EqualAssignmentElement());
        return elements;
    }
    
}
