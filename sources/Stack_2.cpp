// Copyright 2021 Dan10022002 dan10022002@mail.ru

#include "Stack_2.h"

template <typename T>
Stack_2<T>::Stack_2(){
  _end = nullptr;
}

template <typename T>
void deleter(Node_2<T>* obj){
  if (obj != nullptr){
    deleter(obj->_prev);
  }
  delete obj;
}

template <typename T>
Stack_2<T>::~Stack_2(){
  deleter(_end);
  _end = nullptr;
}

template <typename T>
Stack_2<T>::Stack_2(Stack_2&& obj) noexcept{
  _end = obj._end;
  obj._end = nullptr;
}

template <typename T>
Stack_2<T>& Stack_2<T>::operator=(Stack_2<T>&& obj) noexcept {
  if (this != &obj){
    _end = obj._end;
    obj._end = nullptr;
  }
  return *this;
}

template <typename T>
template <typename ...Args>
void Stack_2<T>::push_emplace(Args&&... data) {
  Node_2<T>* tmp = new Node_2<T>;
  tmp->_data = std::move(data ...);
  tmp->_prev = _end;
  _end = tmp;
}

template <typename T>
void Stack_2<T>::push(T&& data) {
  Node_2<T>* tmp = new Node_2<T>;
  tmp->_data = std::move(data);
  tmp->_prev = _end;
  _end = tmp;
}

template <typename T>
const T& Stack_2<T>::head() const{
  return _end->_data;
}

template <typename T>
T Stack_2<T>::pop() {
  Node_2<T>* tmp;
  tmp = _end;
  _end = _end->_prev;
  T rez = std::move(tmp->_data);
  delete tmp;
  return rez;
}
