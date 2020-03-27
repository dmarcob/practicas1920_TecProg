#include "bici.h"

bici::bici(int id_, double x_, double y_, bool disponible_, bool libre_) :
vmp(id_, x_, y_, disponible, libre) {}

bool bici::bateria(int& resultado)
{
  return false; //no es electrica
}
bool bici::esbici()
{
  return true; //es bici
}
