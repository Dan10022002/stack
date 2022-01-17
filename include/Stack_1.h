// Copyright 2021 Dan10022002 dan10022002@mail.ru

#ifndef TEMPLATE_STACK_1_H
#define TEMPLATE_STACK_1_H

#include <utility>

template <typename T>
class Node_1{
 public:
  T _data;
  Node_1* _prev = nullptr;
  Node_1(){
    _prev = nullptr;
  }
};

template <typename T>
class Stack_1{
  Node_1<T>* _end = nullptr;
 public:
  Stack_1();
  Stack_1(Stack_1<T>&& obj) noexcept;
  Stack_1& operator=(Stack_1&& obj) noexcept;
  Stack_1(const Stack_1<T>& obj) = delete;
  Stack_1& operator=(const Stack_1&& obj) = delete;
  ~Stack_1();
  void push(T&& data);
  void push(const T& data);
  void pop();
  const T& head() const;
};

#endif //TEMPLATE_STACK_1_H
