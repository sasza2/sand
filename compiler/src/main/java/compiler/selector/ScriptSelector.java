package compiler.selector;

import compiler.Script;
import compiler.instruction.Instruction;
import compiler.readers.SelectorReader;
import compiler.readers.StandardReader;
import compiler.selector.pattern.Pattern;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

/**
 *
 * @author sasza
 */
public class ScriptSelector {
    
    private final Map <Pattern, SelectorReader> readers;
    private StandardReader last;
    private boolean running = true;
    
    public ScriptSelector(){
        readers = new LinkedHashMap();
    }
    
    public ScriptSelector add(Pattern pattern, SelectorReader reader){
        readers.put(pattern, reader);
        return this;
    }
    
    public ScriptSelector orElse(StandardReader reader){
        last = reader;
        return this;
    }
    
    public List <Instruction> run(Script script){
        List <Instruction> instructions = new ArrayList();        
        int i;
        for(i = 0; running && parseReaders(script, instructions); i++);
        if(last == null){
            return instructions;
        }
        
        return i == 0 && running ? last.read(script) : instructions;
    }
    
    private boolean parseReaders(Script script, List <Instruction> instructions){        
        for(Entry <Pattern, SelectorReader> reader : readers.entrySet()){
            if(reader.getKey().match(script)){
                SelectorReader sr = reader.getValue();
                List <Instruction> instructionsToAdd = sr.read(script, reader.getKey(), this);
                if(instructionsToAdd != null){
                    instructions.addAll(instructionsToAdd);                    
                }
                return true;
            }
        }
        return false;
    }
    
    public void stop(){
        running = false;
    }
    
    public static ScriptSelector create(){
        return new ScriptSelector();
    }
    
}
