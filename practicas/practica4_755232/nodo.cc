//*****************************************************************
// File:    nodo.cc
// Author:  Diego Marco Beisty 755232
// Date:    26-04-2020
// Coms:
//*****************************************************************
#include "nodo.h"
Nodo::Nodo(const string& name_, int size_) : name(name_), size(size_) {}
string Nodo::nombre() const {
  return this->name;
}
int Nodo::tamano() const {
  return this->size;
}
