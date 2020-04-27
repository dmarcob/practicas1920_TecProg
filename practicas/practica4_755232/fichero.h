//*****************************************************************
// File:    fichero.h
// Author:  Diego Marco Beisty 755232
// Date:    26-04-2020
// Coms:
//*****************************************************************
#pragma once
#include "nodo.h"

class Fichero : public Nodo {
public:
  Fichero(const string& name_, int size_);
  void actualizarTam(int size_);
};
