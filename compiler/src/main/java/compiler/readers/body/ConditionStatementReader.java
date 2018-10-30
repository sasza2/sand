package compiler.readers.body;

import compiler.Script;
import compiler.condition.ConditionRead;
import compiler.condition.ConditionTransform;
import compiler.condition.Infix2Postfix;
import compiler.condition.element.Element;
import compiler.condition.transform.before.TransformException;
import compiler.exception.CompilerException;
import compiler.helpers.SkipWhiteChar;
import compiler.instruction.ConditionEndInstruction;
import compiler.instruction.Instruction;
import compiler.readers.SelectorReader;
import compiler.readers.StandardReader;
import compiler.selector.ScriptSelector;
import compiler.selector.pattern.Pattern;
import java.util.List;
import java.util.stream.Collectors;

/**
 *
 * @author sasza
 */
public class ConditionStatementReader implements StandardReader, SelectorReader {

    @Override
    public List <Instruction> read(Script script) {
        ConditionRead condition = new ConditionRead();
        List <Element> elements = condition.read(script);
                
        try {
            elements = ConditionTransform.before(elements);            
        } catch(TransformException e){
            throw new CompilerException(script);
        }
                        
        Infix2Postfix converter = new Infix2Postfix();
        List <Element> postfix = converter.convert(elements);
        
        try {
            elements = ConditionTransform.after(elements);            
        } catch(TransformException e){
            throw new CompilerException(script);
        }
        
        List <Instruction> instructions =
                (List<Instruction>)postfix.stream()
                      .filter(e -> {
                          return e instanceof Instruction;
                      })
                      .map(i -> {
                          return (Instruction)i;
                      })
                      .collect(Collectors.toList());
        
        if(!instructions.isEmpty()){
            instructions.add(new ConditionEndInstruction());
        }
        
        SkipWhiteChar.skip(script);
        
        return instructions;
    }

    @Override
    public List<Instruction> read(Script script, Pattern pattern, ScriptSelector selector) {
        return read(script);
    }
    
}
