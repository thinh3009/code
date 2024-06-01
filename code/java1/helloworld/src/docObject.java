import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.ObjectInputStream;

public class docObject {
    public static void main(String[] args) {
        try {
            File file = new File("C:/Users/ASUS TUF/Desktop/cpp_laptrinh/java1/helloworld/src/sv.dat");
            InputStream is = new FileInputStream(file);
            ObjectInputStream ois= new ObjectInputStream(is);
            arrayListSV st=(arrayListSV) ois.readObject();
            System.out.println(st);
            //ois.flush();
            ois.close();
        } catch (Exception e) {
            // TODO: handle exception
            e.printStackTrace();
        }
        
    }
}
