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
Rational operator+(Rational r1, Rational r2);
Rational operator+(int i, Rational r);
Rational operator+(Rational r, int i);
void operator<<(std::ostream& os, Rational r);
void leer(Rational& r, std::istream& is = std::cin);

#endif
