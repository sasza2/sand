package compiler.readers;

import compiler.Script;
import compiler.instruction.Instruction;
import java.util.List;

/**
 *
 * @author sasza
 */
public interface StandardReader {
    
    public List <Instruction> read(Script script);
    
}
