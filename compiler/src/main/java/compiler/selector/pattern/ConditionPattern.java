package compiler.selector.pattern;

import compiler.Code;
import compiler.ParserConsumer;
import compiler.Script;
import compiler.condition.ConditionRead;
import compiler.condition.ConditionTransform;
import compiler.condition.Infix2Postfix;
import compiler.condition.element.Element;
import compiler.condition.transform.before.TransformException;
import java.util.List;
import java.util.function.Consumer;

/**
 *
 * @author sasza
 */
public class ConditionPattern implements Pattern {
    
    private String value;

    @Override
    public boolean match(Script script) {
        int pos = script.getPos();
        ParserConsumer pc = script.next(new Consumer <ParserConsumer>(){
            boolean inString = false;
            public void accept(ParserConsumer parser) {
                if(parser.current() == '"'){
                    inString = !inString;
                    parser.inc();
                } else if(!inString && parser.current() == ';'){
                    parser.stopAndInc();
                } else {
                    parser.inc();
                }
            }
        });
        
        script.decPos(script.getPos() - pos);
        value = pc.all();
                       
        if(!value.endsWith(";")){
            return false;
        }
        
        return check(value);
    }
    
    private boolean check(String code){
        Script script = new Script();
        script.setCode(Code.fromStr(code));
        
        ConditionRead condition = new ConditionRead();
        List <Element> elements = condition.read(script);        
        try {
            elements = ConditionTransform.before(elements);            
        } catch (TransformException e) {
            return false;
        }
                                
        Infix2Postfix converter = new Infix2Postfix();
        elements = converter.convert(elements);
        
        try {
            elements = ConditionTransform.after(elements);            
        } catch (TransformException e) {
            return false;
        }        
                
        return elements.size() > 0;
    }

    @Override
    public String value() {
        return value;
    }
    
}
