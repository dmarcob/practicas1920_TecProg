//*****************************************************************
// File:    MainStaticStack.java
// Author:  Diego Marco, 755232
// Date:    08-03-2020
// Coms:    Módulo principal de uso de uso de pila estática
//*****************************************************************
import java.util.Iterator;

public class MainStaticStack
{
	public static void main(String[] args)
	{
		StaticStack<Integer> ss = new StaticStack<Integer>();

		ss.push(42);
		ss.push(15);
		ss.pop();
		for (int i = 0; i < 100; i+=5)
			ss.push(i);

		Iterator<Integer> iter = ss.iterator();
		while(iter.hasNext())
			System.out.print(iter.next()+" ");
		System.out.println();

		// Opcionalmente, con esta nomenclatura, puede hacerse asi
		for (Integer i : ss)
			System.out.print(i+" ");
		System.out.println();
	}
}
