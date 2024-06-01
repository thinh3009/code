import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.util.ArrayList;

public class arrayListdsSV {
    private ArrayList<arrayListSV> danhSach;
    //constructor rong
    public arrayListdsSV(){
        this.danhSach = new ArrayList<arrayListSV>();
    }
    //constructor rieng
    public arrayListdsSV(ArrayList<arrayListSV> danhsach){
        
        this.danhSach=danhsach;
    }

    public void themSV(arrayListSV sv){
        //them sv vao cuoi ds
        this.danhSach.add(sv);
    }

    //in danh sach sv
    public void inDS() {
        for (arrayListSV arrayListSV : danhSach) {
            System.out.println(arrayListSV);
        }
    }
    //ghi file
    public void ghiFile(File file){
        try {
            OutputStream os = new FileOutputStream(file);
            ObjectOutputStream oos= new ObjectOutputStream(os);
            
            
            for (arrayListSV arrayListSV : danhSach) {
                oos.writeObject(arrayListSV);
            }
            oos.flush();
            oos.close();
        } catch (Exception e) {
            // TODO: handle exception
            e.printStackTrace();
        }
        
    }
    //doc file
    public void docFile(File f) {
        try {
            InputStream is = new FileInputStream(f);
            ObjectInputStream ois= new ObjectInputStream(is);
            
            arrayListSV sv = null;

            while(true){
                Object oj = ois.readObject();
                if(oj==null){
                    break;
                }
                if(oj!=null){
                    sv=(arrayListSV) oj;
                    this.danhSach.add(sv);
                }
                
            }

            ois.close();
        } catch (Exception e) {
            // TODO: handle exception
            e.printStackTrace();
        }
    }

    
}
