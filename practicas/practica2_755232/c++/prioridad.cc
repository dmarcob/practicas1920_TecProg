#include "prioridad.h"
#include "ramaSuma.h"
#include "ramaResta.h"

Prioridad::Prioridad(Nodo* n_) : n(n_) {}

bool Prioridad::tienePrioridad()
{
  bool prio = (dynamic_cast<RamaResta*>(n) ||
  dynamic_cast<RamaSuma*>(n)) ? false : true;

  return prio;
}
