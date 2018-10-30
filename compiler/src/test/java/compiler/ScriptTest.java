package compiler;

import static org.junit.Assert.assertEquals;
import org.junit.Test;

/**
 *
 * @author sasza
 */

public class ScriptTest {

    @Test
    public void test1(){
        Script script = new Script();
        script.setCode(Code.fromStr("class { }"));
        
        assertEquals("class ", script.next(6));
        assertEquals("class", script.next(5));
    }
    
    @Test
    public void test2(){
        Script script = new Script();
        script.setCode(Code.fromStr("import 'xyz'"));
        
        assertEquals("import ", script.next(7)); 
    }
    
    @Test
    public void test3(){
        Script script = new Script();
        script.setCode(Code.fromStr("  class {}"));
        script.incPos(2);
        
        assertEquals("class ", script.next(6));
    }
    
}
