//ke thua tu student:extends
public class kethua  {
    private String nhanSac;
    private int cmnd;
    private int can_nang;
    public kethua(String nhanSac,int cmnd,int can_nang){
        super();
        this.nhanSac=nhanSac;
        this.cmnd=cmnd;
        this.can_nang=can_nang;

    }
    public String getNhanSac() {
        return nhanSac;
    }
    public void setNhanSac(String nhanSac){
        this.nhanSac=nhanSac;
    }
    public int getCmnd() {
        return cmnd;
    }
    public void setCmnd(int cmnd){
        this.cmnd=cmnd;
    }
    public int getCannang() {
        return can_nang;
    }
    public void setCannang(int can_nang){
        this.can_nang=can_nang;
    }
    public void caiThay(){
        System.out.println("cai thay cai co");
    }
    
}

