public class Mainphim {
    public static void main(String[] args) {
        ngayphim n =new ngayphim(30, 1, 2019);
        ngayphim n2=new ngayphim(15, 8, 2018);
        hangsxphim h = new hangsxphim("marvel", "american");
        phim p =new phim("wakanda forever", 2019, h, 75000, n);

        phim p2=new phim("avenger infinity war", 2018, h, 90000, n2);
        System.out.println("kiem tra gia ve: "+p.ktragiave(p2));
        System.out.println("ten hang sx: "+p.layhangsx());
        System.out.println("gia ve giam: "+p.giamgia(10));
    }
}
