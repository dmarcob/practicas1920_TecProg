package teoria;

public class claseII {
	
	public static void main ( String args[]) {
		U u = new U(32);
		System.out.println(u.get_age());
	}
}

class P {
	public int age;
	
	public P(int age) {
		this.age = age;
	}
}

class U {
	private P p;
	
	public U (int age) {
		p = new P(age);
	}
	
	public int get_age() {
		return p.age;
	}
}