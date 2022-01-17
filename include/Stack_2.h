// Copyright 2021 Dan10022002 dan10022002@mail.ru

#ifndef TEMPLATE_STACK_2_H
#define TEMPLATE_STACK_2_H

#include <utility>

template <typename T>
class Node_2{
 public:
  T _data;
  Node_2* _prev = nullptr;
  Node_2(){
    _prev = nullptr;
  }
};

template <typename T>
class Stack_2{
  Node_2<T>* _end = nullptr;
 public:
  Stack_2();
  Stack_2(Stack_2<T>&& obj) noexcept;
  Stack_2& operator=(Stack_2&& obj) noexcept;
  Stack_2(const Stack_2<T>& obj) = delete;
  Stack_2& operator=(const Stack_2&& obj) = delete;
  ~Stack_2();
  template <typename ... Args>
  void push_emplace(Args&&... data);
  void push (T&& data);
  const T& head() const;
  T pop();
};

#endif //TEMPLATE_STACK_2_H
