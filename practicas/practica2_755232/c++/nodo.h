//*****************************************************************
// File:    hojaVariable.cc
// Author:  Diego Marco Beisty 755232
// Date:    01-04-2020
// Coms:    Clase abstracta nodo
//*****************************************************************

#pragma once
#include "symboltab.h"

class Nodo
{
public:
  virtual float eval(const SymbolTab& syms) const = 0;
  virtual string to_string() const = 0;
};
