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
		cin >>a >> op >> b;
		switch(op)
		{
			case '+': r = a+b; break;
			case '-': r = a-b; break;
			case '*': r = a*b; break;
			case '/': r = a/b; break;
			default:  r = Rational(0,0);
		}
		cout << "= " << r << endl;
	}

	return 0;
}

