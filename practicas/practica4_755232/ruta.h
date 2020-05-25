//*****************************************************************
// File:    ruta.h
// Author:  Diego Marco Beisty 755232
// Date:    26-04-2020
// Coms:
//*****************************************************************
#pragma once

#include <string>
#include <vector>
#include "nodo.h"
#include "directorio.h"
#include "fichero.h"
#include "enlace.h"
#include "excepcion.h"


class Ruta {
private:
  vector <Directorio*> rutaActiva; //Ruta activa del usuario
  //Devuelve true si nombre no contiene los caracteres
  // ' ' ni '/', devuelve false en caso contrario
  bool nombreCorrecto(const string& nombre);

  //Devuelve true si vPath contiene nombres de directorios que
  //corresponden con directorios creados en el mismo orden que en
  //vPath. Además devuelve un vector con punteros a los mismos.
  //En caso contrario devuelve false
  bool existePath(vector<string>vPath, vector<Directorio*>& ruta, bool absoluto);

  //Devuelve true si path es absoluto y false en caso contrario
  //Además procesa los directorios especiales "." ".." de path
  bool procesarPath(const string& path, vector<string>& vPath);

  void procesarPathRec(vector<string>& vPath, int indice);
public:
  //Construye la ruta activa a partir del directorio raiz_
  Ruta(Directorio raiz_);

  //Devuelve la ruta completa de forma textual, con todos los
  //nombres de los directorios desde la raiz hasta el direcotrio
  //actual concatenados y separados por el separador "/"
  string pwd();

  //Devuelve un listado con el nombre de todos los nodos contenidos
  //en la ruta actual, uno por línea.
  string ls();

  //Devuelve un listado con el nombre y el tamaño de todos los nodos contenidos en la ruta actual, uno por línea
  string du();

  //Cambia la ruta a otro directorio. El path representa un directorio
  void cd(const string& path);

  //Devuelve el tamaño del nodo al que referencia el path
  //En caso de no existir el path, devuelve -1
  int stat(string path);

  //Cambia el valor del tamaño del fichero especificado "name"
  //(en el directorio actual) al tamaño indicado en "size"
  //Si el fichero no existe, se crea uno nuevo con el nombre y tamaño especificados.
  void vi(string name, int size);

  //Crea un directorio dentro de la ruta actual
  void mkdir(const string& name);

 //Crea en el directorio actual un enlace simbolico de nombre
 //"name" que apunta al elemento identificado mediante el nombre
 //"path".
   void ln(string path, string name);

  //Elimina un nodo. Si es un fichero, es simplemente eliminado.
  //Si es un enlace, elimina el en lace pero no el nodo referenciado. Si es un directorio, elimina el directorio y todo su contenido. Si existen enlaces al elemento borrado, ese elemento sigue siendo accesible a traves del enlace, pero no a traves de su nodo original.
  void rm(string path);

};
