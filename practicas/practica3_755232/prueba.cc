#include "practica3.h"
#include <iostream>

int main() {

  Producto p4(1,0.2,"veneno");

  Contenedor<Generico> c2(1);
  c2.guardar(p4);
  cout << c2.to_string() << endl;
/*  SerVivo p3(3,5,"perro");
  Contenedor c1(10);


  c1.guardar(p3);
  c1.guardar(c2);

  Generico p1(3.0,4.7,"ordenador");
  Camion m1(20);
  Camion m2(30);
  m1.guardar(p1);
  m1.guardar(c1);
  m1.guardar(p1);
  m1.guardar(m2);
  cout << m1.to_string() << endl;



  //m1.to_string();*/

  return 0;
}
