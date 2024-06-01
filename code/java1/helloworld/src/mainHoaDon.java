public class mainHoaDon {
    public static void main(String args[]) {
        HoaDon hd = new HoaDon("trung nguyen", 1000000, 5);
        HoaDon hd2 = new HoaDon("cf sua da", 40000, 3);
        System.out.println("tong tien hd1: "+hd.tinhTongTien());
        System.out.println("ktra khoi luong:"+hd.Ktra(2));
        System.out.println("ktra tong tien > 500000: "+ hd.KtraTongTien());
        System.out.println("duoc giam gia: "+hd.GiamGia(10));
        System.out.println("tong tien hd2: "+hd2.tinhTongTien());
        System.out.println("duoc giam gia: "+hd2.GiamGia(10));
        System.out.println("so tien hd1 tra: "+hd.KhachTra(10));
        System.out.println("so tien hd2 tra: "+hd2.KhachTra(10));
    }
}
