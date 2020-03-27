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
