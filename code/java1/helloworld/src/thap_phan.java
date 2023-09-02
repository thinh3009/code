import java.util.Scanner;

public class thap_phan {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("nhap so nguyen: ");
        n=sc.nextInt();
        String nhiPhan="";
        while (n>0) {
            nhiPhan = (n%2)+nhiPhan;
            n=n/2;
        }
        System.out.println("he nhi phan= "+nhiPhan);
    }
}
