//*****************************************************
// Autor: Diego Marco Beisty, 755232
// Fecha: 17/06/2020
// Fichero: ejercicio4.h
// Coms:
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
  double getx() const;
  double gety() const;
  // Sea un punto p1(x1, y1), devuelve un nuevo punto de
  // coordenadas (min(x,x1),min(y,y1))
  Point* minNewPoint(const Point& p1) const;
  // Sea un punto p1(x1, y1), devuelve un nuevo punto de
  // coordenadas (max(x,x1),max(y,y1))
  Point* maxNewPoint(const Point& p1) const;
};

class Objeto {
public:
  virtual std::list<Point*> points() = 0;
  virtual bool contains(const Point& x) const = 0;
};

class Rectangle : public Objeto {
private:
  Point bl;
  Point tr;
public:
  //Rectangulo construido a partir de dos puntos.
  //Punto botton left (esquina inferior izquierda)
  //Punto top right (esquina superior derecha)
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
  Point getcentro() const;
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
  Polygon(std::list<Point*> l_);
  std::list<Point*> points() override;
  bool contains(const Point& x) const override;
};

template<class T, class S>
//Si cualquier punto de a está contenido en b ó cualquier punto de b
//está contenido en a, entonces a y b colisionan.
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


template<class T, class S>
bool collide_any(T& objeto, std::list<S*> lista) {
  bool colisionan = false;
  for (S* s : lista) {
      if (collide(objeto, *s)) colisionan = true;
  }
  return colisionan;
}
