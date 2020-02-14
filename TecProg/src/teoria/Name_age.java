package teoria;
import java.util.Scanner;

public class Name_age 
{
	public static void main (String[] args) 
	{
		String name = new String();
		int age;
		
		Scanner scanner = new Scanner(System.in); 
		
		System.out.println("What's your name ? ");
		System.out.flush(); //Fuerza volcado del buffer-line intermedio
		name = scanner.next();
		System.out.println("What's your age ?");
		System.out.flush();
		age = scanner.nextInt();
		System.out.println(
				"Hello, " + name + "\n" +
				"You're " + age + " years old \n"
				);
	}
}
