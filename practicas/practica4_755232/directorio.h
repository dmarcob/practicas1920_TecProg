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
  void updateTam(); //Actualiza el tamaño de directorio
  //Elimina todos los nodos del directorio
  void vaciar();
public:
  //Constuctor.
  Directorio(const string& name);
  //Añade un nodo al directorio (fichero , directorio o enlace)
  bool insertar(Nodo* n);

  //Elimina el nodo n del directorio
  bool eliminar(Nodo* n);
  //Devuelve los nombres de todos los nodos contenidos en el
  //directorio a razón de un nodo por línea
  string listarNom() const;
  //Devuelve los nombres y tamaño de todos los nodos contenidos en
  //el directorio a razón de uno por línea
  string listarNomTam() const;
  //Si contiene un nodo de nombre "name", devuelve en nodo, un
  //puntero al nodo y devuelve true, en caso contrario devuelve
  //false y nodo queda indefinido.
  bool existe(const string& name, Nodo*& nodo);
};
