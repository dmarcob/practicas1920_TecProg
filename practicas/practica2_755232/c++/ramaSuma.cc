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
