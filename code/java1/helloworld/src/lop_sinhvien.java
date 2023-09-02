public class lop_sinhvien {
    private String tenlop;
    private String tenkhoa;

    public lop_sinhvien(String tenlop, String tenkhoa){
        this.tenlop=tenlop;
        this.tenkhoa=tenkhoa;
    }
    public String gettenlop(){
        return this.tenlop;
    }
    public void settenlop(String tenlop){
        this.tenlop=tenlop;
    }

    public String gettenkhoa(){
        return this.tenkhoa;
    }
    public void settenkhoa(String tenkhoa){
        this.tenkhoa=tenkhoa;
    }
}
