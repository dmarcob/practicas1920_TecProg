#pragma once
#include <stdexcept>
#include <string>
using namespace std;
class arbol_ficheros_error : public runtime_error {
protected:
  string error;
public:
  arbol_ficheros_error(string symbol_="");
  const char* what() const throw();
};

class existe_nodo_insertar_error : public arbol_ficheros_error {
public:
  existe_nodo_insertar_error();

};
