#pragma once
/*
  int id
  double x
  double y
  bool disponible
  bool libre

  metodos setter getter
*/
class vmp {
protected:
  int id;
  double x, y;
  bool disponible, libre;
public:

  vmp(int id_, double x_, double y_, bool disponible_=true, bool libre_=true);
  int get_id();
  void get_coordenadas(double& x_, double& y);
  void set_bloquear();
  virtual bool bateria(int& resultado) = 0;
  virtual bool esbici() = 0;
};
