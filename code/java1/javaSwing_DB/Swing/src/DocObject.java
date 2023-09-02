import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;

public class DocObject {
    public static void main(String[] args) throws IOException {
        List<student> list= new ArrayList<>();
        /*ghi du lieu */
        // list.add(new student("20h1120258", "bui duc thinh", "cn20clcb"));
        // list.add(new student("20h1120258", "bui duc thinh", "cn20clcb"));
        // list.add(new student("20h1120258", "bui duc thinh", "cn20clcb"));
        // //tao 1 object
        // FileOutputStream out =null;
        // ObjectOutputStream objectOutputStream=null;
        // try {
        //     out=new FileOutputStream("sv.dat");
        //     objectOutputStream = new ObjectOutputStream(out);
        //     objectOutputStream.writeObject(list);
        // } catch (Exception e) {
        //     // TODO: handle exception
        // } finally{
        //     if(out!=null){
        //         out.close();
        //     }
        //     if(objectOutputStream!=null){
        //         objectOutputStream.close();
        //     }
        // }
        /*doc du lieu */
        FileInputStream in=null ;
        ObjectInputStream inputStream =null;
        try {
            in = new FileInputStream("sv.dat");
            inputStream= new ObjectInputStream(in);
            list=(List<student>) inputStream.readObject();
        } catch (Exception e) {
            e.printStackTrace();
            // TODO: handle exception
        } finally{
            if(inputStream !=null){
                inputStream.close();
            }

        }
        System.out.println("ket qua");
        for (int i = 0; i < list.size(); i++) {
            list.get(i).display();
        }
    }
}
