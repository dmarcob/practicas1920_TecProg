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


class Contenedor : public Almacen {
public:
  Contenedor(double volume_);
};
