//*****************************************************************
// File:    enlace.h
// Author:  Diego Marco Beisty 755232
// Date:    26-04-2020
// Coms:
//*****************************************************************
#pragma once
#include "nodo.h"

//T debe ser un hijo de Nodo y debe tener implementado
//el metodo "actualizarTam"
template <typename T>
class Enlace : public Nodo {
private:
  T* original; //Nodo al que hace referencia
public:
  Enlace(const string& name_, T* original_) : Nodo(name_, original_->tamano()),  original(original_){}

  //Solo si es un enlace a fichero, actualiza el tamaño del
  //fichero y el del enlace con el valor size_
  void actualizarTam(int size_) {
      original->actualizarTam(size_);
      this->size = size_;
  }
};
