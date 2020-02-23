#include "rational.hpp"

int main() {

	Rational a = rational(4, 3);

	Rational b = rational(3, 4);
	mostrar(a);
	
	Rational resul = suma(3, a);
	mostrar(resul);
	
	Rational c;
	leer(c);
	mostrar(c);

}
