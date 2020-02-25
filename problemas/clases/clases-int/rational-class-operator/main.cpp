#include "rational.hpp"

int main() {

	Rational a(4, 3);
	a.mostrar();
	Rational b(3, 4);
    b.mostrar();
	
	Rational resul = a.suma(b);
	resul.mostrar();
	
	
	Rational c;
	c.leer();
	c.mostrar();


}
