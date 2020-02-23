#include "rational.h"

// Helper functions -----------------------
int mcd(int a, int b) {
   return ( b == 0? a : mcd(b,a%b));
}

void reduce(Rational& r) {
   int m = mcd(r.num, r.den);
   r.num /= m; r.den /= m;
}

// Constructor -----------------------
Rational rational(int num, int den) {
   Rational sol;
   sol.num = num; sol.den = den;
   reduce(sol);
   return sol;
}

// Add -----------------------
Rational operator+(const Rational& r1, const Rational& r2) {
   return rational(r1.num*r2.den + r1.den*r2.num, r1.den*r2.den);
}

Rational operator+(const Rational& r, int i) {
   return rational(r.num*i, r.den);
}

Rational operator+(int i, const Rational& r) {
   return r+i;
}

// Substract -----------------------
Rational operator-(const Rational& r1, const Rational& r2) {
   return r1 + rational(-r2.num, r2.den);
}

Rational operator-(const Rational& r, int i) {
   return r + (-i);
}

Rational operator-(int i, const Rational& r) {
   return rational(-r.num, r.den) + i;
}

// Multiply -------------------------
Rational operator*(const Rational& r1, const Rational& r2) {
   return rational(r1.num*r2.num, r1.den*r2.den);
}

Rational operator*(const Rational& r, int i) {
   return rational(i*r.num, r.den);
}

Rational operator*(int i, const Rational& r) {
   return r*i;
}

// Divide ------------------------------
Rational operator/(const Rational& r1, const Rational& r2) {
   return rational(r1.num*r2.den, r1.den*r2.num);
}

Rational operator/(const Rational& r, int i) {
   return rational(r.num, r.den*i);
}

Rational operator/(int i, const Rational& r) {
   return rational(i*r.den, r.num);
}

// Helper function ------------------------------
float value(const Rational& r) {
	return float(r.num)/float(r.den);
}

// Input/output ---------------------------------
std::ostream& operator<<(std::ostream& os, const Rational& r) {
 	os<< r.num<<"/"<<r.den; return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {
	is >> r.num;
	is.ignore(1);
	is >> r.den;
	return is;
}


