// Copyright 2021 Dan10022002 dan10022002@mail.ru

#include "Stack_1.h"

template <typename T>
Stack_1<T>::Stack_1(){
    _end = nullptr;
}

template <typename T>
void deleter(Node_1<T>* obj){
  if (obj != nullptr){
    deleter(obj->_prev);
  }
  delete obj;
}

template <typename T>
Stack_1<T>::~Stack_1(){
  deleter(_end);
  _end = nullptr;
}

template <typename T>
Stack_1<T>::Stack_1(Stack_1&& obj) noexcept{
  _end = obj._end;
  obj._end = nullptr;
}

template <typename T>
Stack_1<T>& Stack_1<T>::operator=(Stack_1<T>&& obj) noexcept {
  if (this != &obj){
    _end = obj._end;
    obj._end = nullptr;
  }
  return *this;
}

template <typename T>
void Stack_1<T>::push(T&& data) {
  Node_1<T>* tmp = new Node_1<T>;
  tmp->_data = std::move(data);
  tmp->_prev = _end;
  _end = tmp;
}

template <typename T>
void Stack_1<T>::push(const T& data) {
  Node_1<T>* tmp = new Node_1<T>;
  tmp->_data = data;
  tmp->_prev = _end;
  _end = tmp;
}

template <typename T>
void Stack_1<T>::pop() {
  Node_1<T>* tmp;
  tmp = _end;
  _end = _end->_prev;
  delete tmp;
}

template <typename T>
const T& Stack_1<T>::head() const{
  return _end->_data;
}
