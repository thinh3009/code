import java.util.Scanner;

public class sinhvien {
    private int maso;
    private String ten;
    private double diemtb;
    private ngaysinhvien ngaysinh;
    private lop_sinhvien lop;

    public sinhvien(int maso, String ten,double diemtb,ngaysinhvien ngaysinh,lop_sinhvien lop){
        this.maso=maso;
        this.ten=ten;
        this.diemtb=diemtb;
        this.ngaysinh=ngaysinh;
        this.lop=lop;
    }
    public int getmaso(){
        return this.maso;
    }
    public void setmaso(int maso){
        this.maso=maso;
    }
    public String getten(){
        return this.ten;
    }
    public void setten(String ten){
        this.ten=ten;
    }
    public double getdiemtb(){
        return this.diemtb;
    }
    public void setdiemtb(Double diemtb){
        this.diemtb=diemtb;
    }

    public ngaysinhvien getngaysinh(ngaysinhvien ngaysinh){
        return this.ngaysinh;
    }
    public void setngaysinh(ngaysinhvien ngaysinh){
        this.ngaysinh=ngaysinh;
    }

    public lop_sinhvien getlop(){
        return this.lop;
    }
    public void setlop(lop_sinhvien lop){
        this.lop=lop;
    }

    public double ktraDTB(Double x){
        // Scanner sc = new Scanner(System.in);
        // System.out.println("nhap diem trung binh: ");
        if (this.getdiemtb()>=5.0){
            System.out.println("ban da dau!!");
        }
        else{
            System.out.println("ban da rot!!");
        }
        return this.getdiemtb();
    }
    //lay ngay sinh trung
    public int ktrangaysinh(int ngaykhac){
        if(ngaykhac==this.ngaysinh.getngay()){
            System.out.println("co sinh vien trung ngay sinh!!");
        }
        else{
            System.out.println("khong trung ngay sinh!!");
        }
        return this.ngaysinh.getngay();
    }
   
}
