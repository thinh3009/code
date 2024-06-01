
package model;

import java.util.Date;
import java.util.Objects;

public class ThiSinh {
    public ThiSinh(){
        
    }
    private int maThiSinh;
    private String tenThiSinh;
    private Tinh queQuan;
    private Date ngaysinh;
    private boolean gioiTinh;
    private boolean diemMon1, diemMon2,diemMon3;

    public ThiSinh(int maThiSinh, String tenThiSinh, Tinh queQuan, Date ngaysinh, boolean gioiTinh, boolean diemMon1, boolean diemMon2, boolean diemMon3) {
        this.maThiSinh = maThiSinh;
        this.tenThiSinh = tenThiSinh;
        this.queQuan = queQuan;
        this.ngaysinh = ngaysinh;
        this.gioiTinh = gioiTinh;
        this.diemMon1 = diemMon1;
        this.diemMon2 = diemMon2;
        this.diemMon3 = diemMon3;
    }

    public int getMaThiSinh() {
        return maThiSinh;
    }

    public void setMaThiSinh(int maThiSinh) {
        this.maThiSinh = maThiSinh;
    }

    public String getTenThiSinh() {
        return tenThiSinh;
    }

    public void setTenThiSinh(String tenThiSinh) {
        this.tenThiSinh = tenThiSinh;
    }

    public Tinh getQueQuan() {
        return queQuan;
    }

    public void setQueQuan(Tinh queQuan) {
        this.queQuan = queQuan;
    }

    public Date getNgaysinh() {
        return ngaysinh;
    }

    public void setNgaysinh(Date ngaysinh) {
        this.ngaysinh = ngaysinh;
    }

    public boolean isGioiTinh() {
        return gioiTinh;
    }

    public void setGioiTinh(boolean gioiTinh) {
        this.gioiTinh = gioiTinh;
    }

    public boolean isDiemMon1() {
        return diemMon1;
    }

    public void setDiemMon1(boolean diemMon1) {
        this.diemMon1 = diemMon1;
    }

    public boolean isDiemMon2() {
        return diemMon2;
    }

    public void setDiemMon2(boolean diemMon2) {
        this.diemMon2 = diemMon2;
    }

    public boolean isDiemMon3() {
        return diemMon3;
    }

    public void setDiemMon3(boolean diemMon3) {
        this.diemMon3 = diemMon3;
    }

   @Override
	public String toString() {
		return "ThiSinh [maThiSinh=" + maThiSinh + ", tenThiSinh=" + tenThiSinh + ", queQuan=" + queQuan + ", ngaySinh="
				+ ngaysinh + ", gioiTinh=" + gioiTinh + ", diemMon1=" + diemMon1 + ", diemMon2=" + diemMon2
				+ ", diemMon3=" + diemMon3 + "]";
	}
    @Override
	public int hashCode() {
		return Objects.hash(diemMon1, diemMon2, diemMon3, gioiTinh, maThiSinh, ngaysinh, queQuan, tenThiSinh);
	}

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final ThiSinh other = (ThiSinh) obj;
        if (this.maThiSinh != other.maThiSinh) {
            return false;
        }
        if (this.gioiTinh != other.gioiTinh) {
            return false;
        }
        if (this.diemMon1 != other.diemMon1) {
            return false;
        }
        if (this.diemMon2 != other.diemMon2) {
            return false;
        }
        if (this.diemMon3 != other.diemMon3) {
            return false;
        }
        if (!Objects.equals(this.tenThiSinh, other.tenThiSinh)) {
            return false;
        }
        if (!Objects.equals(this.queQuan, other.queQuan)) {
            return false;
        }
        return Objects.equals(this.ngaysinh, other.ngaysinh);
    }
    
    
}
