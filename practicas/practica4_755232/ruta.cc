//*****************************************************************
// File:    ruta.cc
// Author:  Diego Marco Beisty 755232
// Date:    26-04-2020
// Coms:
//*****************************************************************
#include "ruta.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Ruta::Ruta(Directorio raiz_) {
   rutaActiva.push_back(new Directorio(raiz_.nombre()));
}


bool Ruta::nombreCorrecto(const string& nombre) {
  if (nombre.find('/') == string::npos
      and  nombre.find(' ') == string::npos) {
          return true;
  } else {
    cout << "ERROR nombre incorrecto" << nombre << ", incluir EXCEPCION aqui" << endl;
    return false;
  }
}

bool Ruta::existePath(vector<string>vPath, vector<Directorio*>& ruta, bool absoluto) {
  int indice; //Desde donde compruebo rutaActiva
  Nodo* nodo; //Nodo candidato a existir en rutaActiva
  Directorio* dir; //Nodo confirmado a existir en rutaActiva
  bool existeNodo;
  (absoluto) ? indice = 0 : indice = rutaActiva.size() - 1;
  dir = rutaActiva[indice]; //Directorio inicial segun path absoluto.
  for(string& i : vPath) {
    if(dir->existe(i, nodo) and dynamic_cast<Directorio*>(nodo)) {
        //Nodo existe y es directorio
        dir = dynamic_cast<Directorio*>(nodo);
        ruta.push_back(dir);
    } else {
        cout << "EXCEPCION AQUI, PATH NO EXISTE" << endl;
        return false;
    }
  }
  return true;
}


void Ruta::procesarPathRec(vector<string>& vPath, int indice) {
  if (indice <= int(vPath.size() - 1)) {
    if (vPath[indice] == ".") {
      vPath.erase(vPath.begin() + indice);
      procesarPathRec(vPath, indice);
    }
    else if (vPath[indice] == "..") {
      if (indice > 0) {
        vPath.erase(vPath.begin() + indice - 1);
        vPath.erase(vPath.begin() + indice - 1);
        procesarPathRec(vPath, indice - 1);
      } else {
        //indice == 0
        vPath.erase(vPath.begin());
        vector<string> vAux;
        for (int i = 1; i <= int(rutaActiva.size() - 2); i++) {
            vAux.push_back(rutaActiva[i]->nombre());
        }
        vAux.insert(vAux.end(),vPath.begin(),vPath.end());
        vPath = vAux;
        procesarPathRec(vPath, vAux.size());
      }
    }
    else {
      procesarPathRec(vPath, indice + 1);
    }
  }
}


bool Ruta::procesarPath(const string& path, vector<string>& vPath) {

  bool absoluto = false;
  stringstream ss(path); string dir;
  while(getline(ss, dir, '/')) {
    vPath.push_back(dir);
  }
  if (vPath[0].empty()) {
    vPath.erase(vPath.begin());
    absoluto = true;
  }
  procesarPathRec(vPath, 0);
  return absoluto;
}



string Ruta::pwd() {
  string str;
  //Caso directorio actual = directorio raiz
  if (rutaActiva.size() == 1) str.append("/");
  //Caso directorio raiz != directorio raiz
  for (int i = 1; i <= rutaActiva.size() - 1; i++) {
    str.append("/" + rutaActiva[i]->nombre());
  }
  return str;
}

string Ruta::ls() {
  return rutaActiva[rutaActiva.size() - 1]->listarNom();
}

string Ruta::du() {
  return rutaActiva[rutaActiva.size() - 1]->listarNomTam();
}

int Ruta::stat(string path) {
  vector<string> vPath;
  vector<Directorio*>ruta;
  Nodo* nodo;
  int tamano = -1; //Por defecto tamaño incorrecto
  bool absoluto = procesarPath(path, vPath);
  string name = vPath[vPath.size() - 1]; //Nombre nodo
  vPath.pop_back();
  if (existePath(vPath,ruta, absoluto)) {
      //Caso existe el path
      if (ruta[ruta.size() - 1] -> existe(name,nodo)) {
        //Caso existe el nodo del que se quiere obtener el tamaño
        tamano = nodo -> tamano();
      } else {
        cout << "NO EXISTE EL NODO" << endl;
      }
  } else {
    //Si no existe el path saco excepción
    cout << "NO EXISTE EL PATH"<< endl;
  }
  return tamano;
}

void Ruta::cd(const string& path) {
  vector<string> vPath;
  vector<Directorio*>ruta;
  //Proceso los "." y ".." del path
  bool absoluto = procesarPath(path, vPath);
  //Compruebo que el path exista
  if (existePath(vPath,ruta, absoluto)) {
    if (absoluto) {
      //Si path absoluto actualizo directorios desde la raiz
      rutaActiva.erase(rutaActiva.begin() + 1, rutaActiva.end());
    }
    //Añado los nuevos directorios a la ruta activa
    rutaActiva.insert(rutaActiva.end(), ruta.begin(), ruta.end());
  } else {
    //Si no existe el path saco excepción
    cout << "NO EXISTE EL PATH"<< endl;
  }
}

void Ruta::vi(string name, int size) {
  Nodo* nodo;
  Fichero* fich;
  if (rutaActiva[rutaActiva.size() - 1] -> existe(name, nodo)) {
    //Caso existe el nodo, se modifica su tamaño
    if (fich = dynamic_cast<Fichero*>(nodo)) {
        fich -> actualizarTam(size);
    } else{
      cout << "EXCEPCION, NO ES UN FICHERO" << endl;
    }
  } else {
    //Caso no existe el nodo, se crea uno
    rutaActiva[rutaActiva.size() - 1] -> insertar(new Fichero(name, size));
  }
}


void Ruta::mkdir(const string& name) {
  if (nombreCorrecto(name)) {
    //EXCEPCION interna si name ya existe en el dir actual
    rutaActiva[rutaActiva.size()-1]->insertar( new Directorio(name));
  }
}

void Ruta::ln(string path, string name) {
  //EXCEPCION Interna si name existe en directorio actual
  if (nombreCorrecto(name)) {
    vector<string> vPath;
    vector<Directorio*>ruta;
    Nodo* ptnodo;
    //Proceso los "." y ".." del path
    bool absoluto = procesarPath(path, vPath); //Segmento el path
    string nodo = vPath[vPath.size() - 1]; //guardo el nodo
    vPath.pop_back(); //Elimino el ultimo elemento
    if (existePath(vPath,ruta, absoluto)) {
        if (ruta[ruta.size() - 1]->existe(nodo,ptnodo)) {
          rutaActiva[rutaActiva.size() - 1]->insertar(new Enlace<Nodo>(name,ptnodo));
        } else {
          //EXCEPCION el nodo de path no existe
        }
    } else {
      //EXCEPCION path no existe
    }
  }
}

void Ruta::rm(string path) {
  vector<string> vPath;
  vector<Directorio*>ruta;
  Nodo* ptnodo;
  bool absoluto = procesarPath(path, vPath);
  string nodo = vPath[vPath.size() - 1]; //guardo el nodo
  vPath.pop_back(); //Elimino el ultimo elemento
  if (existePath(vPath,ruta, absoluto)) {

    if (ruta[ruta.size() - 1]->existe(nodo,ptnodo)) {

      ruta[ruta.size() - 1]->eliminar(ptnodo);
    } else {
      //EXCEPCION el nodo de path no existe
    }
  } else {
    //EXCEPCION el path no existe
  }
}
