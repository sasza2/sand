package compiler.instruction.level;

/**
 *
 * @author sasza
 */
public class LevelGenerator {
    
    private static int lvl;
    
    public static int next(){
        return lvl++;
    }
    
}
