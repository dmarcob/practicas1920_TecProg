//*****************************************************************
// File:    hojaVariable.cc
// Author:  Diego Marco Beisty 755232
// Date:    01-04-2020
// Coms:    implementacion modulo hojaVariable
//*****************************************************************

#include "hojaVariable.h"
#include <iostream>

undefined_symbol::undefined_symbol(string symbol_) :
  excep("ERROR!!! '"+ symbol_ + "' no esta definida") {}
const char* undefined_symbol::what() const throw()
{
  return this->excep.c_str();
}

HojaVariable::HojaVariable(string dato_) : dato(dato_) {}

float HojaVariable::eval(const SymbolTab& syms)const
{
  map<string,float>::const_iterator it = syms.find(this->dato);
  try {
     //Lanzo excepcion simbolo no definido si no tiene valor float asociado
    if (it == syms.end()) throw undefined_symbol(this->dato);
  }
  catch(exception& e) {
    cout << e.what() << endl;
  }

  return it->second;
}

string HojaVariable::to_string()const
{
  return this->dato;
}
