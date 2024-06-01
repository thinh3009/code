import java.io.Serializable;
//dung implement serialiazable de luu thong tin object vao file
public class student implements Serializable {
    String ID;
    String name;
    String classID;
    public student(String ID, String name, String classID){
        this.ID=ID;
        this.name=name;
        this.classID=classID;

    }
    public String getID(){
        return ID;
    }
    public void setID(String ID){
        this.ID=ID;
    }
    public String getName(){
        return name;
    }
    public void setName(String name){
        this.name=name;
    }
    public String getClassid(){
        return classID;
    }
    public void setClassid(String classID){
        this.classID=classID;
    }
    @Override
    public String toString() {
        return "student{"+" ID= "+ID+", name= "+name+", classID=  "+classID+"}";

    }
    public void display(){
        System.out.println(toString());
    }
}
