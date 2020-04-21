//*****************************************************************
// File:    ramaDivi.h
// Author:  Diego Marco Beisty 755232
// Date:    01-04-2020
// Coms:    interfaz modulo ramaDivi
//*****************************************************************

#pragma once
#include "rama.h"

class RamaDivi : public Rama
{
public:
  RamaDivi(Nodo* i_, Nodo* d_);
  float eval(const SymbolTab& syms)const override;
  string to_string()const override;
};
