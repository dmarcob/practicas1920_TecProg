
//*****************************************************************
// File:    ramaResta.cc
// Author:  Diego Marco Beisty 755232
// Date:    01-04-2020
// Coms:    implementacion modulo ramaResta
//*****************************************************************
#include "ramaResta.h"

RamaResta::RamaResta(Nodo* i_, Nodo* d_) : Rama(i_, d_) {}

float RamaResta::eval(const SymbolTab& syms)const
{
  return i->eval(syms) - d->eval(syms);
}

string RamaResta::to_string()const
{
  return i->to_string() + " - " + d->to_string();
}
