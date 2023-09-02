public class Maininterface {
    public static void main(String[] args) {
        System.out.println("test:\n");
        Casiofx500interface mfx = new Casiofx500interface();
        Vinagame500interface mv = new Vinagame500interface();
        System.out.println("5+3= "+mfx.cong(5, 3));

        System.err.println("4*3= "+mv.nhan(4, 3));

        System.out.println("4/0= "+mfx.chia(4, 4));

        double arr[] = new double[] {2,1,3,4,5,8,0};
        double arr2[] = new double[] {7,6,3,4,5,8,0};
        SapXepCheninterface chen= new SapXepCheninterface();
        SapXepChoninterface chon=new SapXepChoninterface();

        chen.sapxeptang(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+" ");
        }
        System.out.println();

        chon.sapxepgiam(arr2);
        for (int i = 0; i < arr2.length; i++) {
            System.out.print(arr2[i]+" ");

        }
        System.out.println();

    }
}
