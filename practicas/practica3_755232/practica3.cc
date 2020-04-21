//*****************************************************************
// File:    practica3.cc
// Author:  Diego Marco Beisty 755232
// Date:    21-04-2020
// Coms:    modulo implementacion practica 3
//*****************************************************************
#include "practica3.h"
#include <iostream>
#include <sstream>

//***********Metodos clase Cosa***************************
Cosa::Cosa(const string& name_,double weight_, double volume_) : name(name_), weight(weight_), volume(volume_) {};
string Cosa::nombre() const {
  return this->name;
}

double Cosa::peso() const {
  return this->weight;
}

double Cosa::volumen() const {
  return this->volume;
}


//************Metodos clase Carga**************************
Carga::Carga(const string& name_, double weight_, double volume_) :
   Cosa(name_, weight_, volume_) {}

string Carga::to_string(int desplazamiento) const {
    ostringstream oss;
    oss << string(desplazamiento,' ')<< this->name << " [" << this->volume << " m3] [" << this-> weight << " kg]" << endl;
    string str = oss.str();
    return str;
  }




/*////////////////////////////////////
//BORRAR
//string Carga::toString() const { return name + "holaaa";}
////////////////////////////////////*/

//************Metodos clase Almacen*************
Almacen::Almacen(const string& name_, double weight_,double capacity_) : Cosa(name_, weight_, capacity_), capacity(capacity_) {}

bool Almacen::guardar( Cosa& c) {
    if (c.volumen() > this->capacity) {
      return false;
    } else {
      Cosa* puntero = &c;
      this->contenido.push_back(puntero);
      this->capacity -= c.volumen();
      this->weight += c.peso();
      return true;
    }
}

string Almacen::to_string(int desplazamiento) const {
  ostringstream oss;
  oss << string(desplazamiento,' ') << this->name << " [" << this->volume << " m3] [" << this-> weight << " kg]" << endl;
  string str = oss.str();
  vector<Cosa*>::const_iterator it;
  for(it = contenido.begin(); it != contenido.end();it++) {
      str.append((*it)->to_string(desplazamiento + 3));
  }
  return str;
}


//*************Metodos clase Camion*****************
Camion::Camion(double capacity_) :
 Almacen("Camion", 0, capacity_) {}



//*************Metodos clase Producto*******************
Producto::Producto(double volume_, double weight_, const string& name_) :
   Carga(name_, weight_, volume_) {}


//************Metodos clase Contenedor******************
Contenedor::Contenedor(double volume_) : Almacen("Contenedor", 0, volume_) {}
