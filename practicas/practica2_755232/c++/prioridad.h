//*****************************************************************
// File:    prioridad.h
// Author:  Diego Marco Beisty 755232
// Date:    01-04-2020
// Coms:    interfaz modulo prioridad
//*****************************************************************

#include "nodo.h"
class Prioridad
{
private:
  Nodo* n;
public:
  Prioridad(Nodo* n_= nullptr);

  //Devuelve false si this->n es de tipo ramaSuma o ramaResta
  //Devuelve true en caso contrario
  bool tienePrioridad();
};
