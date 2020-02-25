#include "rational.h"
#include <iostream>

using namespace std;

int main()
{
	Rational	a,b,r;
	char		op;

	while (true)
	{
		cout << "? " << flush;
		a.read();
		cin >> op;
		b.read();
		switch(op)
		{
			case '+': r = a.add(b);       break;
			case '-': r = a.substract(b); break;
			case '*': r = a.multiply(b);  break;
			case '/': r = a.divide(b);    break;
			default:  r = Rational(0,0);
		}
		cout << "= "; r.write(); cout << endl;
	}

	return 0;
}

