#include "hojaConstante.h"

HojaConstante::HojaConstante(float dato_) : dato(dato_) {}


float HojaConstante::eval(const SymbolTab& syms)const
{
  return this->dato;
}

string HojaConstante::to_string()const
{
  return std::to_string(this->dato);
}
