import java.util.Scanner;

public class try_catch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=0;
        try {
            System.out.println("nhap vao so nguyen n: ");
            n=sc.nextInt();
        } catch (Exception e) {
            System.out.println("nhap du lieu khong dung");
        }
        System.out.println("gia tri: "+n);
        System.out.println("ket thuc");

    }
}
