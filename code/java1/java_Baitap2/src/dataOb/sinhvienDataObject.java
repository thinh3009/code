package dataOb;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import JDBC.database;
import model.sinhvien;

public class sinhvienDataObject implements dataObject<sinhvien> {
	
	public static sinhvienDataObject getInstance () {
		return new sinhvienDataObject();
	}
	@Override
	public int them(sinhvien t) {
		int ketQua=0;
		// TODO Auto-generated method stub
		try {
			//tao ket noi
			Connection con = database.getConnection();
			//tao doi tuong statement
			Statement st = con.createStatement();
			//thuc thi cau lenh
			String sql = "insert into sinhvien (stt, ten, lop ,mssv, ngaysinh)"
					+ "values ('"+t.getStt()+"', '"+t.getHoTen()+"', '"+t.getLop()+"', '"+t.getMssv()+"', '"+t.getNgaysinh()+"')";
			
			ketQua = st.executeUpdate(sql);
			//xu ly ket qua
			System.out.println("ban da thuc thi: \n"+sql);
			//ngat ket noi
			database.closeConnection(con);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ketQua;
	}

	@Override
	public int capNhat(sinhvien t) {
		// TODO Auto-generated method stub
		int ketQua=0;
		// TODO Auto-generated method stub
		try {
			//tao ket noi
			Connection con = database.getConnection();
			//tao doi tuong statement
			Statement st = con.createStatement();
			//thuc thi cau lenh
			String sql = "update sinhvien "
					+ "set "+
					"stt="+t.getStt()+
					",ten='"+t.getHoTen()+
					",lop="+t.getLop()+
					",mssv="+t.getMssv()+
					",ngaysinh="+t.getNgaysinh()+
					" where stt="+t.getStt()+"\'";
					
					System.out.println(sql);
			ketQua = st.executeUpdate(sql);
			//xu ly ket qua
			System.out.println("ban da thuc thi: \n"+sql);
			//ngat ket noi
			database.closeConnection(con);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ketQua;
	}

	@Override
	public int xoa(sinhvien t) {
		// TODO Auto-generated method stub
		int ketQua=0;
		// TODO Auto-generated method stub
		try {
			//tao ket noi
			Connection con = database.getConnection();
			//tao doi tuong statement
			Statement st = con.createStatement();
			//thuc thi cau lenh
			String sql = "delete sinhvien"
					+ "where stt= "+t.getStt();
					
					
					System.out.println(sql);
			ketQua = st.executeUpdate(sql);
			//xu ly ket qua
			System.out.println("ban da thuc thi: \n"+sql);
			//ngat ket noi
			database.closeConnection(con);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ketQua;
		return 0;
	}

	@Override
	public ArrayList<sinhvien> selectAll() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public sinhvien selectByID(sinhvien t) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public ArrayList<sinhvien> selectByCondition(String condition) {
		// TODO Auto-generated method stub
		return null;
	}
	
}
