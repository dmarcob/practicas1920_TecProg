package teoria;

public class claseII {
	
	public static void main ( String args[]) {
		//U u = new U(32);
		//System.out.println(u.get_age());
	}
}

class T {
	public int age;
	
	public T(int age) {
		this.age = age;
	}
}

class U {
	private T t;
	
	public U (int age) {
		t = new T(age);
	}
	
	public int get_age() {
		return t.age;
	}
}