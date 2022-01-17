// Copyright 2021 Dan10022002 dan10022002@mail.ru

#include <gtest/gtest.h>

#include "Stack_1.h"
#include "./../sources/Stack_1.cpp"
#include "Stack_2.h"
#include "./../sources/Stack_2.cpp"

template <typename T>
class smart_pointer{
  T* _data;
 public:
  smart_pointer(){
    _data = nullptr;
  }
  explicit smart_pointer(T* ptr){
    _data = ptr;
  }
  smart_pointer(const smart_pointer<T>& other) = delete;
  smart_pointer(smart_pointer<T>&& other) noexcept {
    _data = other._data;
    other._data = nullptr;
  }
  smart_pointer& operator=(const smart_pointer& other) = delete;
  smart_pointer& operator=(smart_pointer&& other) noexcept{
    if (&other != this){
      _data = other._data;
      other._data = nullptr;
    }
    return *this;
  }
  T& operator*() const{
    return *_data;
  }
  ~smart_pointer(){
    delete _data;
  }
};

template class Stack_1<int>;
template class Stack_2<smart_pointer<int>>;

TEST(Stack_1_Methods, push){
  Stack_1<int> st;
  st.push(10);
  ASSERT_EQ(10, st.head());
}

TEST(Stack_1_Methods, push_with_params){
  Stack_1<int> st;
  int a = 10;
  st.push(a);
  ASSERT_EQ(10, st.head());
}

TEST(Stack_1_Methods, pop){
  Stack_1<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.pop();
  ASSERT_EQ(20, st.head());
}

TEST(Stack_1_Constructors, copy){
  ASSERT_FALSE(std::is_copy_constructible<Stack_1<int>>::value);
}

TEST(Stack_1_Constructors, move){
  ASSERT_TRUE(std::is_move_constructible<Stack_1<int>>::value);
  Stack_1<int> st1;
  st1.push(10);
  Stack_1<int> st2(std::move(st1));
  ASSERT_EQ(10, st2.head());
}

TEST(Stack_1_Operators, copy){
  ASSERT_FALSE(std::is_copy_assignable<Stack_1<int>>::value);
}

TEST(Stack_1_Operators, move){
  ASSERT_TRUE(std::is_move_assignable<Stack_1<int>>::value);
  Stack_1<int> st1;
  st1.push(10);
  Stack_1<int> st2;
  st2 = std::move(st1);
  ASSERT_EQ(10, st2.head());
}

TEST(Stack_2_Methods, push){
  Stack_2<smart_pointer<int>> st;
  smart_pointer<int> ptr(new int(10));
  st.push(std::move(ptr));
  ASSERT_EQ(10, *(st.head()));
}

TEST(Stack_2_Methods, push_emplace){
  Stack_2<smart_pointer<int>> st;
  smart_pointer<int> ptr1 (new int(10));
  st.push_emplace<smart_pointer<int>>(std::move(ptr1));
  ASSERT_EQ(10, *(st.head()));
}

TEST(Stack_2_Methods, pop){
  Stack_2<smart_pointer<int>> st;
  st.push(smart_pointer<int> (new int(10)));
  st.push(smart_pointer<int> (new int(20)));
  st.push(smart_pointer<int> (new int(30)));
  st.pop();
  ASSERT_EQ(20, *(st.head()));
}

TEST(Stack_2_Constructors, copy){
  ASSERT_FALSE(std::is_copy_constructible<Stack_2<smart_pointer<int>>>::value);
}

TEST(Stack_2_Constructors, move){
  ASSERT_TRUE(std::is_move_constructible<Stack_2<smart_pointer<int>>>::value);
  Stack_2<smart_pointer<int>> st1;
  st1.push(smart_pointer<int> (new int(10)));
  Stack_2<smart_pointer<int>> st2(std::move(st1));
  ASSERT_EQ(10, *(st2.head()));
}

TEST(Stack_2_Operators, copy){
  ASSERT_FALSE(std::is_copy_assignable<Stack_2<smart_pointer<int>>>::value);
}

TEST(Stack_2_Operators, move){
  ASSERT_TRUE(std::is_move_assignable<Stack_2<smart_pointer<int>>>::value);
  Stack_2<smart_pointer<int>> st1;
  st1.push(smart_pointer<int> (new int(10)));
  Stack_2<smart_pointer<int>> st2;
  st2 = std::move(st1);
  ASSERT_EQ(10, *(st2.head()));
}
