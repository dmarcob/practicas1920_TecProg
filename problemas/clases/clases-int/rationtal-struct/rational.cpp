#include <iostream>
#include "rational.hpp"

int mcd(int i1, int i2) {
	if(i2 == 0){
		return i1;	
	}
	return mcd(i2, i1%i2);
}

void simplificar(Rational& r) {
	int m = mcd(r.n, r.d);
	
	r.n = r.n / m;
	r.d = r.d / m;
}
Rational rational(int a, int b) {
	Rational r;
	r.n = a; r.d = b;
	simplificar(r);
	return r;
}
Rational suma(Rational r1, Rational r2) {
	return rational((r1.n*r2.d) + (r2.n*r1.d), r1.d*r2.d);
}
Rational suma(int i, Rational r) {
	return rational(r.n + (i*r.d), r.d);
}
Rational suma(Rational r, int i) {
	Rational resul;
	resul.n = r.n + (i*r.d);
	resul.d = r.d;
	simplificar(resul);
	return resul;
}

void mostrar(Rational r, std::ostream& os) {
	os << r.n << " / " << r.d << std::endl;
}
void leer(Rational& r, std::istream& is) {
	int n, d;
	char dummy;
	is >> n >> dummy >> d;
	r = rational(n, d);
}
