//*****************************************************************
// File:    directorio.h
// Author:  Diego Marco Beisty 755232
// Date:    26-04-2020
// Coms:
//*****************************************************************
#pragma once
#include <map>
#include "nodo.h"
typedef map<string, Nodo*> ContenidoDir;
class Directorio : public Nodo {
private:
  ContenidoDir contenido;
public:
  //Constuctor.
  Directorio(const string& name);
  //Añade un nodo al directorio (fichero , directorio o enlace)
  bool insertar(Nodo* n);
  //Elimina todos los nodos del directorio
  void vaciar();
  //Elimina el nodo n del directorio
  bool eliminar(Nodo* n);
  //Devuelve los nombres de todos los nodos contenidos en el
  //directorio a razón de un nodo por línea
  string listarNom() const;
  //Devuelve los nombres y tamaño de todos los nodos contenidos en
  //el directorio a razón de uno por línea
  string listarNomTam() const;
};
