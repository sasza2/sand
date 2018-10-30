package compiler.condition;

import compiler.Code;
import compiler.Script;
import org.junit.Test;

/**
 *
 * @author sasza
 */
public class ConditionReadTest {
    
    @Test
    public void test1(){
        Script script = new Script();
        script.setCode(Code.fromStr("2.81 * (3 / 4 * x(5,4, abc)) + 10"));
        ElementsPrinter.print(script);
    }
    
    @Test
    public void test2(){
        Script script = new Script();
        script.setCode(Code.fromStr("ab[x(3, 4) + mn[8]] + b[22] / c"));
        ElementsPrinter.print(script);
    }
    
    @Test
    public void test3(){
        Script script = new Script();
        script.setCode(Code.fromStr("-15 + 34"));
        ElementsPrinter.print(script);
    }    
    
    @Test
    public void test4(){
        Script script = new Script();
        script.setCode(Code.fromStr("this.callback[5]()"));
        System.out.println(ElementsPrinter.print(script));
    }
    
}
