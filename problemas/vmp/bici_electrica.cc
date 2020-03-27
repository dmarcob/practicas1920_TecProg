#include "bici_electrica.h"

bicielectrica::bicielectrica(int id_, double x_, double y_, int bate_, bool disponible_, bool libre_) :
vmp(id_, x_, y_, disponible, libre), bate(bate_) {}

bool bicielectrica::bateria(int& resultado)
{
  resultado = this->bate;
  return true;
}
bool bicielectrica::esbici()
{
  return true; //es bici
}
