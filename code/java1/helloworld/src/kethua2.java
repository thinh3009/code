public class kethua2 extends kethua{

    private String tenlop;
    private String tentruong;
    //ke thua tu class (kethua)
    public kethua2(String hoten,int namsinh,String tenlop,String tentruong){
        super(hoten, namsinh);
        this.tenlop=tenlop;
        this.tentruong=tentruong;
    }
    public String gettenlop(){
        return this.tenlop;
    }
    public void settenlop(String tenlop){
        this.tenlop=tenlop;
    }
    
    public String gettentruong(){
        return this.tentruong;
    }
    public void settentruong(String tentruong){
        this.tentruong=tentruong;
    }

    public void lambt(){
        System.out.println("lam bai nha!!");
    }
}
