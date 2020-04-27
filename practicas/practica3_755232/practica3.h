//*****************************************************************
// File:    practica3.h
// Author:  Diego Marco Beisty 755232
// Date:    21-04-2020
// Coms:    modulo interfaz practica 3
//*****************************************************************
#pragma once
#include <string>
#include <vector>
#include <iterator>
using namespace std;

/* JERARQUÍA:
 *
 *                        Cosa
 *         Carga                        Almacen
 * Producto SerVivo Toxico      Contenedor   Camion
 *
 *
 * EXPLICACIÓN:
 * Cosa permite almacenar los atributos que tienen en común todas las clases, en concreto
 * nombre, peso y volumen, junto con sus métodos getter. Además define el método virtual puro
 * to_string que será implementado en sus clases hijas Carga y Almacen.
 *
 * Carga representa a aquellos objetos que se pueden cargar dentro de otros. Al principio también
 * se añadió como descendiente de esta clase a Contenedor, pero debido a múltiples complicaciones al implementar
 * herencia múltiple se decidió no ponerlo. Esta clase implementa su popia versión de to_string en la que
 * se muestra el nombre del objeto junto con su volumen y peso.
 *
 * Almacen representa a aquellos objetos que pueden almacenar otros objetos, como son los contenedores
 * y los camiones. Esta clase añade el atributo capacidad, inicialmente equivalente al volumen del objeto.
 * Añade el método guarda que recibe cualquier objeto descendiente de Cosa y almacena su puntero en un
 * vector.
 *
 * Contenedor hace uso de la especialización de plantillas para poder restringir los tipos de objectos
 * que puede recibir su método heredado guardar, siendo una clase genérica.
 *
 * Respecto a las clases nietas Producto SerVivo y Toxico, se observa que también he añadido una clase nieta
 * llamada Generico, esto se debe al tipo Contenedor<Generico>, que requiere de Generico.

 */

class Cosa {
protected:
   const string name;
   double weight;
   double volume;
public:
  Cosa(const string& name_, double weight_, double volume_);
  string nombre() const;
  double peso() const;
  double volumen() const;
  virtual string to_string(int desplazamiento = 0) const = 0;

};


class Carga : public Cosa {
public:
    Carga(const string& name_, double weight_, double volume_);
    string to_string(int desplazamiento = 0) const override;
};


class Almacen :  public Cosa {
protected:
  double capacity;
  vector<Cosa*>contenido;
public:
  Almacen(const string& name_, double weight_,double capacity_);
  bool guardar(Cosa& c);
  string to_string(int deplazamiento=0) const override;
};


class Camion : public Almacen {
public:
  Camion(double capacity_);
};


class Producto : public Carga {
public:
  Producto (double volume_, double weight_, const string& name_);
};

class Generico : public Carga {
public:
  Generico (double volume_, double weight_, const string& name_);
};

class Toxico : public Carga {
public:
  Toxico (double volume_, double weight_, const string& name_);
};


class SerVivo : public Carga {
public:
  SerVivo (double volume_, double weight_, const string& name_);
};


//Por defecto no existe implementación generica para ningún tipo T
template<class T>
class Contenedor : public Almacen{};

//Añado el comportamiento especifico para Contenedor<Toxico>,
//Contenedor<SerVivo> y Contenedor<Generico>
template<>
class Contenedor<Toxico> : public Almacen{
public:
  Contenedor<Toxico>(double volume_): Almacen("Contenedor de productos toxicos", 0, volume_) {}

  //Añado la restricción de que solo se podrá guardar un objeto de tipo Toxico
  bool guardar(Toxico& c) {
    return Almacen::guardar(c);
  }

};

template<>
class Contenedor<SerVivo> : public Almacen{
public:
  Contenedor<SerVivo>(double volume_): Almacen("Contenedor de seres vivos", 0, volume_) {}

  bool guardar(SerVivo& c) {
    return Almacen::guardar(c);
  }

};

template<>
class Contenedor<Generico> : public Almacen{
public:
  Contenedor<Generico>(double volume_): Almacen("Contenedor de genericos", 0, volume_) {}

  bool guardar(Producto& c) {
    return Almacen::guardar(c);
  }
  bool guardar(Contenedor<Generico>& c) {
    return Almacen::guardar(c);
  }
  bool guardar(Contenedor<Toxico>& c) {
    return Almacen::guardar(c);
  }
  bool guardar(Contenedor<SerVivo>& c) {
    return Almacen::guardar(c);
  }
};
