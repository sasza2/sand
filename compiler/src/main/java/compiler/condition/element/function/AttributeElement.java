package compiler.condition.element.function;

import compiler.condition.element.Element;
import compiler.condition.element.Priority;
import compiler.instruction.Instruction;

/**
 *
 * @author sasza
 */
public class AttributeElement implements Element, Instruction {

    private final boolean type;
    
    public AttributeElement(boolean type){
        this.type = type;
    }
    
    /*public AttributeElement(String value){
        this.value = value;
    }
    
    public String value(){
        return value;
    }*/
    
    @Override
    public Priority priority() {
        return Priority.ATTRIBUTE;
    }
    
    @Override
    public String toString(){
        return "]";
    }

    @Override
    public String toAssembly() {
        return "NEXT" + (type ? " IN" : "");
    }
    
}
