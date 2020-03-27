//*****************************************************************
// File:    Stack.java
// Author:  Diego Marco, 755232
// Date:    08-03-2020
// Coms:    Interfaz pila genérica
//*****************************************************************
import java.lang.Iterable;


//Stack<T> extiende  Iterable<T> por lo que las clases que hereden
//esta interfaz no tendrán que heredar Iterable<T>.
//Además tendrán que implementar los métodos push() y pop()
interface Stack<T> extends Iterable<T>
{
  boolean push(T t);
  boolean pop();
}
