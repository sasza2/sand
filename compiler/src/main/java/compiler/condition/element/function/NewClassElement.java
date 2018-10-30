package compiler.condition.element.function;

import compiler.condition.element.Priority;

/**
 *
 * @author sasza
 */
public class NewClassElement extends FunctionElement {
    
    public NewClassElement(String name) {
        super(name);
    }
    
    public NewClassElement(FunctionElement function){
        super(function.name);
        this.args = function.args;
    }
    
    @Override
    public Priority priority(){
        return Priority.CLASS;
    }
    
    @Override
    public String toString(){
        return name + ":" + args + ":new";
    }    
    
    @Override
    public String toAssembly() {
        return "NEW " + args + " " + name;
    }
    
}
