import compiler.Code;
import compiler.Script;
import compiler.exception.CompilerException;
import compiler.logger.CompilerLogger;
import compiler.readers.ScriptAllReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.file.Files;
import java.util.Arrays;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.apache.commons.cli.CommandLine;
import org.apache.commons.cli.CommandLineParser;
import org.apache.commons.cli.DefaultParser;
import org.apache.commons.cli.Option;
import org.apache.commons.cli.Options;
import org.apache.commons.cli.ParseException;

/**
 *
 * @author sasza
 */
public class Compiler {
    
    private File source, target, project;
    
    private void Compiler(){
        
    }
    
    public static void main(String [] args){
        CompilerLogger.get()
                      .setLevel(Level.OFF);
        Compiler compiler = new Compiler();
                        
        Options options = new Options();        
        options.addOption(Option.builder("P")
                                        .required(true)
                                        .desc("Path to project")
                                        .longOpt("path")
                                        .hasArg()
                                        .build());
        
        CommandLine commandLine;
        CommandLineParser parser = new DefaultParser();
        try {      
            commandLine = parser.parse(options, args);
        } catch (ParseException ex) {
            System.out.println(ex.getMessage());
            return;
        }
                
        compiler.run(commandLine.getOptionValue("path"));        
    }        
    
    private void run(String path){
        if(path == null){
            throw new NullPointerException("path is null");
        }
        
        project = new File(path);
        source  = new File(project.getAbsolutePath() + "/src");
        target  = new File(project.getAbsolutePath() + "/target");
        
        final int dirLen = source.getAbsolutePath().length() + 1;
        
        Arrays.asList(source.listFiles())
              .stream()
              .map(file -> {
                  return file.getAbsolutePath().substring(dirLen);
              })
              .forEach(fileName -> {
                   each(fileName);
              });
    }
    
    private void each(String name){
        String content;
        try {
            content = new Scanner(new File(source.getAbsolutePath() + "/" + name)).useDelimiter("\\Z").next();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Compiler.class.getName()).log(Level.SEVERE, null, ex);
            content = "";
        }
        Script script = new Script();
        script.setCode(Code.fromStr(content));
        
        ScriptAllReader scriptAllReader = new ScriptAllReader();
        try {
            StringBuilder code = new StringBuilder();
            scriptAllReader.read(script)
                           .forEach(i -> {
                               code.append(i.toAssembly())
                                   .append("\n");                               
                           });
            
            File compiled = new File(target.getAbsolutePath() + "/" + name);
            compiled.delete();
            compiled.createNewFile();
            Files.write(compiled.toPath(), code.toString().getBytes());
        } catch(CompilerException e){
            System.out.println(e);
            e.printStackTrace();
        } catch (IOException ex) {
            Logger.getLogger(Compiler.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}
