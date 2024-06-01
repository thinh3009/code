

public class KhachThread extends Thread{
    private int soGheDat;
    public KhachThread(int gh, Runnable daiLy,String hoTen){
        super(daiLy,hoTen);
        this.soGheDat =gh;

    }
    public int LaySoGheDat(){
        return soGheDat;

    }
    public static void Main(String args[]) {

        tuongTranh bus = new tuongTranh();
        KhachThread nam = new KhachThread(2, bus, "Nam");
        KhachThread binh = new KhachThread(2, bus, "Binh");
        nam.start();
        binh.start();
    }
}
