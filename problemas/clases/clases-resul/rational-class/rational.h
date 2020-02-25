#pragma once

#include <iostream>

//- All methods, except adding with a first integer parameter
//- All functions are named, no operators overloaded
//- Attributes private so they can only be accessed from the methods.
class Rational {
private:
   int num, den;
   static int mcd(int a, int b);
   void reduce();
public:
   Rational(int num = 0, int den = 1);
   Rational add(const Rational& that) const;
   Rational add(int i) const; 
   Rational substract(const Rational& that) const;
   Rational substract(int i) const; 
   Rational multiply(const Rational& that) const;
   Rational multiply(int i) const; 
   Rational divide(const Rational& that) const;
   Rational divide(int i) const; 
   float value() const;
   void write(std::ostream& os = std::cout) const;
   void read(std::istream& is = std::cin);
};

Rational add(int i, const Rational& r);
Rational substract(int i, const Rational& r);
Rational multiply(int i, const Rational& r);
Rational divide(int i, const Rational& r);

