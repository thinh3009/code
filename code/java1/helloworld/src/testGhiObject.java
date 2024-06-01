import java.io.File;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;

public class testGhiObject {
    public static void main(String[] args) {
        try {
            File file = new File("C:/Users/ASUS TUF/Desktop/cpp_laptrinh/java1/helloworld/src/sv.dat");
            OutputStream os = new FileOutputStream(file);
            ObjectOutputStream oos= new ObjectOutputStream(os);
            arrayListSV sv = new arrayListSV("123", "bui duc thinh", 2002, 5.2f);
            oos.writeObject(sv);
            oos.flush();
            oos.close();
        } catch (Exception e) {
            // TODO: handle exception
        }
        
    }
}
