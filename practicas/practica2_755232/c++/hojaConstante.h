#pragma once
#include "nodo.h"

class HojaConstante : public Nodo
{
private:
  float dato;
public:
  HojaConstante(float dato_);
  float eval(const SymbolTab& syms)const override;
  string to_string()const override;
};
