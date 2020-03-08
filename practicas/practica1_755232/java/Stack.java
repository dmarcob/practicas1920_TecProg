//*****************************************************************
// File:    Stack.java
// Author:  Diego Marco, 755232
// Date:    08-03-2020
// Coms:    Interfaz pila genérica
//*****************************************************************
import java.lang.Iterable;

interface Stack<T> extends Iterable<T>
{
  boolean push(T t);
  boolean pop();
}
