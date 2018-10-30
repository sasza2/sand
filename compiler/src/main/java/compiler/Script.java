package compiler;

import compiler.exception.CompilerException;
import compiler.selector.pattern.Pattern;
import java.util.function.Consumer;

/**
 *
 * @author sasza
 */
public class Script {
    
    private int pos;
    private int line = 1;
    private int linePos = 1;
    private Code code;
    private Pattern patternCurrent;
    private boolean eoc; //reach end of code
    
    public int getPos(){
        return pos;
    }
    
    public int getLine(){
        return line;
    }
    
    public int getLinePos(){
        return linePos;
    }
    
    public void incPos(){
        if(pos + 1 >= code.length()){
            throw new CompilerException(this);
        }
        if(code.charAt(pos) == '\n'){
            line++;
            linePos = 0;
        }
        linePos++;
        pos++;
    }
    
    public void incPos(int c){
        if(pos + c >= code.length()){
            throw new CompilerException(this);
        }
        for(int i = pos; i < pos + c; i++){
            if(code.charAt(i) == '\n'){
                line++;
                linePos = 0;
            }
            linePos++;
        }        
        pos += c;
    }
    
    public void decPos(int c){
        if(pos - c < 0){
            throw new CompilerException(this);
        }
        
        line    = 1;
        linePos = 0;
        
        for(int i = 0; i <= pos - c; i++){
            if(code.charAt(i) == '\n'){
                line++;
                linePos = 0;
            }
            linePos++;
        }        
        pos -= c;
    }

    public Code getCode() {
        return code;
    }

    public void setCode(Code code) {
        this.code = code;
    }
    
    public char next(){
        if(pos >= code.length()){
            throw new CompilerException(this);
        }
        return code.charAt(pos);
    }
    
    public ParserConsumer next(Consumer <ParserConsumer> consumer){
        ParserConsumer parser = new ParserConsumer(this);
        while(!eoc && !parser.isStopped()){            
            consumer.accept(parser);
        }
        return parser;
    }        
    
    public String next(int count){
        if(pos + count >= code.length()){
            throw new CompilerException(this);
        }
        int to = pos + count >= code.length() ? code.length() - 1 : pos + count;
        return code.substring(pos, to);
    }

    public Pattern getPatternCurrent() {
        return patternCurrent;
    }

    public void setPatternCurrent(Pattern patternCurrent) {
        this.patternCurrent = patternCurrent;
    }

    public boolean isEoc() {
        return eoc;
    }

    public void setEoc() {
        eoc = true;
    }        
            
}
