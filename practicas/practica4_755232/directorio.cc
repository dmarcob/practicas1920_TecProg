//*****************************************************************
// File:    directorio.cc
// Author:  Diego Marco Beisty 755232
// Date:    26-04-2020
// Coms:
//*****************************************************************
#include "directorio.h"
#include <sstream>
#include <iostream>

Directorio::Directorio(const string& name_) : Nodo(name_, 0) {
}

bool Directorio::insertar(Nodo* n) {
  ContenidoDir::const_iterator it = contenido.find(n->nombre());
  if (it == contenido.end()) {
    //Caso el nodo a insertar no existe
    contenido.insert(pair<string, Nodo*>(n->nombre(), n));
    this->size += n->tamano();
    return true;
  } else {
    cout << n->nombre()<< " ya existe en directorio: AÑADIR EXCEPCIÓN AQUÍ"<< endl;
    return false;
  }
}


void Directorio::vaciar() {
  //Elimina todos los elementos del directorio
  ContenidoDir::const_iterator it;
  for (it = contenido.begin(); it != contenido.end(); it++) {
    if (Directorio* d = dynamic_cast<Directorio*>(it->second)) {
      //Es un directorio, borro primero su interior
      d->vaciar();
    }
    delete it->second;
    contenido.erase(it->first);
  }
}


bool Directorio::eliminar(Nodo* n) {
  ContenidoDir::const_iterator it = contenido.find(n->nombre());
  if (it != contenido.end()) {
      if (Directorio* d = dynamic_cast<Directorio*>(n)) {
        //Es un directorio, borro primero su interior
        d->vaciar();
      }
      //Elimino mem dinamica del nodo
      this->size -= it->second->tamano();
      delete it->second;
      contenido.erase(it->first);
  } else {
    cout << n->nombre()<< " no existe, no se borrara: AÑADIR EXCEPCIÓN AQUÍ"<< endl;
  }
}


string Directorio::listarNom() const {
  ContenidoDir::const_iterator it;
  string str;
  for (it = contenido.begin(); it != contenido.end(); it++) {
      str.append(it->first + "\n");
  }
  return str;
}

string Directorio::listarNomTam() const {
  ostringstream oss;
  ContenidoDir::const_iterator it;
  for (it = contenido.begin(); it != contenido.end(); it++) {
      oss << it->first << " " << it->second->tamano() << " B" << endl;
  }
  return oss.str();
}
