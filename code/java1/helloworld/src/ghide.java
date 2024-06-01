//lop cha con co moi quan he ke thua
//phuong thuc phai giong nhau
//phuong thuc lop con co tham so giong lop cha
public class ghide {
    protected String name;
    public ghide(String name){
        this.name=name;
    }
    public String getname(){
        return this.name;
    }
    public void setname(String name){
        this.name=name;
    }

    public void eat(){
        System.out.println("an an an");
    }
    public void makeSound(){
        System.out.println("..........");
    }

    public void sleep() {
        System.err.println("zzzzzzzzzzzz");
    }
}
