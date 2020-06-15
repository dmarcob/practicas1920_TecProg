//*****************************************************
// Autor: Diego Marco Beisty, 755232
// Fecha: 17/06/2020
// Fichero: main.cpp
// Coms: Programa principal ejericio 4
//*****************************************************
#include <iostream>
#include "ejercicio4.h"
#include <list>
using namespace std;

int main() {
  //  Coordenadas
  //   ------> x
  //  |
  //  | y
//--------------------punto
  Point p1(5.3,1.8);
  Point p2(5.2,2);
  Point* p3 = p1.maxNewPoint(p2);
  //cout << p3->getx() << endl;
  //cout << p3->gety() << endl;

//--------------------rectangulo
  list<Point*> l;
  Rectangle r(p1, p2);
  l = r.points();
  for (auto v : l)
      //    std::cout << v->getx() << "," << v->gety()<< "\n";

  Point p4(2.4,12);
//  if (r.contains(p4)) cout << "contenido" << endl;
  //--------------------circulo
    list<Point*> z;
  Circle c(p2, 2.5);
  z = c.points();
  //for (auto v : z)
        //  std::cout << v->getx() << "," << v->gety()<< "\n";

  //cout << c.contains(p1) << endl;
//----------------------Polygon
 list<Point*> t;
 Point p5(8.25,1.82);
 t.push_back(&p1);
 t.push_back(&p2);
 Polygon p(t);
  //if  (p.contains(p5)) cout << "contiene" << endl;

//-----------------------collide
  Circle c1(p5, 2.5);
//if (collide(c1, c)) cout << "colisionan" << endl;

Point p7(2,3);
Point p8(4,1);
Point p9(3,2);
Point p10(6,0);
Point p11(5,2);

Rectangle r5(p7, p8);
Rectangle r6(p9, p10);
Rectangle r7(p11, p10);
if (collide(r5, r6)) cout << "colisionan" << endl; //Colisionan
if (collide(r5, r7)) cout << "colisionan" << endl; //No colisionan


//-----------------collide_any
list<Objeto*> u;
u.push_back(&r5);
u.push_back(&c1);
collide_any(r, u);

  return 0;
}
