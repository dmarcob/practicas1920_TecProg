//*****************************************************************
// File:    enlace.h
// Author:  Diego Marco Beisty 755232
// Date:    26-04-2020
// Coms:
//*****************************************************************
#pragma once
#include "nodo.h"

class Enlace : public Nodo {
private:
  Nodo* original; //Nodo al que hace referencia
public:
  Enlace(const string& name_, Nodo* original_);
  //Solo si es un enlace a fichero, actualiza el tamaño del
  //fichero y el del enlace con el valor size_
  void actualizarTam(int size_);

};
