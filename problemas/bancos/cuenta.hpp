#pragma once

class Cuenta {
protected:
  double capital;
  double interes;
public:
  Cuenta(double _capital, double _interes) : capital(_capital), interes(_interes) {}
  virtual double valor(int t) const = 0;
};
