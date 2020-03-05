#include <iostream>
#include "cuenta_corriente.hpp"
#include "plazo_fijo.hpp"

double total(Cuenta** cuentas, int n, int t)
{
  double total;
  for (int i = 0; i < n; i++)
  {
    total += cuentas[i]->valor(t);
  }
  return total;
}
int main () {
  Cuenta *cuentas[4];
  cuentas[0] = new CuentaCorriente(100, 0.2);
  cuentas[1] = new CuentaCorriente(100, 0.2);
  cuentas[2] = new PlazoFijo(100, 0.5, 3);
  double resul = total(cuentas, 3, 5);
  std::cout << resul << std::endl;

  return 0;
}
