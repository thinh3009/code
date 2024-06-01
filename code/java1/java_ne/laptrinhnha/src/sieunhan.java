import mypack.dcm;
public class sieunhan {
    public static void main(String[] args) {
        dcm a = new dcm("thinh",21,1.7f);
        a.eat("com");
        int age=a.getAge();
        System.out.println("his age: "+age);
        //pham vi private k cho truy cap
        /*System.out.println(a.age);*/
        a.eat("rice");
    }
}
