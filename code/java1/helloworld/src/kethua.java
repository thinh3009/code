public class kethua {
    private String hoten;
    private int namsinh;
    public kethua(String hoten, int namsinh){
        this.hoten=hoten;
        this.namsinh=namsinh;
    }
    public String gethoten(){
        return this.hoten;

    }
    public void sethoten(String hoten){
        this.hoten=hoten;
    }
    public int getnamsinh(){
        return this.namsinh;
    }
    public void setnamsinh(int namsinh){
        this.namsinh=namsinh;
    }

    public void an(){
        System.out.println("an com");
    }
    public void uong(){
        System.out.println("uong");
    }
}
