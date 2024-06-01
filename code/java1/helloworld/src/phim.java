import java.util.Scanner;
import java.util.function.DoubleBinaryOperator;

public class phim{
    private String tenphim;
    private int namsx;
    private hangsxphim hangsx;
    private double giave;
    private ngayphim Ngaychieu;
    public phim(String tenphim, int namsx,hangsxphim hangsx,double giave, ngayphim Ngaychieu ){
        this.tenphim=tenphim;
        this.namsx=namsx;
        this.hangsx=hangsx;
        this.giave=giave;
        this.Ngaychieu=Ngaychieu;
    }
    //ten phim
    public String gettenphim(){
        return this.tenphim;
    }
    public void settenphim(String tenphim){
        this.tenphim=tenphim;
    }
    //namsx
    public int getnamsx(){
        return this.namsx;
    }
    public void settenphim(int namsx){
        this.namsx=namsx;
    }
    //hangsx
    public hangsxphim gethangsx(){
        return hangsx;
    }
    public void settenphim(hangsxphim hangsx){
        this.hangsx=hangsx;
    }
    //gia ve
    public double getgiave(){
        return this.giave;
    }
    public void setgiave(double giave){
        this.giave=giave;
    }
    //ngay chieu
    public ngayphim getngaychieu(){
        return Ngaychieu;
    }
    public void setngaychieu(ngayphim Ngaychieu){
        this.Ngaychieu=Ngaychieu;
    }

    public boolean ktragiave(phim phimkhac){
        //neu gia phim hien tai nho hon gia phim khac
        return this.giave <phimkhac.giave;
    }

    public String layhangsx() {
        return this.hangsx.getTenhang();
    }

    public double giamgia(double x){
        return (this.giave*x)/100;
    }
    
}

    
