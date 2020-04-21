//*****************************************************************
// File:    expression.h
// Author:  Diego Marco Beisty 755232
// Date:    01-04-2020
// Coms:    interfaz modulo expression
//*****************************************************************

#pragma once

#include <iostream>
#include "nodo.h"

class Expression
{
private:
	// Raiz del arbol de terminos
	Nodo* root;

	void	parse(const string& s);

	string to_string() const;

public:
	// Constructores
	Expression(const string& rpn = "");

	float	eval(const SymbolTab& syms) const;

	friend ostream& operator<<(ostream& os,const Expression& e);
};

ostream& operator<<(ostream& os,const Expression& e);
