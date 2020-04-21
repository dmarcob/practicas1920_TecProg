//*****************************************************************
// File:    ramaSuma.cc
// Author:  Diego Marco Beisty 755232
// Date:    01-04-2020
// Coms:    implementacion modulo ramaSuma
//*****************************************************************

#include "ramaSuma.h"

RamaSuma::RamaSuma(Nodo* i_, Nodo* d_) : Rama(i_, d_) {}

float RamaSuma::eval(const SymbolTab& syms)const
{
  return i->eval(syms) + d->eval(syms);
}

string RamaSuma::to_string()const
{
  return i->to_string() + " + " + d->to_string();
}
