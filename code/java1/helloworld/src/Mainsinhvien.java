public class Mainsinhvien {
    public static void main(String[] args) {
        ngaysinhvien n=new ngaysinhvien(30, 9, 2002);
        ngaysinhvien n2=new ngaysinhvien(20, 8, 2001);
        lop_sinhvien l=new lop_sinhvien("cn20clcb", "CNTT");
        
        sinhvien s= new sinhvien(123, "bui duc thinh", 5.0, n, l);
        sinhvien s1=new sinhvien(321, "nguyen van a", 4.3, n2, l);

        System.out.println("khoa dang hoc: "+l.gettenkhoa());
        System.out.println("diem trung binh cua ban: \n"+s1.ktraDTB(null));
        System.out.println("ngay sinh:\n"+s1.ktrangaysinh(20));
    }
    

}
