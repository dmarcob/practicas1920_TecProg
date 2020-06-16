//*****************************************************
// Autor: Diego Marco Beisty, 755232
// Fecha: 17/06/2020
// Fichero: ejercicio4.h
// Coms:Fichero interfaz ejercicio 4
//*****************************************************

#pragma once
#include <list>
#include <iostream>
const double PI = 3.151592653589;

class Point {
private:
   double x;
   double y;
public:
  Point(double x_=0, double y_=0);
  //Devuelve coordenada x
  double getx() const;
  //Devuelve coordenada y
  double gety() const;
  // Sea un punto p1(x1, y1), devuelve un nuevo punto de
  // coordenadas (min(x,x1),min(y,y1))
  Point* minNewPoint(const Point& p1) const;
  // Sea un punto p1(x1, y1), devuelve un nuevo punto de
  // coordenadas (max(x,x1),max(y,y1))
  Point* maxNewPoint(const Point& p1) const;
  bool operator<(const Point& p1);
  bool operator>(const Point& p1);
};
std::ostream& operator<<(std::ostream& os, const Point& p1);

/* Se ha decidido implementar una clase base abstracta llamada Objeto
 * que declara los métodos points y contains.
 * Las demás clases Rectangle, Circle y Polygon heredan de ella, usándola
 * a modo de interfaz.
 */
class Objeto {
public:
  virtual std::list<Point*> points() = 0;
  virtual bool contains(const Point& x) const = 0;
};

class Rectangle : public Objeto {
private:
  Point bl; //Bottom Left corner (esquina inferior izquierda)
  Point tr; //Top Right corner  (esquina superior derecha)
public:
  //Rectangulo construido a partir de dos puntos.
  Rectangle(Point& bl_, Point& tr_);
  std::list<Point*> points() override;
  bool contains(const Point& x) const override;
  //Devuelve el punto que representa la esquina inferior izquierda del rectángulo
  Point getbl() const;
  //Devuelve el punto que representa la esquina superior derecha del rectángulo
  Point gettr() const;
};

class Circle : public Objeto {
private:
  Point centro;
  double radio;
public:
  //Circulo definido a partir del centro y el radio.
  Circle(Point& centro_, double radio_);
  std::list<Point*> points() override;
  bool contains(const Point& x) const override;
  //Devuelve el punto que representa el centro del circulo
  Point getcentro() const;
  //Devuelve el radio del circulo
  double getradio() const;
};

class Polygon : public Objeto {
private:
  std::list<Point*> l;
  //Construye un punto cuyas coordenadas son el mayor valor
  //del eje x y el mayor valor del eje y de todos los puntos
  //de la lista l
  Point* maxListPoint() const;
  //Construye un punto cuyas coordenadas son el menor valor
  //del eje x y el menor valor del eje y de todos los puntos
  //de la lista l
  Point* minListPoint() const;
public:
  //Construye un poligono a partir de una lista de puntos
  Polygon(std::list<Point*> l_);
  std::list<Point*> points() override;
  bool contains(const Point& x) const override;
};

/* Se ha hecho uso de la programación genérica para implementar una función
 * collide generalizada para cualquier tipo de dato.
 * Se ha hecho uso de la especialización de plantillas para implementar dos
 * funciones collide específicas para la colisión entre círculos y la colisión
 * entre rectángulos. (Estas funciones están en ejercicio4.cpp)
 */

//Si cualquier punto de a está contenido en b ó cualquier punto de b
//está contenido en a, entonces a y b colisionan.
template<class T, class S>
bool collide( T& a, S& b) {
  bool colisionan = false;
  for ( Point* p : b.points()) {
      if (a.contains(*p)) colisionan = true;
  }
  for ( Point* p : a.points()) {
      if (b.contains(*p)) colisionan = true;
  }
  return colisionan;
}

/* Se ha hecho uso de la programación genérica para implementar una función
 * collide_any que acepta tanto listas de Objects (genéricas), como listas
 * homogéneas de Circle,Rectangle,..
 * Se ha comprobado que se llama correctamente a las funciones collide especializadas
 * si los argumentos pasados a esta función son dos Circle o dos Rectangle.
 */

//Comprueba si un objeto colisiona con cualquiera de una lista
//de objetos cualesquiera (genéricos o de un tipo determinado)
template<class T, class S>
bool collide_any(T& objeto, std::list<S*> lista) {
  bool colisionan = false;
  for (S* s : lista) {
      if (collide(objeto, *s)) colisionan = true;
  }
  return colisionan;
}
