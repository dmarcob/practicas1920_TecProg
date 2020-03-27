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
