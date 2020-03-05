#pragma once
#include "cuenta.hpp"

class CuentaCorriente : public Cuenta {
public:
  CuentaCorriente(double _capital, double _interes): Cuenta(_capital, _interes) {}

  double valor(int t)const override {
    return capital*(1 + interes/12)*t;
  }
};
