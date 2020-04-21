//*****************************************************************
// File:    hojaConstante.cc
// Author:  Diego Marco Beisty 755232
// Date:    01-04-2020
// Coms:    implementacion modulo hojaConstante
//*****************************************************************

#include "hojaConstante.h"
#include <sstream>
HojaConstante::HojaConstante(float dato_) : dato(dato_) {}

float HojaConstante::eval(const SymbolTab& syms)const
{
  return this->dato;
}

string HojaConstante::to_string()const
{
  std::ostringstream ss;
  ss << this->dato;
  return  ss.str();
}
