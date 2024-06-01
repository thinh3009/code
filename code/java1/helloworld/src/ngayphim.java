public class ngayphim {
    private int ngay;
    private int thang;
    private int nam;
    public ngayphim(int ngay,int thang, int nam){
        this.ngay=ngay;
        this.thang=thang;
        this.nam=nam;

    }
    public int getNgay(){
        return this.ngay;
    }
    public void setNgay(int ngay){
        if(ngay>=1 && ngay<=31)
            this.ngay=ngay;
    }

    public int getThang(){
        return this.thang;
    }
    public void setThang(int thang){
        if(thang>=1 && thang<=12)
            this.thang=thang;
    }

    public int getNam(){
        return this.nam;
    }
    public void setNam(int nam){
        this.nam=nam;
    }
}
