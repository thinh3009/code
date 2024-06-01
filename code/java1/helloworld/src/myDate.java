public class myDate {
    private int day;
    private int month;
    private int year;
    //constructor
    public myDate(int day, int month, int year){
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
    // public void printDay(){
    //     System.out.println("day: "+this.day);
        
        
    // }
    // public void printMonth(){
    //     System.out.println("month: "+this.month);
    // }
    // public void printYear(){
    //     System.out.println("year: "+this.year);
    // }
    // public void printDate(){
    //     System.out.println("date: "+this.day+"-"+this.month+"-"+this.year);
    // }
    //get lay gu lieu
    public int GetDay(){
        return this.day;
    }
    public int getMonth(){
        return this.month;
    }
    //set sua du lieu
    public void setDay(int d){
        if(d>=1 && d<=31){
            this.day =d;
        }
        
    }
    public void setMonth(int m){
        if(m>=1 && m<=12){
            this.month=m;
        }
    }

}
