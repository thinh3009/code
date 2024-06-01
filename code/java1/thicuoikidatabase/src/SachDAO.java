
package dataaccObject;


import java.sql.*;
import database.JDBCUntil;
import java.util.ArrayList;
import model.Sach;

/**
 *
 * @author ASUS TUF
 */
public class SachDAO implements DAOinterface<Sach>{
    public static SachDAO getInstance(){
        return new SachDAO();
    }

    @Override
    public int insert(Sach t) {
        int ketQua=0;
        try {
            //tao ket noi
            Connection con = JDBCUntil.getConnection();
            //tao doi tuong
            Statement st = con.createStatement();

            //thuc thi cau lenh sql
            String sql = "insert into sach()"
                    + " VALUES ('" + t.getId() + "' , '" + t.getTensach() + "' , '" + t.getGiaban() + "')";
            
            int ketQua=st.executeUpdate(sql);
            System.out.println("ban da thuc thi"+sql);
            System.out.println("co: "+ketQua+"bi thay doi");
            
            //dong ket noi
            JDBCUntil.closeConnection(con);
            
            
            
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return ketQua;
    }

    @Override
    public int update(Sach t) {
        int ketQua = 0;
		try {
			// Bước 1: tạo kết nối đến CSDL
			Connection con = JDBCUntil.getConnection();
			
			// Bước 2: tạo ra đối tượng statement
			Statement st = con.createStatement();
			
			// Bước 3: thực thi câu lệnh SQL
			
			String sql = "UPDATE sach "+
						 " SET " +
						 " id='"+ t.getId()+"'"+
						 ", tensach="+ t.getTensach()+
						 ", giaban="+ t.getGiaban()+
						 " WHERE id='"+t.getId()+"\'";
			System.out.println(sql);
			ketQua = st.executeUpdate(sql);
			
			// Bước 4:
			System.out.println("Bạn đã thực thi: "+ sql);
			System.out.println("Có "+ ketQua+" dòng bị thay đổi!");
			
			// Bước 5:
			JDBCUntil.closeConnection(con);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return ketQua;
    }

    @Override
    public int delete(Sach t) {
        int ketQua = 0;
		try {
			// Bước 1: tạo kết nối đến CSDL
			Connection con = JDBCUntil.getConnection();
			
			// Bước 2: tạo ra đối tượng statement
			Statement st = con.createStatement();
			
			// Bước 3: thực thi câu lệnh SQL
			
			String sql = "DELETE from sach "+
						 " WHERE id='"+t.getId()+"'";
			System.out.println(sql);
			ketQua = st.executeUpdate(sql);
			
			// Bước 4:
			System.out.println("Bạn đã thực thi: "+ sql);
			System.out.println("Có "+ ketQua+" dòng bị thay đổi!");
			
			// Bước 5:
			JDBCUntil.closeConnection(con);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return ketQua;
    }

    @Override
    public ArrayList<Sach> selectAll() {
        return null;
    }

    @Override
    public Sach selectById(Sach t) {
        return null;
    }

    @Override
    public ArrayList<Sach> selectByCondition(String condition) {
        return null;
    }
    
}
