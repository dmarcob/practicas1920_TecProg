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


//Evita la repetición del atributo name, weight y el método nombre.
//De esta clase hereda Carga y Almacen
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

//Contiene los atributos y métodos comunes a los objetos que pueden
//ser cargados como contenedores y productos
class Carga : public Cosa {
public:
    //Carga(double volume_,double weight_ ,const string& name_);
    Carga(const string& name_, double weight_, double volume_);
    string to_string(int desplazamiento = 0) const override;

    /*////////////////////////////////////
    //BORRAR
    //string toString() const override;
    ////////////////////////////////////*/
};

//Almacén de capacidad definida en el constructor, que puede guardar
//objetos de tipo Carga si su volumen es menor o igual a la capacidad
//del almacen
class Almacen :  public Cosa {
protected:
  double capacity;
  //list<Cosa> contenido;
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


template<class T>
class Contenedor : public Almacen{};

template<>
class Contenedor<Toxico> : public Almacen{
public:
  Contenedor<Toxico>(double volume_): Almacen("Contenedor de productos toxicos", 0, volume_) {}

  bool guardar(Toxico& c) {
    Almacen::guardar(c);
  }

};

template<>
class Contenedor<SerVivo> : public Almacen{
public:
  Contenedor<SerVivo>(double volume_): Almacen("Contenedor de seres vivos", 0, volume_) {}

  bool guardar(SerVivo& c) {
    Almacen::guardar(c);
  }

};

template<>
class Contenedor<Generico> : public Almacen{
public:
  Contenedor<Generico>(double volume_): Almacen("Contenedor de genericos", 0, volume_) {}

  bool guardar(Producto& c) {
    Almacen::guardar(c);
  }
  bool guardar(Contenedor<Generico>& c) {
    Almacen::guardar(c);
  }
  bool guardar(Contenedor<Toxico>& c) {
    Almacen::guardar(c);
  }
  bool guardar(Contenedor<SerVivo>& c) {
    Almacen::guardar(c);
  }
};
