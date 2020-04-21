//*****************************************************************
// File:    ramaResta.h
// Author:  Diego Marco Beisty 755232
// Date:    01-04-2020
// Coms:    implementacion modulo ramaResta
//*****************************************************************

#pragma once
#include "rama.h"

class RamaResta : public Rama
{
public:
  RamaResta(Nodo* i_, Nodo* d_);
  float eval(const SymbolTab& syms)const override;
  string to_string()const override;
};
