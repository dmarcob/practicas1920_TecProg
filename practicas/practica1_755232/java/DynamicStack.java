//*****************************************************************
// File:    DynamicStack.java
// Author:  Diego Marco Beisty 755232
// Date:    08-03-2020
// Coms:    Fichero implementación pila dinámica
//*****************************************************************
import java.lang.Iterable;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.lang.UnsupportedOperationException;


public class DynamicStack<T> implements Stack<T>
{

  private class Node
  {
    private T dato;
    private Node next;

    private Node(T dato_, Node next_)
    {
      this.dato = dato_;
      this.next = next_;
    }
  }

  private Node head;

  @SuppressWarnings("unchecked")
  public DynamicStack()
  {
    this.head = null;
  }

  //Cabecera de push y pop idénticas a la clase static_stack para que puedan
  //implementar la interfaz Stack.(Para polimorfismo de inclusión en Main.java)
  public boolean push(T t)
  {
    this.head = new Node(t, head);
    return true;
  }

  public boolean pop()
  {
    boolean esPosible = this.head != null;
    if ( esPosible )
    {
      this.head = this.head.next;
      return true;
    }
    return false;
  }

  private class StackIterator implements Iterator<T>
  {
    DynamicStack<T> dtk;
    DynamicStack<T>.Node iter;

    private StackIterator(DynamicStack<T> dtk_)
    {
      this.dtk = dtk_;
      this.iter = dtk.head;
    }

    public boolean hasNext()
    {
      return this.iter != null;
    }

    public T next() throws NoSuchElementException
    {
      if(!hasNext())
      {
        throw new NoSuchElementException();
      }
      else
      {
      T dato = this.iter.dato;
      this.iter = this.iter.next;
      return dato;
      }
    }
  }
  public void remove() throws UnsupportedOperationException
  {
    throw new UnsupportedOperationException();
  }

  public Iterator<T> iterator()
  {
    return new StackIterator(this);
  }
}
