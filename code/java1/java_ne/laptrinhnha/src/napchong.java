public class napchong {
    public static int add(int a,int b) {
        return a+b;
    }
    public static int add(int a,short b) {
        return a+b;
    }
    public static float add(float a,float b) {
        return a+b;
    }
    public static double add(double a,double b) {
        return a+b;
    }
    public static void main(String[] args) {
        int sumInt=add(100,200);
        double sumdouble=add(20, 15);
        float sumfloat=add(2.5f,3.4f);
        System.out.println("sum int: "+sumInt);
        System.out.println("sum double: "+sumdouble);
        System.out.println("sum float: "+sumfloat);
        Math.abs(100);
        System.out.println("abs: "+Math.sqrt(100));
    }
}
