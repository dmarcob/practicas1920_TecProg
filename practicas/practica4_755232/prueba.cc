#include "nodo.h"
#include "directorio.h"
#include "ruta.h"
#include "enlace.h"
#include "fichero.h"
#include <iostream>

int main () {
  //Directorio* raiz = new Directorio("/");
  //cout << raiz.listarNom() << endl;
  /*Fichero* f1 = new Fichero("f1", 1);
  Directorio* otro = new Directorio("otro");
  Directorio* uno = new Directorio("uno");

  otro->insertar(f1);
  otro->insertar(uno);

  Fichero* f2 = new Fichero("f2", 2);
  raiz->insertar(otro);
  //raiz->insertar(f2);
  //cout << raiz->listarNomTam() << endl;
  cout << raiz->tamano() << endl;
  raiz->eliminar(otro);
  raiz->eliminar(f2);

  cout << raiz->tamano() << endl;*/
  /*Directorio raiz("/");
  //cout <<raiz.nombre() << endl;
  Enlace e1("enalceRaiz", &raiz);
  e1.actualizarTam(66);
  cout << e1.tamano() << endl;
  cout << raiz.tamano() << endl;*/
  Directorio raiz("caca");
	Ruta ruta(raiz);



  return 0;
}
