#include "vmp.h"

vmp::vmp(int id_, double x_, double y_, bool disponible_, bool libre_) :
  id(id_), x(x_), y(y_), disponible(disponible_), libre(libre_){}

int vmp::get_id()
{
  return this->id;
}
void vmp::get_coordenadas(double& x_, double& y_)
{
  x_ = this-> x;
  y_ = this-> y;
}
void vmp::set_bloquear()
{
  this-> disponible = false;
}
