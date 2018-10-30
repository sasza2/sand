package compiler.helpers.argument;

import java.util.ArrayList;
import java.util.stream.Collectors;

/**
 *
 * @author sasza
 */
public class Arguments extends ArrayList <Argument> {
    
    public String toAssembly(){
        return String.join(",", stream().map(a -> a.value()).collect(Collectors.toList()).toArray(new String[size()]));
    }
    
}
