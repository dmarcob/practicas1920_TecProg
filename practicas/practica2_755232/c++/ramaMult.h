#pragma once
#include "rama.h"

class RamaMult : public Rama
{
public:
  RamaMult(Nodo* i_, Nodo* d_);
  float eval(const SymbolTab& syms)const override;
  string to_string()const override;
};
