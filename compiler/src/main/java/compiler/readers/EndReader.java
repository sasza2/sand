package compiler.readers;

import compiler.Script;
import compiler.exception.CompilerException;
import compiler.instruction.Instruction;
import java.util.List;

/**
 *
 * @author sasza
 */
public class EndReader implements StandardReader {

    @Override
    public List <Instruction> read(Script script) {
        throw new CompilerException(script);
    }
    
}
