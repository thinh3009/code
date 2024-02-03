//ghi file vao file text
//ghi dc len terminal
import java.io.PrintWriter;
public class GhiFile {
    public static void main(String args[]) {
        //PrintWriter pw;
        try {
            //truyen vao file
            PrintWriter pw = new PrintWriter("C:/Users/ASUS TUF/Desktop/cpp_laptrinh/java1/javaSwing_DB/Swing/src/file.txt","UTF8");
            pw.println("xin chao");
            pw.println("bui duc thinh");
            pw.println(3.14);
            pw.println("thinh ne");
            //day du lieu vao file
            pw.flush();
            //dong file
            pw.close();
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        
    }
    
}

