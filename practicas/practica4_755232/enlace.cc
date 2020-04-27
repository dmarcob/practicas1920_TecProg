//*****************************************************************
// File:    enlace.cc
// Author:  Diego Marco Beisty 755232
// Date:    26-04-2020
// Coms:
//*****************************************************************
#include "enlace.h"
#include "fichero.h"
#include <iostream>

Enlace::Enlace(const string& name_, Nodo* original_) : Nodo(name_, original_->tamano()),  original(original_){}

void Enlace::actualizarTam(int size_) {
  if (Fichero* f= dynamic_cast<Fichero*>(original)) {
    //caso es un enlace a fichero
    f->actualizarTam(size_);
    this->size = size_;
  } else  {
    cout << "ERROR no es un enlace a fichero y no se puede editar: INSERTAR EXCEPCION AQUI" << endl;
  }
}
