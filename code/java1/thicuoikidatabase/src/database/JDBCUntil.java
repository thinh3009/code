/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package database;
import com.mysql.jdbc.Driver;
import java.sql.SQLException;
import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.DatabaseMetaData;

/**
 *
 * @author ASUS TUF
 */
public class JDBCUntil {
    //ket noi db
    public static Connection getConnection(){
        Connection c = null;
        try {
            DriverManager.registerDriver(new com.mysql.jdbc.Driver());
            String url="jdbc:mySQL://localhost::3306/school";
            String username ="root";
            String password="thinhbeo103";
            //tao ket noi
            c= DriverManager.getConnection(url,username,password);
            
        } 
        catch (SQLException e) {
            //e.printStackTrace();
        }
        return c;
    }
    //ngat ket noi
    public static void closeConnection(Connection c){
        try {
            if(c!=null){
                c.close();
            }
        } catch (SQLException e) {
            //e.printStackTrace();
        }
    }
    public static void printInf(Connection c){
        
            try {
                if(c!=null){
                    DatabaseMetaData mtdt = c.getMetaData();
                    System.out.println(mtdt.getDatabaseProductName());
                    System.out.println(mtdt.getDatabaseProductVersion());
                }
            } catch (SQLException e) {
               //e.printStackTrace();
            }
        
    }
    
}
