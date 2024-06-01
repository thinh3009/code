package model;

public class sinhvien {
	private int stt;
	private String hoTen;
	private String lop;
	private String mssv;
	private String ngaysinh;
	
	
	public sinhvien() {
		super();
	}


	public sinhvien(int stt, String hoTen, String lop, String mssv, String ngaysinh) {
		super();
		this.stt = stt;
		this.hoTen = hoTen;
		this.lop = lop;
		this.mssv = mssv;
		this.ngaysinh = ngaysinh;
	}


	public int getStt() {
		return stt;
	}


	public void setStt(int stt) {
		this.stt = stt;
	}


	public String getHoTen() {
		return hoTen;
	}


	public void setHoTen(String hoTen) {
		this.hoTen = hoTen;
	}


	public String getLop() {
		return lop;
	}


	public void setLop(String lop) {
		this.lop = lop;
	}


	public String getMssv() {
		return mssv;
	}


	public void setMssv(String mssv) {
		this.mssv = mssv;
	}


	public String getNgaysinh() {
		return ngaysinh;
	}


	public void setNgaysinh(String ngaysinh) {
		this.ngaysinh = ngaysinh;
	}
	
	
}

