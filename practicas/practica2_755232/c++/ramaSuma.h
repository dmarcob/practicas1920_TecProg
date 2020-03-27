#pragma once
#include "rama.h"

class RamaSuma : public Rama
{
public:
  RamaSuma(Nodo* i_, Nodo* d_);
  float eval(const SymbolTab& syms)const override;
  string to_string()const override;
};
