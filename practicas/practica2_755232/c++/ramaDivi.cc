#include "ramaDivi.h"
#include "prioridad.h"

RamaDivi::RamaDivi(Nodo* i_, Nodo* d_) : Rama(i_, d_) {}

float RamaDivi::eval(const SymbolTab& syms)const
{
  return i->eval(syms) / d->eval(syms);
}

string RamaDivi::to_string()const
{
  string resul;
  Prioridad izq(i);
  Prioridad der(d);
  if (!izq.tienePrioridad())
  {
    resul = "(" + i->to_string() + ")" + " / " + d->to_string();
  }
  else if(!der.tienePrioridad())
  {
    resul = i->to_string() + " / " + "(" + d->to_string() + ")";
  }
  else {
    resul = i->to_string() + " / " + d->to_string();
  }
  return resul;
}
