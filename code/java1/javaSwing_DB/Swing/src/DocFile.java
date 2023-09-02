import java.io.BufferedReader;
import java.io.File;
import java.nio.Buffer;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;
//doc tu file text len
public class DocFile {
    public static void main(String[] args) {
        /*cach 1 */
        File f = new File("C:/Users/ASUS TUF/Desktop/cpp_laptrinh/java1/javaSwing_DB/Swing/src/file.txt");
        
        try {
            
            BufferedReader br= Files.newBufferedReader(f.toPath(),StandardCharsets.UTF_8);
            //tao bien line de doc du lieu trong file text
            String line=null;
            //vong lap while true doc tu dau den cuoi filetext
            while(true){
                line =br.readLine();
                if(line==null){
                    break;
                }
                else{
                    System.out.println(line);;
                }
            }
        } catch (Exception e) {
            // TODO: handle exception
            //in ra loi
            e.printStackTrace();
        }
        /*cach 2 */
        // File f2=new File("C:/Users/ASUS TUF/Desktop/cpp_laptrinh/java1/javaSwing_DB/Swing/src/file.txt");
        // try {
        //     List<String> allText =Files.readAllLines(f2.toPath(),StandardCharsets.UTF_8);
        //     for (String line:allText){
        //         System.out.println(line);
        //     }
        // } catch (Exception e) {
        //     // TODO: handle exception
        // }
    }
}
