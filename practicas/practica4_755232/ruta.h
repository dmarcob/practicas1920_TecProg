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

//TODO: GESTIONAR NOMBRES SIN ESPACIOS NI "/"
//TODO: GESTIONAR NOMBRES ESPECIALES . Y ..

class Ruta {
private:
  vector <Directorio*> rutaActiva;
public:
  //Construye la ruta activa a partir del directorio raiz_
  Ruta(Directorio raiz_);

  //Devuelve la ruta completa de forma textual, con todos los
  //nombres de los directorios desde la raiz hasta el direcotrio
  //actual concatenados y separados por el separador "/"
//  string pwd();

  //Devuelve un listado con el nombre de todos los nodos contenidos
  //en la ruta actual, uno por línea.
//  string ls();

  //Devuelve un listado con el nombre y el tamaño de todos los nodos contenidos en la ruta actual, uno por línea
//  string du();

  //Cambia la ruta a otro directorio. El path representa un directorio
//  void cd(string path);

  //Devuelve el tamaño del nodo al que referencia el path
//  int stat(string path);

  //Cambia el valor del tamaño del fichero especificado "name"
  //(en el directorio actual) al tamaño indicado en "size"
  //Si el fichero no existe, se crea uno nuevo con el nombre y tamaño especificados.
//  void vi(string name, int size);

  //Crea un directorio dentro de la ruta actual
//  void mkdir(string name);

 //Crea en el directorio actual un enlace simbolico de nombre
 //"name" que apunta al elemento identificado mediante el nombre
 //"path".
//  void ln(string path, string name);

  //Elimina un nodo. Si es un fichero, es simplemente eliminado.
  //Si es un enlace, elimina el en lace pero no el nodo referenciado. Si es un directorio, elimina el directorio y todo su contenido. Si existen enlaces al elemento borrado, ese elemento sigue siendo accesible a traves del enlace, pero no a traves de su nodo original.
//  void rm(string path);

};
