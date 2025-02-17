//*****************************************************************
// File:    main-static-stack-struct.cc
// Author:  Enunciado práctica 1, tecnología de la programación.
// Date:    08-03-2020
// Coms:    Módulo principal de uso de pila estática con structs
//*****************************************************************
#include "static-stack-struct.h"
#include <iostream>

int main(int argc,char* argv[])
{
	static_stack<int> ss;

	init(ss);
	push(ss, 42);
	push(ss, 15);
	pop(ss);
	for (int i = 0; i < 100; i+=5)
		push(ss, i);

	startIterator(ss);
	bool error = false;
	while(hasNext(ss) && (!error))
	{
		std::cout<<next(ss, error)<<" ";
	}
	std::cout<<std::endl;

	return 0;
}
