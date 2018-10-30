package compiler.readers;

import compiler.Code;
import compiler.Script;
import org.junit.Test;

/**
 *
 * @author sasza
 */
public class ScriptAllReaderTest {
    
    @Test
    public void test1(){
        Script script = new Script();
        script.setCode(Code.fromStr("class App { main(){ system(0, \"hej\"); } }"));
        ScriptAllReader scriptAllReader = new ScriptAllReader();
        try {
            System.out.println(scriptAllReader.read(script));
        } catch(Exception e){
            e.printStackTrace();
        }
    }
    
}
