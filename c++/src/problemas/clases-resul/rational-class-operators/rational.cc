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
Rational& Rational::operator+=(const Rational& that) {
	this->num = this->num*that.den + this->den*that.num;
	this->den *= that.den;
	reduce();
    return (*this);
}

Rational& Rational::operator+=(int i) {
	this->num += i*this->den;
	reduce();
    return (*this);
}

Rational Rational::operator+(const Rational& that) const {
	Rational sol(*this); return sol+=that;
};

Rational Rational::operator+(int i) const {
	Rational sol(*this); return sol+=i;
};

Rational operator+(int i, const Rational& r) {
   return r + i;
}

// Substract -----------------------
Rational& Rational::operator-=(const Rational& that) {
	this->num = this->num*that.den - this->den*that.num;
	this->den *= that.den;
	reduce();
    return (*this);
}

Rational& Rational::operator-=(int i) {
	this->num -= i*this->den;
	reduce();
    return (*this);
}

Rational Rational::operator-(const Rational& that) const {
	Rational sol(*this); return sol-=that;
};

Rational Rational::operator-(int i) const {
	Rational sol(*this); return sol-=i;
};

Rational operator-(int i, const Rational& r) {
   return Rational(i) - r;
}

// Multiply -------------------------
Rational& Rational::operator*=(const Rational& that) {
	this->num *= that.num;
	this->den *= that.den;
	reduce();
    return (*this);
}

Rational& Rational::operator*=(int i) {
	this->num *= i;
	reduce();
    return (*this);
}

Rational Rational::operator*(const Rational& that) const {
	Rational sol(*this); return sol*=that;
};

Rational Rational::operator*(int i) const {
	Rational sol(*this); return sol*=i;
};

Rational operator*(int i, const Rational& r) {
   return r * i;
}


// Divide ------------------------------
Rational& Rational::operator/=(const Rational& that) {
	this->num *= that.den;
	this->den *= that.num;
	reduce();
    return (*this);
}

Rational& Rational::operator/=(int i) {
	this->den *= i;
	reduce();
    return (*this);
}

Rational Rational::operator/(const Rational& that) const {
	Rational sol(*this); return sol/=that;
};

Rational Rational::operator/(int i) const {
	Rational sol(*this); return sol/=i;
};

Rational operator/(int i, const Rational& r) {
   return Rational(i)/r;
}


// Helper function ------------------------------
float Rational::value()  const {
	return float(num)/float(den);
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



