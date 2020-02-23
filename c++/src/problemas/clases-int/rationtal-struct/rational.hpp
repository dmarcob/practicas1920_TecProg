#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>

struct Rational {
	int n;
	int d;
};

int mcd(int i1, int i2);
void simplificar(Rational& r);
Rational rational(int i1, int i2);
Rational suma(Rational r1, Rational r2);
Rational suma(int i, Rational r);
Rational suma(Rational r, int i);
void mostrar(Rational r, std::ostream& os = std::cout);
void leer(Rational& r, std::istream& is = std::cin);

#endif
