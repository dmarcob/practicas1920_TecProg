#include "excepcion.h"

arbol_ficheros_error::arbol_ficheros_error(string error_) :
      runtime_error(error_), error(error_) {}

existe_nodo_insertar_error::existe_nodo_insertar_error() : arbol_ficheros_error("El nodo ya existe") {}


const char* arbol_ficheros_error::what() const throw()
{
  return this->error.c_str();
}
