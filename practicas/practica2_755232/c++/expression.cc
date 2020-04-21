//*****************************************************************
// File:    expression.cc
// Author:  Diego Marco Beisty 755232
// Date:    01-04-2020
// Coms:    implementacion modulo expression
//*****************************************************************

#include <iostream>
#include <sstream>
#include <stack>
#include "expression.h"
#include "symboltab.h"
#include "hojaConstante.h"
#include "hojaVariable.h"
#include "rama.h"
#include "ramaSuma.h"
#include "ramaResta.h"
#include "prioridad.h"
#include "ramaMult.h"
#include "ramaDivi.h"

using namespace std;

void Expression::parse(const string& s)
{
	istringstream ss(s);
	string tok;

	// Pila de términos
	// Consulta el tipo de datos 'stack' de la STL
	stack<Nodo*>stk;

	while (ss >> tok)
	{
		if (tok=="+")
		{
			// Apilar suma
			Nodo* der = stk.top(); stk.pop();
			Nodo* izq = stk.top(); stk.pop();
			stk.push(new RamaSuma(izq, der));
		}
		else if (tok=="-")
		{
			// Apilar resta
			Nodo* der = stk.top(); stk.pop();
			Nodo* izq = stk.top(); stk.pop();
			stk.push(new RamaResta(izq, der));
		}
		else if (tok=="*")
		{
			// Apilar producto
			Nodo* der = stk.top(); stk.pop();
			Nodo* izq = stk.top(); stk.pop();
			stk.push(new RamaMult(izq, der));
		}
		else if (tok=="/")
		{
			// Apilar cociente
			Nodo* der = stk.top(); stk.pop();
			Nodo* izq = stk.top(); stk.pop();
			stk.push(new RamaDivi(izq, der));
		}
		else
		{
			// Variable o constante
			// Si comienza por un caracter no numerico,
			// es un nombre de variable
			if (isalpha(tok[0]))
			{
				// Apilar variable
				stk.push(new HojaVariable(tok));
			}
			else
			{
				float f = stof(tok);
				// Apilar constante
				stk.push(new HojaConstante(f));

			}
		}
	}

	root = stk.top();// cima de la pila
}


Expression::Expression(const string& rpn)
{
	parse(rpn);
}

float Expression::eval(const SymbolTab& syms) const
{
	// Devuelve el resultado de evaluar la expresion
	return root->eval(syms);
}

string Expression::to_string() const
{
	// Devuelve la cadena que representa la expresion
	return root->to_string();
}

ostream& operator<<(ostream& os,const Expression& e)
{
    os << e.to_string();

    return os;
}
