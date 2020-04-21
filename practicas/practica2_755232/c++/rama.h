//*****************************************************************
// File:    rama.h
// Author:  Diego Marco Beisty 755232
// Date:    01-04-2020
// Coms:    interfaz modulo rama
//*****************************************************************

#pragma once
#include "nodo.h"

class Rama : public Nodo
{
protected:
  Nodo* i;
  Nodo* d;
public:
  Rama(Nodo* i_, Nodo* d_);

};
