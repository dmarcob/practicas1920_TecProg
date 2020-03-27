#include "vmp.h"
class bicielectrica : public vmp
{
private:
  int bate;
public:
  bicielectrica(int id_, double x_, double y_, int bate_, bool disponible_=true, bool libre_=true);

  bool bateria(int& resultado)override;
  bool esbici()override;
};
