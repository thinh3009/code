
public class tuongTranh implements Runnable {
    private int soGhetrong=2;

    @Override
    public void run() {
        KhachThread khach =(KhachThread) Thread.currentThread();
        boolean DatTruoc=this.BanVe(khach.LaySoGheDat(),khach.getName());
        if(DatTruoc==true){
            System.out.println("chuc mung"+Thread.currentThread().getName()+","+khach.LaySoGheDat()+"ghe da dc dat.");
        }
        else{
            System.out.println("xin loi"+Thread.currentThread().getName()+"khong du so ghe yeu cau ("+khach.LaySoGheDat()+")");
        }

        
        
    }

	private synchronized boolean BanVe(int soGheDat, String hoTen) {
        
        System.out.println("chao mung"+hoTen+"so ghe trong la: "+ this.LaySoGheTrong());
        if(soGheDat>this.LaySoGheTrong()){
            return false;
        }
        else{
            soGhetrong = soGhetrong-soGheDat;
            return true;
        }
        
		
	}

    private int LaySoGheTrong() {
        return soGhetrong;
    }
    
}
