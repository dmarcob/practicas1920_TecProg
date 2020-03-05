#pragma once
 #include <iostream>
 using namespace std;

template<typename T>
class dynamic_stack
{
private:

  class node
  {
  private:
    T dato;
    node* next;
  public:
    node(const T& dato_,  node* next_): dato(dato_), next(next_) {}

    friend class dynamic_stack;

  };

  node* head;

public:
  dynamic_stack(): head(nullptr) {}

  bool push(const T& e)
  {
    this->head = new node(e, head);
    return true;
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

  friend class const_iterator;


  class const_iterator
  {
  private:
    const dynamic_stack<T>& dtk;
    node* iter;
  public:
    const_iterator(const dynamic_stack& dtk_, node* iter_) : dtk(dtk_),
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
    return const_iterator(*this, this->head);
  }

  const_iterator end() const
  {
    return const_iterator(*this, nullptr);
  }

};
