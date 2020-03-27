#pragma once
#include "rama.h"

class RamaDivi : public Rama
{
public:
  RamaDivi(Nodo* i_, Nodo* d_);
  float eval(const SymbolTab& syms)const override;
  string to_string()const override;
};
