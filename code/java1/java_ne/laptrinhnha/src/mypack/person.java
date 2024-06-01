package mypack;
//protected co the dung trong hoac ngoai package deu dc(dung ke thua)
public class person {
    protected String name;
	protected int age;
	protected float height;
	
	public person(String name, int age, float height) {
		this.name = name;
		this.age = age;
		this.height = height;
	}
	
	protected void eat(String foodName) {
		System.out.println(name + " is eating "+ foodName);
	}
	
	protected int getAge() {
		return age;
	}

}
