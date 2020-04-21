//*****************************************************************
// File:    ramaSuma.h
// Author:  Diego Marco Beisty 755232
// Date:    01-04-2020
// Coms:    interfaz modulo ramaSuma
//*****************************************************************

#pragma once
#include "rama.h"

class RamaSuma : public Rama
{
public:
  RamaSuma(Nodo* i_, Nodo* d_);
  float eval(const SymbolTab& syms)const override;
  string to_string()const override;
};
