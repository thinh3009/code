public class staticMem {
    //static la thanh phan tinh (dung chung) co the goi truc tiep trong class
    //dinh nghia static
    public static int id=1000;//dinh nghia static mac dinh la 1k
    public static String mess="hello";
    private int memID;
    public staticMem(){
        //tao ham moi lan nhap tang len 1
        memID=id++;
        //goi truc tiep class
        staticMem.showID();
        
    }
    public int getmemID(){
        //tra ve 1000
        return memID;
    }
    public void setMid(int memID){
        this.memID=memID;
        
    }
    public static void showID(){
        System.out.println("static ID="+id);
    }
    public static void main(String[] args) {
        
        staticMem s1=new staticMem();
        staticMem s2=new staticMem();
        //s1.showID();
        //goi bth
        // System.out.println("s1 id="+s1.getmemID());
        // System.out.println("s2 id="+s2.getmemID());
    }

}
