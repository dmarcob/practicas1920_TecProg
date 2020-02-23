#include <iostream>
#include "rational.hpp"

//funciones


Rational suma(int i,const Rational& r) {
     Rational resul;
     resul = r.suma(i);
     return resul;
}

void Rational::leer(std::istream& is) {
    char dummy;
	is >> n >> dummy >> d;
}



//metodos
int Rational::mcd(int i1, int i2) {
    return (i2 == 0? i1: mcd(i2, i1%i2));
}

void Rational::simplificar() {
	int m = mcd(n, d);
	n = n / m; d = d / m;
}
Rational::Rational(int a, int b): n(a), d(b) {
	simplificar();
}
Rational Rational::suma(const Rational& r2) const {
    
	Rational resul((n*r2.d) + (r2.n*d), d*r2.d);
	return resul;
}

Rational Rational::suma(int i) const{
	return suma(Rational(i));
}

void Rational::mostrar(std::ostream& os) const{
	os << n << " / " << d << std::endl;
}

