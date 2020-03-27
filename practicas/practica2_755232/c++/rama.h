#pragma once
#include "nodo.h"

class Rama : public Nodo
{
protected:
  Nodo* i;
  Nodo* d;
public:
  Rama(Nodo* i_, Nodo* d_);

};
