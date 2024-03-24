#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<vector>
#include <initializer_list>
template<typename T,typename Container =std::vector<T>>

class Stack{
 private:
 Container ob;
 public:
   using ValueType = T;
   using SizeType = std::size_t;
   using Reference = ValueType&;
   using ConstReference = const ValueType&;
   using Pointer = ValueType*;
   using ConstPointer = const ValueType*;
public:
 Stack();
 Stack(std::initializer_list<T> initList);
 Stack(const Stack<T,Container>& rhv);
 const Stack<T,Container>& operator=(Stack&& rhv);
 Stack(Stack&& rhv);
 const Stack<T,Container>& operator=(const Stack& rhv);
 ~Stack();
 
 Reference top();
 void pop();
 void push(ConstReference el);
 SizeType  size_s();
 void swap(Stack<T,Container>&);
 bool empty_s();
};

template<typename T, typename Container>
bool operator==(Stack<T, Container>& ob1,Stack<T, Container>& ob2);

template<typename T, typename Container>
bool operator!=(Stack<T, Container>& ob1, Stack<T, Container>& ob2);

template<typename T, typename Container>
bool operator>(Stack<T, Container>& ob1, Stack<T, Container>& ob2);

template<typename T, typename Container>
bool operator<(Stack<T, Container>& ob1, Stack<T, Container>& ob2);

template<typename T, typename Container>
bool operator>=(Stack<T, Container>& ob1, Stack<T, Container>& ob2);

template<typename T, typename Container>
bool operator<=(Stack<T, Container>& ob1, Stack<T, Container>& ob2);


#include "stack.hpp"
#endif //STACK_H
