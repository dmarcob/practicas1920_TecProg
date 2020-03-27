#include "vmp.h"
class bici : public vmp
{
  bici(int id_, double x_, double y_, bool disponible_=true, bool libre_=true);

  bool bateria(int& resultado)override;
  bool esbici()override;
};
