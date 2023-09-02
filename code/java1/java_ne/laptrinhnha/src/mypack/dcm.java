package mypack;
//package java
public class dcm {
    public String name;
    //private:truy cap trong pham vy cua class dcm
    private int age;
    public float height;
    
    public dcm (String name, int age, float height) {
        this.name=name +" hello ";
        //private age truy cap dc
        this.age=age;
        this.height=height;
    }
    public void eat(String foodname){
        System.out.println(name +"is eating"+foodname);
    }
    public int getAge(){
        //private age truy cap dc
        return age;
    }
}
