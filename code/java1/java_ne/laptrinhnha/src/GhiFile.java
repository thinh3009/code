import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class GhiFile {

    public static void ghi_file() {
        FileOutputStream out =null;
        try{
            File f=new File("tho.dat");
            out = new FileOutputStream(f);
            String s= "khi ta o chi la noi dat o";
            out.write(s.getBytes());

        }catch(Exception ex){}
        finally{
            try{out.close();
            }catch(IOException ex){}
        }
    }
}
