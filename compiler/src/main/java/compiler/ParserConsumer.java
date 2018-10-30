package compiler;

import compiler.exception.CompilerException;

/**
 *
 * @author sasza
 */
public class ParserConsumer {

    private final Script script;
    private boolean stop;
    private String all = "";
    private String helper = "";
    
    public ParserConsumer(Script script){
        this.script = script;
    }

    public Character prev() {
        return script.getPos() - 1 == 0 ? null : script.getCode().charAt(script.getPos() - 1);
    }
    
    public String next(int count){
        if(script.getPos() + count >= script.getCode().length()){
            return script.getCode().substring(script.getPos());
        }
        return script.next(count);
    }

    public char current() {
        if (script.getPos() >= script.getCode().length()) {
            throw new CompilerException(script);
        }
        return script.getCode().charAt(script.getPos());
    }

    public boolean isStopped() {
        return stop;
    }

    public void stop() {
        stop = true;
    }

    public void inc() {        
        all += script.getCode().charAt(script.getPos());
        if(script.getPos() + 1 >= script.getCode().length()){
            stop();  
            script.setEoc();
        } else {
            script.incPos();
        }
    }
    
    public void inc(int count){
        script.incPos(count);
    }
    
    public boolean couldInc(int count){
        return !(script.getPos() + count >= script.getCode().length());
    }

    public String all() {
        return all;
    }
    
    public boolean last(String value){                
        if(all.length() < value.length()){
            return false;
        }                
        
        return all.substring(all.length() - value.length()).equals(value);
    }

    public void stopAndInc() {
        inc();
        stop();
    }
    
    public String helper(){
        return helper;
    }
    
    public void helperAdd(char c){
        helper += c;
    }
    
    public void helperClear(){
        helper = "";
    }

}
