import java.lang.Iterable;

interface Stack<T> extends Iterable<T>
{
  boolean push(T t);
  boolean pop();
}
