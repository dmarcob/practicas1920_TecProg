#pragma once
#include <string>
#include <exception>
#include "nodo.h"

class HojaVariable : public Nodo
{
private:
  string dato;
public:
  HojaVariable(string dato_);
  float eval(const SymbolTab& syms)const override;
  string to_string()const override;
};

class undefined_symbol : public exception
{
public:
  const char* what() const  throw();
};
