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


//--------------------------------------------------
  cout << "------------TEST rectangulo" << endl;
  list<Point*> l1;
  Point p1(1,4.5);
  Point p2(5.3, 2.1);
  Rectangle r1(p1, p2);
  l1 = r1.points();
  cout << "Lista de puntos generada:" << endl;
  for (Point* p : l1) {
          cout << *p << endl;
  }
  Point p3(2.4,12);
  Point p4(2.3, 3);
  if (r1.contains(p3)) cout << "Rectangulo contiene a p3" << endl;
  if (r1.contains(p4)) cout << "Rectangulo contiene a p4" << endl;


  //--------------------------------------------------
  cout << endl <<"------------TEST circulo" << endl;
  list<Point*> l2;
  Point p5(5.2, 6.1);
  Point p6(1,1);
  Circle c1(p5, 2.5);
  l2 = c1.points();
  cout << "Lista de puntos generada:" << endl;
  for (Point* p : l2) {
         cout << *p << endl;
  }
  if (c1.contains(p5)) cout << "Circulo contiene a p5" << endl;
  if (c1.contains(p6)) cout << "Circulo contiene a p6" << endl;


  //--------------------------------------------------
  cout << endl <<"------------TEST polygon" << endl;
 list<Point*> l3;
 Point p7(8.25,1.82);
 Point p8(6.25,2.82);
 Point p9(2.25,8.82);
 Point p10(3.25,5.82);
 l3.push_back(&p7);
 l3.push_back(&p8);
 l3.push_back(&p9);
 Polygon pol1(l3);
 for (Point* p : l3) {
        cout << *p << endl;
 }
 if  (pol1.contains(p10)) cout << "Polygon contiene a p10" << endl;
 if  (pol1.contains(p7)) cout << "Polygon contiene a p7" << endl;


 //--------------------------------------------------
 cout << endl <<"------------TEST funcion collide" << endl;
Point p11(2,3);
Point p12(4,1);
Point p13(3,2);
Point p14(6,0);
Point p15(5,2);

Rectangle r2(p11, p12);

Circle c2(p11, 3.7);
Circle c3(p12, 5);
//Caso generico
if (collide(r2, c2)) cout << "Colisión entre rectangulo y circulo" << endl;
//Caso generico
if (collide(r2, pol1)) cout << "Colisión entre rectangulo y poligono" << endl;
//Caso especializada entre circulos
if (collide(c2, c3)) cout << "Colisión entre circulo y circulo" << endl; //Colisionan
//Caso especializada entre rectangulos
if (collide(r2, r2)) cout << "Colisión entre rectangulo y rectangulo" << endl; //Colisionan


//--------------------------------------------------
cout << endl <<"------------TEST funcion collide_any" << endl;
list<Objeto*> lo;
list<Rectangle*> lr;
list<Circle*> lc;
Rectangle r5(p1, p2);
Rectangle r6(p13, p14);
Rectangle r7(p15, p14);
lo.push_back(&r6);
lo.push_back(&c1);
lo.push_back(&pol1);
lr.push_back(&r5);
lr.push_back(&r7);
lc.push_back(&c1);
lc.push_back(&c1);

//Caso generico
if (collide_any(r5, lo)) cout << "colision entre rectangulo y lista genericos" << endl;
//Caso especializacion rectangulo con rectangulo
if (collide_any(r5, lr)) cout << "colision entre rectangulo y lista de rectangulos" << endl;
//Caso especializacion circulo con circulo
if (collide_any(c1, lc)) cout << "colision entre circulo y lista de circulos lista" << endl;

  return 0;
}
