package compiler;

/**
 *
 * @author sasza
 */
public class Code {

    private String code;
    private int length;

    private Code(){
    }

    public static Code fromStr(String str){
        Code code   = new Code();
        code.code   = str + "\n";
        code.length = code.code.length();
        return code;
    }

    public int length(){
        return length;
    }

    public char charAt(int pos){
        return code.charAt(pos);
    }

    public String substring(int from){
        return code.substring(from);
    }

    public String substring(int from, int to){
        return code.substring(from, to);
    }

}
