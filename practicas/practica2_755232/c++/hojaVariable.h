//*****************************************************************
// File:    hojaVariable.cc
// Author:  Diego Marco Beisty 755232
// Date:    01-04-2020
// Coms:    interfaz modulo hojaVariable
//*****************************************************************

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
private:
  string excep;
public:
  undefined_symbol(string symbol_);
  const char* what() const  throw();
};
