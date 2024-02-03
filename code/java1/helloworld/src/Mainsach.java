import java.util.Scanner;

public class Mainsach {
    public static void main(String[] args) {
        sach s= new sach("hoc di dung choi nua", 100000, 2002, "bui duc thinh");
        sach s2= new sach("an com dung bua", 1000000, 2004, "bui duc thi");
        System.out.println("\nsach: \n"+s);
        System.out.println("ktra sach trung hay khong!!\n");
        System.out.println(s.ktraSach());
        System.out.println("giam gia!!");
        System.out.println(s2.giamgia());
        
    
        
        
    }
}
