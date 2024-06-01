
package model;
import java.sql.Date;
/**
 *
 * @author ASUS TUF
 */
public class KhachHang {
    private int id;
    private String hoten;
    private Date ngaysinh;
    
    public KhachHang(){
        super();
    }

    public KhachHang(int id, String hoten, Date ngaysinh) {
        this.id = id;
        this.hoten = hoten;
        this.ngaysinh = ngaysinh;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getHoten() {
        return hoten;
    }

    public void setHoten(String hoten) {
        this.hoten = hoten;
    }

    public Date getNgaysinh() {
        return ngaysinh;
    }

    public void setNgaysinh(Date ngaysinh) {
        this.ngaysinh = ngaysinh;
    }
    
}
