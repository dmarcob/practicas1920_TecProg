//*****************************************************************
// File:    ramaMulti.h
// Author:  Diego Marco Beisty 755232
// Date:    01-04-2020
// Coms:    interfaz modulo ramaMulti
//*****************************************************************

#pragma once
#include "rama.h"

class RamaMult : public Rama
{
public:
  RamaMult(Nodo* i_, Nodo* d_);
  float eval(const SymbolTab& syms)const override;
  string to_string()const override;
};
