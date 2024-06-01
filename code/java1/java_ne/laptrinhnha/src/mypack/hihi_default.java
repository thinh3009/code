package mypack;
/*default:chung trong package thi dung dc neu o ngoai thi khong dung dc*/
public class hihi_default {
    String name;
	int age;
	float height;
	
    hihi (String name, int age, float height) {
        this.name=name +" hello ";
        this.age=age;
        this.height=height;
    }
    void eat(String foodname){
        System.out.println(name+" "+foodname);
    }
    int getAge(){
        return age;
    }
}