package compiler.readers.body;

import compiler.Script;
import compiler.helpers.SkipWhiteChar;
import compiler.instruction.Instruction;
import compiler.readers.SelectorReader;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.Pattern;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author sasza
 */
public class BodyCloseReader implements SelectorReader {
    
    private Script script;
    private ScriptSelector selector;
    private boolean used;

    @Override
    public List <Instruction> read(Script script, Pattern pattern, ScriptSelector selector) {        
        this.script   = script;
        this.selector = selector;
                
        if(used){
            close();
        } else {
            use();
        }
        
        List <Instruction> instructions = new ArrayList();
        return instructions;
    }
    
    private void use(){        
        selector.stop();
        used = true;
        script.incPos();
        SkipWhiteChar.skip(script);
    }
        
    private void close(){
        selector.stop();
    }
    
}
