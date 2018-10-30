package compiler.condition.element;

/**
 *
 * @author sasza
 */
public enum Priority {
    
    OTHER(0),   
    BRACKET(0),    
    ASSIGNMENT(1),
    OR(2),
    AND(3),
    EQUAL(4),
    LESS_GREATER_EQ(5),
    BITWISE(6),
    ADD_SUB(7),
    MUL_DIV_MOD(8),
    POWER(9),
    NOT(10),   
    INC_DEC(10),
    ATTRIBUTE(11),
    FUNCTION(12),
    CLASS(13);
    
    private int value;
    
    Priority(int value){
        this.value = value;
    }
    
    public int v(){
        return value;
    }
    
}
