package testDb;

import dataOb.sinhvienDataObject;
import model.sinhvien;

public class testSV {
	public static void main(String[] args) {
		//test them
//		sinhvien sv1 = new sinhvien(1,"bui duc thinh","cn20clcb","20h1120258","2002-09-30");
//		sinhvien sv2 = new sinhvien(2,"duy no sad","cn20clcb","20h1120222","2002-01-20");
//		sinhvien sv3 = new sinhvien(3,"trinh minh cuong","cn20clca","20h1120202","2002-01-30");
//		sinhvienDataObject.getInstance().them(sv1);
		//in nhieu sinh vien
//		for (int i=0; i< 100;i++) {
//			sinhvien sv = new sinhvien(1+i,"bui duc thinh"+i,"cn20clcb","20h1120258","2002-09-30");
//			sinhvienDataObject.getInstance().them(sv);
//		}
		//test cap nhat
		sinhvien sv = new sinhvien(3,"bui duc thinh3","cn20clcd","20h1120258","2002-09-30");
		sinhvienDataObject.getInstance().capNhat(sv);
//		//test xoa
//		for (int i=0; i< 100;i++) {
//			sinhvien sv = new sinhvien(1+i,"bui duc thinh"+i,"cn20clcb","20h1120258","2002-09-30");
//			sinhvienDataObject.getInstance().xoa(sv);
//		}
	}
}
