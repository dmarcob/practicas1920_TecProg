#include "hojaVariable.h"
#include <iostream>



const char* undefined_symbol::what() const throw()
{
  return "ERROR: simbolo no definido";
}

HojaVariable::HojaVariable(string dato_) : dato(dato_) {}

float HojaVariable::eval(const SymbolTab& syms)const
{
  map<string,float>::const_iterator it = syms.find(this->dato);
  try {
    if (it == syms.end()) throw undefined_symbol(); //El símbolo this->dato no está definido
  }
  catch(exception& e) {
    cout << e.what() << endl;
  }

  return it->second;
}

string HojaVariable::to_string()const
{
  std::cout << "soy_hoja_variable: " << dato << std::endl;
  return this->dato;
}
