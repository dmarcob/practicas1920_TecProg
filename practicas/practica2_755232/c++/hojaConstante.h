//*****************************************************************
// File:    hojaConstante.h
// Author:  Diego Marco Beisty 755232
// Date:    01-04-2020
// Coms:    interfaz modulo expression
//*****************************************************************

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
