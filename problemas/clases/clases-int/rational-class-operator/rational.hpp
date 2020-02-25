#pragma once

#include <iostream>

class Rational {
private:
    int n, d;
    int mcd(int i1, int i2);
    void simplificar();
public:
     Rational(int i1 = 0, int i2 = 1);
     Rational suma(const Rational& r2) const;
     Rational suma(int i) const;
     void mostrar(std::ostream& os = std::cout) const;
     void leer(std::istream& is = std::cin);
};



Rational suma(int i, Rational r);

