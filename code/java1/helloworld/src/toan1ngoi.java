import java.util.Scanner;

public class toan1ngoi {
    public static void main(String[] args) {
        // int a=5;
        // System.out.println("- => gia tri: "+(-a));
        // System.out.println("+ => gia tri: "+(+a));
        // System.out.println("++a= "+(++a));
        // System.out.println("a++= "+(a++));

        // System.out.println("--a= "+(--a));
        // System.out.println("a--= "+(a--));
        int n;
        Scanner sc =new Scanner(System.in);
        System.out.println("nhap so nguyen: ");
        n =sc.nextInt();
        //ktra chan le
        if(n%2==0){
            System.out.println("n la so chan!!");

        }
        else{
            System.out.println("n la so le!!");
        }
    }
}
