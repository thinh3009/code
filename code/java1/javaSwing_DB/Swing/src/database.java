import java.sql.Connection;
import java.sql.Driver;
import java.sql.DriverManager;
import java.sql.SQLException;

import com.mysql.cj.jdbc.Driver;
public class database {
    public static Connection getConnection(){
        Connection c =null;

        try {
            //dang ki mysql driver
            DriverManager.registerDriver(new com.mysql.jdbc.Driver());
            //thong tin data
            String url = "jdbc:mySQL://localhost:3306/root";
            String username= "root";
            String pass= "thinhbeo103";
            //tao ket noi
            c= DriverManager.getConnection(url, username, pass);
        } catch (SQLException e) {
            // TODO: handle exception
            e.printStackTrace();
        }
        
        return c;
    }   
    public static void closeConnection(Connection c){

    }
}
