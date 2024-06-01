import java.util.Scanner;

public class sach {
    private String tensach;
    private int giaban;
    private int namsx;
    private String tacgia;

    public sach(String tensach, int giaban, int namsx, String tacgia) {
        this.tensach= tensach;
        this.giaban=giaban;
        this.namsx=namsx;
        this.tacgia=tacgia;
    }
    public String Gettensach() {
        return this.tensach;
    }
    public void Settensach(String s) {
        this.tensach=s;
    }
    public int Getgiaban() {
        return this.giaban;
    }
    public void Setgiaban(int g) {
        this.giaban=g;
    }
    public int Getnamsx(){
        return this.namsx;
    }
    public void Setnamsx(int n){
        this.namsx=n;
    }
    public String Gettacgia(){
        return this.tacgia;
    }
    public void Settacgia(String t){
        this.tacgia=t;
    }
    @Override
    public String toString() {
        return "ten sach: "+this.tensach+"\n"+"gia ban: "+this.giaban+"\n"+"nam san xuat: "+this.namsx+"\n"+"tac gia: "+this.tacgia;
    }

    public int ktraSach(){
        int kt;
        Scanner sc = new Scanner(System.in);
        System.out.println("nhap nam san xuat: ");
        kt =sc.nextInt();
        if(kt==this.Getnamsx()){
            System.out.println("sach da trung nam san xuat");
        }
        else{
            System.out.println("sach khac nam san xuat!!");
        }
        return 0;
    }
    public double giamgia(){
        Scanner sc=new Scanner(System.in);
        int gia,giamgia;
        gia=sc.nextInt();
        giamgia=(this.Getgiaban()*gia)/100;
        if(Getgiaban()>500000){
            
            System.out.println("ban duoc giam gia");
            System.out.println("cu the la: "+giamgia);
        }
        else{
            System.out.println("xin loi ban k dc giam!!");
        }
        return 0;
    }
}
