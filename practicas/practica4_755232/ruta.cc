//*****************************************************************
// File:    ruta.cc
// Author:  Diego Marco Beisty 755232
// Date:    26-04-2020
// Coms:
//*****************************************************************
#include "ruta.h"
#include <iostream>
using namespace std;

Ruta::Ruta(Directorio raiz_) {
   rutaActiva.push_back(&raiz_);
   //cout << rutaActiva[0]->nombre() << endl;
   //cout << rutaActiva.size() << endl;
}
