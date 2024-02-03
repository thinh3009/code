public class Mainnapchong {
    public static void main(String[] args) {
        napchong n = new napchong();
        System.out.println(n.timMin(2, 3));
        System.out.println(n.timMin(4.5, 3.4));

        System.out.println(n.tinhTong(2, 4));
        double arr[]=new double[] {1,2,3,4,5,6};
        System.out.println(n.tinhTong(arr));
    }
}
