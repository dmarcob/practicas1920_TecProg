//*****************************************************************
// File:    ramaMulti.cc
// Author:  Diego Marco Beisty 755232
// Date:    01-04-2020
// Coms:    implementacion modulo ramaMulti
//*****************************************************************

#include "ramaMult.h"
#include "prioridad.h"

RamaMult::RamaMult(Nodo* i_, Nodo* d_) : Rama(i_, d_) {}

float RamaMult::eval(const SymbolTab& syms)const
{
  return i->eval(syms) * d->eval(syms);
}

string RamaMult::to_string()const
{
  string resul;
  Prioridad izq(i);
  Prioridad der(d);
  if (!izq.tienePrioridad())
  {
    resul = "(" + i->to_string() + ")" + " * " + d->to_string();
  }
  else if(!der.tienePrioridad())
  {
    resul = i->to_string() + " * " + "(" + d->to_string() + ")";
  }
  else {
    resul = i->to_string() + " * " + d->to_string();
  }
  return resul;
}
