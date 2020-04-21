#include "practica3.h"
#include <iostream>

int main() {

  Producto p4(1,0.2,"boli");

  Contenedor c2(1);
  c2.guardar(p4);
  Producto p3(3,5,"pasa");
  Contenedor c1(10);


  c1.guardar(p3);
  c1.guardar(c2);

  Producto p1(3.0,4.7,"ordenador");
  Camion m1(20);
  m1.guardar(p1);
  m1.guardar(c1);
  m1.guardar(p1);
  cout << m1.to_string() << endl;
  //m1.to_string();

  return 0;
}
