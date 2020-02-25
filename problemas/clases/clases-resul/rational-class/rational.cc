#include "rational.h"

// Helper methods -----------------------
int Rational::mcd(int a, int b) {
   return ( b == 0? a : mcd(b,a%b));
}

void Rational::reduce() {
   int m = mcd(num, den);
   num /= m; den /= m;
}

// Constructor -----------------------
Rational::Rational(int num, int den) : num(num), den(den) {
   reduce();
}

// Add -----------------------
Rational Rational::add(const Rational& that) const {
	return Rational(this->num*that.den + this->den*that.num, this->den*that.den);
}

Rational Rational::add(int i) const {
	return add(Rational(i));
}

Rational add(int i, const Rational& r) {
   return r.add(i);
}

// Substract -----------------------
Rational Rational::substract(const Rational& that) const {
	return Rational(this->num*that.den - this->den*that.num,this->den*that.den);
}

Rational Rational::substract(int i) const {
	return substract(Rational(i));
}

Rational subtract(int i, const Rational& r) {
   return Rational(i).substract(r);
}

// Multiply -------------------------
Rational Rational::multiply(const Rational& that) const {
	return Rational(this->num*that.num,this->den*that.den);
}

Rational Rational::multiply(int i) const {
	return multiply(Rational(i));
}


Rational multiply(int i, const Rational& r) {
   return r.multiply(i);
}


// Divide ------------------------------
Rational Rational::divide(const Rational& that) const {
	return Rational(this->num*that.den,this->den*that.num);
}

Rational Rational::divide(int i) const {
	return divide(Rational(i));
}

Rational divide(int i, const Rational& r) {
   return Rational(i).divide(r);
}


// Helper function ------------------------------
float Rational::value()  const {
	return float(num)/float(den);
}

// Input/output ---------------------------------
void Rational::write(std::ostream& os) const {
 	os<< num<<"/"<<den; 
}

void Rational::read(std::istream& is) {
	is >> num;
	is.ignore(1);
	is >> den;
}



