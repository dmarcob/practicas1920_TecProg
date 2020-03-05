#pragma once
#include "cuenta.hpp"

class PlazoFijo : public   Cuenta
{
protected:
  int plazo;
public:
  PlazoFijo(double _capital, double _interes, double _plazo) :   Cuenta(_capital,_interes), plazo(_plazo){}

  double valor(int t)const override
  {
    return t < plazo?capital:capital*(interes + 1);
  }
};
