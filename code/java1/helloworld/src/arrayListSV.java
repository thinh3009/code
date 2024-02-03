import java.io.Serializable;

public class arrayListSV implements Comparable<arrayListSV>, Serializable  {
    private String masv;
    private String hoten;
    private int namsinh;
    private float diemtb;
    public arrayListSV(String masv, String hoten, int namsinh, float diemtb){
        this.masv=masv;
        this.hoten=hoten;
        this.namsinh=namsinh;
        this.diemtb=diemtb;

    }
    public String getmasv() {
        return this.masv;
    }
    public void setmasv(String masv){
        this.masv=masv;
    }
    public String gethoten() {
        return this.hoten;
    }
    public void sethoten(String hoten){
        this.hoten=hoten;
    }
    public int getnamsinh() {
        return this.namsinh;
    }
    public void setnamsinh(int namsinh){
        this.namsinh=namsinh;
    }
    public float getdiemtb() {
        return this.diemtb;
    }
    public void setmasv(float diemtb){
        this.diemtb=diemtb;
    }
    
    @Override
    public String toString() {
        // TODO Auto-generated method stub
        return "arrayListSV [masv="+masv+", ho ten: "+hoten+", nam sinh: "+namsinh+", diemtb: "+diemtb+"]"; 
    }
    @Override
    public int compareTo(arrayListSV o) {
        // TODO Auto-generated method stub
        return 0;
    }
}
