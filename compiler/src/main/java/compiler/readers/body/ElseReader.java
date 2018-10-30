package compiler.readers.body;

import compiler.Script;
import compiler.exception.CompilerException;
import compiler.helpers.SkipWhiteChar;
import compiler.helpers.VerifyNext;
import compiler.instruction.ElseIfEndInstruction;
import compiler.instruction.ElseIfInstruction;
import compiler.instruction.ElseInstruction;
import compiler.instruction.IfJumpInstruction;
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
public class ElseReader implements SelectorReader {

    private Script script;
    private boolean end;
    private final int lvl;

    public ElseReader(int lvl){
        this.lvl = lvl;
    }

    @Override
    public List <Instruction> read(Script script, Pattern pattern, ScriptSelector selector) {
        this.script = script;

        if(end){
            throw new CompilerException(script);
        }

        SkipWhiteChar.skip(script);

        List <Instruction> instructions = new ArrayList();
        if(script.next() == '{'){
            instructions.addAll(createElse());
        } else if(script.next(2).equals("if")){
            instructions.addAll(createElseIf());
        }

        VerifyNext.verify(script, '}');

        return instructions;
    }

    private List <Instruction> createElse(){
        List <Instruction> instructions = new ArrayList();
        instructions.add(new ElseInstruction(lvl));

        script.incPos();
        instructions.addAll(BodyReader.nonEnding().read(script));
        end = true;
        return instructions;
    }

    private List <Instruction> createElseIf(){
        List <Instruction> instructions = new ArrayList();
        instructions.add(new ElseIfInstruction(lvl));

        script.incPos(2); //skip "if" word
        ConditionStatementReader conditionStatementReader = new ConditionStatementReader();
        instructions.addAll(conditionStatementReader.read(script));
        instructions.add(new IfJumpInstruction(lvl));

        SkipWhiteChar.skip(script);
        instructions.addAll(BodyReader.nonEnding().read(script));
        instructions.add(new ElseIfEndInstruction(lvl));

        return instructions;
    }

}
