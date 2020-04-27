//*****************************************************************
// File:    nodo.h
// Author:  Diego Marco Beisty 755232
// Date:    26-04-2020
// Coms:
//*****************************************************************
#pragma once
#include <string>
using namespace std;
class Nodo {
protected:
  string name;  //Nombre identificativo del nodo
  int size;     //Tamaño nodo en bytes
public:
   Nodo(const string& name_, int size_);
  virtual string nombre() const;
  int tamano() const;
};
