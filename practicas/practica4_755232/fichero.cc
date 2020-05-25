//*****************************************************************
// File:    fichero.cc
// Author:  Diego Marco Beisty 755232
// Date:    26-04-2020
// Coms:
//*****************************************************************
#include "fichero.h"
#include <iostream>

Fichero::Fichero(const string& name_, int size_) : Nodo(name_, size_) {}

void Fichero::actualizarTam(int size_) {
  if (size_ > 0) {
    this->size = size_;
  } else {
    cout <<"ERROR nuevo tamaño fichero negativo: AÑADIR EXCEPCION" << endl;
  }
}
