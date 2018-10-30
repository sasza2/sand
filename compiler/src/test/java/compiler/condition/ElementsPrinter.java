package compiler.condition;

import compiler.Script;
import compiler.condition.element.Element;
import java.util.List;

/**
 *
 * @author sasza
 */
public class ElementsPrinter {
   
    public static String print(Script script){
        final StringBuilder sb = new StringBuilder();
        
        ConditionRead condition = new ConditionRead();
        sb.append(script.getCode())
          .append("\n")
          .append(print(condition.read(script)));
        
        return sb.toString();
    }
    
    public static String print(List <Element> elements){        
        final StringBuilder sb = new StringBuilder();
        elements.forEach(e -> {
            sb.append(e.toString());
        });
        
        sb.append("\n");
        return sb.toString();
    }    
    
}
