//*****************************************************************
// File:    dynamic-stack.h
// Author:  Diego Marco Beisty 755232
// Date:    08-03-2020
// Coms:    Fichero interfaz e implementación pila dinámica genérica
//*****************************************************************
#pragma once
#include <iostream>
using namespace std;

template<typename T>
class dynamic_stack
{
private:
  //Subclase a la que solo se puede acceder desde dynamic_stack
  class node
  {
  private:
    T dato;
    node* next; //Puntero al siguiente nodo, nullptr si es el primer nodo almacenado
  public:
    node(const T& dato_,  node* next_): dato(dato_), next(next_) {}
    //Declaro friend a dynamic_stack para que pueda acceder directamente a los atributos de node.
    //Otra opción sería establecer métodos getter y setter en clase node
    friend class dynamic_stack;
  };

  node* head; //Puntero al último elemento almacenado de la pila

public:
  //Inicialmente pila vacía
  dynamic_stack(): head(nullptr) {}


  //Método bool en vez de void para mantener la misma funcionalidad que
  //la clase static_stack al aplicar polimorfismo paramétrico en main.cc
  bool push(const T& e)
  {
    this->head = new node(e, head);
    return true; //Ninguna restricción de espacio en memoria dinámica
  }

  bool pop()
  {
    if(this->head != nullptr)
    {
      node* aux = head;
      this->head = head->next;
      delete aux;
      return true;
    }
    return false;
  }
  //Declaro friend a const_iterator para que pueda acceder directamente a los
  //atributos privados de dynamic_stack
  friend class const_iterator;


  class const_iterator
  {
  private:
    //const dynamic_stack<T>& dtk;
    node* iter;
  public:
    const_iterator(/*const dynamic_stack& dtk_, */node* iter_)
    : /*dtk(dtk_),*/
     iter(iter_) {}

    const_iterator& operator++()
    {
      bool avanzar = this->iter != nullptr;
      if (avanzar)
      {
        iter=iter->next;
      }
      return (*this);
    }

    const T& operator*() const
    {
      return iter->dato;
    }

    bool operator!=(const const_iterator &that) const
    {
      return this->iter != that.iter;
    }

  };

  const_iterator begin() const
  {
    return const_iterator(/**this,*/ this->head);
  }

  const_iterator end() const
  {
    return const_iterator(/**this,*/ nullptr);
  }

};
