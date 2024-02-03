
package quanligiangvien;
import java.sql.*;

public class Conn {
    
    Connection c;
    Statement s;
    
    public Conn(){
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
            c=DriverManager.getConnection("jdbc:mysql:///school", "root","thinhbeo103");
            s=c.createStatement();
        } catch(Exception e){
            e.printStackTrace();
        }
    }
}
