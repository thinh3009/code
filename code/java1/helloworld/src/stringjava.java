import java.util.Scanner;

public class stringjava {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=null;
        System.out.println("nhap gia tri: ");
        s= sc.nextLine();
        System.out.println("----");
        //length()
        System.out.println(s.length());
     
        int doDai=s.length();

        //charAt-->lay ki tu o vi tri
        for(int i=0; i<doDai;i++){
            System.out.println("vi tri "+i+"la: "+s.charAt(i));

        }

    }
}
