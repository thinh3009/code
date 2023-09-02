public class HoaDon {
    //thuoc tinh
    private String tenCf;
    private double giaTien;
    private double khoiLuong;

    public HoaDon(String ten, double gia, double kl){
        this.tenCf =ten;
        this.giaTien=gia;
        this.khoiLuong=kl;
    }
    //phuong thuc
    public double tinhTongTien(){
        return this.giaTien * this.khoiLuong;
    }
    
    public boolean Ktra(double kl){//ktra khoi luong nen dien khoi luong
        // if (this.khoiLuong>kl){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        return this.khoiLuong>kl;
    }
    public boolean KtraTongTien(){
        if(this.tinhTongTien()>500000){
            return true;
        }
        else{
            return false;
        }
    }
    public double GiamGia(double x){
        if(tinhTongTien()>500000){
            return this.tinhTongTien()*(x/100);
        }
        else{
            System.out.println("xin loi k dc giam gia!!");
            return 0;
            
        }
        
    }
    public double KhachTra(double x){//phan tram giam gia nen can nhap
        return this.tinhTongTien()-this.GiamGia(10);
    }
    
}
