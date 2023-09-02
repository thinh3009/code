public class kethuaMain {
    public static void main(String[] args) {
        kethua kt=new kethua("dep trai", 20133, 30);
        //ham caiThay() khong can sysout, con get vs set phai sysout
        kt.caiThay();
        kt.setCmnd(4003);
        System.out.println("cmnd: "+kt.getCmnd());
        hocSinh hs= new hocSinh("xau trai", 2234, 23, "cn20b", "tran phu");
        hs.anVung();
        hs.tronHoc();
        
    } 
        
    
}
