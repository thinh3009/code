/*public class App {
    public static void main(String[] args){
        //bien
        int a=1;
        int tuoi = 16;
        int chieu_cao=15;
        int can_nang=50;
        String ho_ten ="thinh";
        System.out.println(ho_ten);
        System.out.println(tuoi);
        System.out.println(chieu_cao);
        //toan tu
        System.out.print(a++);//  a = 2 , in ra 1
        System.out.print(" a = ");
        System.out.println(a);
        System.out.print(++a); // a = 3, in ra 3
        System.out.print(" a = ");
        System.out.println(a);
        System.out.print(a+++1);// a = 4, in ra 4
        System.out.print(" a = ");
        System.out.println(a);
        System.out.print(++a+1); // a = 5, in ra 6
        System.out.print(" a = ");
        System.out.println(a); 
        //hang so
        final double hang_so=3.1459;
        int r=3;
        System.out.print("dap an la: ");
        System.out.println(2*r*hang_so);

        String s="hello";
        if(s=="hello")
            System.out.println("anh xin loi");
        
        else
            System.out.println("dcm");
        
    }
}*/
//vong lap while 
/*public class App{
    public static void main(String[] args){
        int i=0;
        while(i<10){
            System.out.print(i);
            i+=1;
        }
    }
}*/
//for
/*public class App{
    public static void main(String[] args){
        for(int i=0;i<10;i+=2){
            System.out.println(i);
        }
    }
}*/
public class App{
    public static void main(String[] args){
        //khai bao mang
        int [] a;
        //khoi tao
        a=new int[3];
        a[0]=5;
        a[1]=3;
        a[2]=1;
        System.out.println(a);
        //a.length de cho bt kich cow mang
        for(int i=0;i<a.length;i++){
            //in mang co the dua thu tu vao de xuat vi tri cua mang
            System.out.println(a[i]);
        }
        //in mang ki tu
        char[] b={'t','h','i','n','h'};
        System.out.println(b);

        //mang 2 chieu
        //khai bao
        int c[][] = {{1,2,3},{4,5,6},{8,9,10}};
        for(int i =0;i<3;i++){
            for(int j=0;j<3;j++){
                System.out.print(c[i][j]+" ");
            }
            System.out.println();
        }

        //foreach:dung nhu dslk don
        int array[] ={1,2,3,4};
        for (int d:array){
            System.out.println(d);
        }

        //break
        for (int i=0;i<array.length;i++){
            if (array[i]==4){
                System.out.println("cu phap: "+i);
                break;
            }
        }
        //continue
        int [] mang={1,2,3,4};
        int s=0;
        for (int i:mang){
            if(i==3){
                continue;
            }
            s+=i;
        }
        System.out.println("gia tri: "+s);
        //switch case
        String gender="boy";
        switch(gender){
            case "boy":
                System.out.println("you are boy");
                break;
            case "girl":
                System.out.println("you are girl");
                break;
            default:
                System.out.println("be de");

        }

    }
}

