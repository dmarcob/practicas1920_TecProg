//*****************************************************
// Autor: Diego Marco Beisty, 755232
// Fecha: 17/06/2020
// Fichero: ejercicio4.cpp
// Coms:
//*****************************************************
#include "ejercicio4.h"
#include <cmath>
#include <iostream>
using namespace std;

Point::Point(double x_,double y_) : x(x_),y(y_) {};

double Point::getx() const {
  return this -> x;
}

double Point::gety() const {
  return this -> y;
}

Point* Point::minNewPoint(const Point& p1) const {
  double x1 = p1.getx();
  double y1 = p1.gety();
  return new Point(fmin(this->x,x1), fmin(this->y, y1));
}

Point* Point::maxNewPoint(const Point& p1) const {
  double x1 = p1.getx();
  double y1 = p1.gety();
  return new Point(fmax(this->x,x1), fmax(this->y, y1));
}

Rectangle::Rectangle(Point& bl_, Point& tr_) : bl(bl_),tr(tr_){};

list<Point*> Rectangle::points() {
  list<Point*> l;
  l.push_back(&bl); //Esquina inferior izquierda
  l.push_back(&tr); //Esquina superior derecha
  l.push_back(bl.minNewPoint(tr)); //Esquina superior izquierda
  l.push_back(bl.maxNewPoint(tr)); //Esquina inferior derecha
  return l;
}


Point Rectangle::getbl() const {
  return this->bl;
}
Point Rectangle::gettr() const {
  return this->tr;
}

bool Rectangle::contains(const Point& x) const {
  double x1 = x.getx();
  double y1 = x.gety();
  //x está contenido en el rectángulo sii x1 pertenece al rango ( bl.getx(), tr.getx() )
  // y y1 pertenece al rango ( tr.gety(), bl.gety() )
  return (x1 < tr.getx()) && (x1 > bl.getx()) &&
    (y1 < bl.gety()) && (y1 > tr.gety());
}


Circle::Circle(Point& centro_, double radio_) : centro(centro_), radio(radio_){};


list<Point*> Circle::points() {
  list<Point*> l;
  //Puesto que cos(alfa) = x / radio -> x = cos(alfa) * radio
  //Puesto que sen(alfa) = y /radio -> y = sen(alfa) * radio
  //Con alfa = 11.25 grados (en radianes) para obtener 32 puntos.
  double anguloRad = 11.25 * PI / 180; //ángulo en radianes
  for (int i = 0; i < 32; i++) {
    double x = (cos(i*anguloRad) * this->radio) + this->centro.getx();
    double y = (sin(i*anguloRad) * this->radio) + this->centro.gety();
    l.push_back(new Point(x, y));
  }
  return l;
}

bool Circle::contains(const Point& x) const {
  //Calculo la distancia con el punto x aplicando:
  // distancia = sqrt( (x1-x2)^2 + (y1 -y2)^2 )
  double distanciax = pow(x.getx() - this->centro.getx(), 2.0);
  double distanciay = pow(x.gety() - this->centro.gety(), 2.0);
  double distancia = sqrt(distanciax + distanciay);
  return distancia < this->radio;
}

Point Circle::getcentro() const {
  return this->centro;
}
double Circle::getradio() const {
  return this->radio;
}


Polygon::Polygon(list<Point*> l_) : l(l_) {};

Point* Polygon::maxListPoint() const{
    double xmax;
    double ymax;
    bool primIter = true;
    for(Point* p : l) {
      if (primIter) {
          xmax = p->getx();
          ymax = p->gety();
          primIter=false;
      } else {
          xmax = fmax(xmax, p->getx());
          ymax = fmax(ymax, p->gety());
      }
    }
    return new Point(xmax,ymax);
}

Point* Polygon::minListPoint() const{
    double xmin;
    double ymin;
    bool primIter = true;
    for(Point* p : l) {
      if (primIter) {
          xmin = p->getx();
          ymin = p->gety();
          primIter=false;
      } else {
          xmin = fmin(xmin, p->getx());
          ymin = fmin(ymin, p->gety());
      }
    }
    return new Point(xmin,ymin);
}


std::list<Point*> Polygon::points() {
  return this->l;
}

bool Polygon::contains(const Point& x) const {
  Point* pmax = this->maxListPoint();
  Point* pmin = this->minListPoint();
  double x1 = x.getx();
  double y1 = x.gety();
  //x está contenido en el polígono sii x1 pertenece al rango ( pmax.getx(), pmin.getx() )
  // y y1 pertenece al rango ( pmax.gety(), pmin.gety() )
  bool contenido = (x1 < pmax->getx()) && (x1 > pmin->getx()) &&
    (y1 < pmax->gety()) && (y1 > pmin->gety());
  delete pmax; delete pmin;
  return contenido;
}

//Especialización de la función collide para el caso de dos
//círculos
template<>
bool collide<Circle>( Circle& a,  Circle& b) {
  //Si la distancia entre los centros de a y de b es menor que
  //la suma de sus radios, entonces a y b colisionan.
  std::cout << "Especializacion circulos" << std::endl;

  Point acentro = a.getcentro();
  Point bcentro = b.getcentro();
  double distanciax = pow(acentro.getx() - bcentro.getx(), 2.0);
  double distanciay = pow(acentro.gety() - acentro.gety(), 2.0);
  double distancia = sqrt(distanciax + distanciay);
  return distancia < (a.getradio() + b.getradio());
}

//Especialización de la función collide para el caso de dos
//rectangulos
template<>
bool collide<Rectangle>( Rectangle& a, Rectangle& b) {
  //Si se cumple la condición de que el valor de la coordenada máxima x e y
  //del rectangulo a es superior a la coordenada mínima x e y del rectangulo b,
  //y además la coordenada mínima de rectangulo a es inferior a la coordenada
  //máxima del rectangulo b (y viceversa), entonces los rectangulos colisionan.
  std::cout << "Especializacion rectangulos" << std::endl;
  Point abl = a.getbl(); //botton left corner rectangulo a
  Point  bbl = b.getbl(); //botton left corner rectangulo b
  //Puntos máximo y mínimo del rectangulo a
  Point* amax = abl.maxNewPoint(a.gettr());
  Point* amin = abl.minNewPoint(a.gettr());
  //Puntos máximo y mínimo del rectángulo b
  Point* bmax = bbl.maxNewPoint(b.gettr());
  Point* bmin = bbl.minNewPoint(b.gettr());

  return amax->getx() > bmin->getx() and amin->getx() < bmax ->getx()
      and amax->gety() > bmin->gety() and amin->gety() < bmax ->gety();
}
