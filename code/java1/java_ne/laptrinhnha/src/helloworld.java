import mypack.person;
public class helloworld extends person {
    protected helloworld(String name, int age, float height) {
		//phương thức khởi tạo HelloWorld sẽ gọi phương thức Person
		super(name, age, height);
	}

	public static void main(String[] args) {
		helloworld a = new helloworld("Chau", 21, 1.7f);
		a.eat("Rice");
	}
}
