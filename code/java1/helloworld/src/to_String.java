public class to_String {
    private int day;
    private int month;
    private int year;
    //constructor
    public to_String(int day, int month, int year){
        if (day>=1 && day<=31){
            this.day =day;
        }
        else{
            this.day=1;
        }
        if(day>=1 && month <=12){
            this.month =month;
        }
        else{
            this.month=1;
        }
        if(year >=0){
            this.year=year;
        }
        else{
            this.year=1;
        }
    }
    public int xuatDay() {
        return day;
    }
    public void nhapDay(int d) {
        if(d>=1 && d<=31){
            this.day=d;
        }
    }

    public int xuatMonth() {
        return month;
    }
    public void nhapMonth(int m) {
        if(m>=1 && m<=12){
            this.month=m;
        }
    }

    public int xuatYear() {
        return year;
    }
    public void nhapYear(int y) {
        if(y>=1){
            this.year=y;
        }
    }
    //in chuoi ra terminal
    @Override
    public String toString() {
        // TODO Auto-generated method stub
        return this.day+"/"+this.month+"/"+this.year;
    }
}
