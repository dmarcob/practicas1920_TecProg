#pragma once

#include <iostream>

using namespace std;

//- No methods, all functions
//- All functions are named, no operators overloaded
//- Attributes public so they can be accessed from the functions.
struct Rational {
   int num, den;
};

int mcd(int a, int b);
void reduce(Rational& r);
Rational rational(int num, int den = 1);
Rational operator+(const Rational& r1, const Rational& r2);
Rational operator+(const Rational& r, int i);
Rational operator+(int i, const Rational& r);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r, int i);
Rational operator-(int i, const Rational& r);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r, int i);
Rational operator*(int i, const Rational& r);
Rational operator/(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r, int i);
Rational operator/(int i, const Rational& r);
float value(const Rational& r);
std::ostream& operator<<(std::ostream& os, const Rational& r);
std::istream& operator>>(std::istream& is, Rational& r);

