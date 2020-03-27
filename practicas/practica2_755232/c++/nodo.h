#pragma once
#include "symboltab.h"

class Nodo
{
public:
  virtual float eval(const SymbolTab& syms) const = 0;
  virtual string to_string() const = 0;
};
