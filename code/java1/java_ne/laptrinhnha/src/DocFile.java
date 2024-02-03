import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class DocFile {
    public static void doc_file() {
        FileInputStream in =null;
        try {
            File f =new File("tho.dat"); 
            in= new FileInputStream(f);
            int kq;
            do{
                kq=in.read();
                System.out.println((char) kq);
            }while(kq!=-1);
            
        } catch (Exception ex) {
            
        }
        finally{
            try{
                in.close();
            }catch(IOException ex){
                
            }
        }
    }
}
