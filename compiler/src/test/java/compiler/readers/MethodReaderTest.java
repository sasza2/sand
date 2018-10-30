package compiler.readers;

import compiler.Code;
import compiler.Script;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.StringPattern;
import org.junit.Test;

/**
 *
 * @author sasza
 */
public class MethodReaderTest {
    
    @Test
    public void test1(){
        Script script = new Script();
        script.setCode(Code.fromStr("a,b,c){ } "));
        MethodReader methodReader = new MethodReader();
        methodReader.read(script, new StringPattern("test"), new ScriptSelector());        
    }
    
}
