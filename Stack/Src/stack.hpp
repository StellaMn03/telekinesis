#ifndef Stack_hpp_
#define Stack_hpp_

#include <iostream>
#include "stack.h"
template<typename T,typename Container>
Stack<T,Container>::Stack()
:ob{}
{}

template<typename T, typename Container>
Stack<T, Container>::Stack(std::initializer_list<T> initList)
 : ob(initList)
  {}

template<typename T, typename Container>
Stack<T, Container>::Stack(Stack<T, Container>&& rhv)
: ob(std::move(rhv.ob))
{}


template<typename T , typename Container>
const Stack<T,Container>& Stack<T,Container>::operator=(const Stack& rhv){
    if (this != &rhv){
        
          for (const T& val : rhv){
              ob = rhv.ob;
          }
    }
     return *this; 
}

template<typename T , typename Container>
const Stack<T,Container>& Stack<T,Container>::operator=(Stack&& rhv){
        if (this != &rhv){
              for (const T& val : rhv){
                ob = std::move(rhv.ob);
            }
        }
    return *this; 
}

template<typename T,typename Container>
typename Stack<T,Container>:: Reference Stack<T,Container>::top(){
 return ob.back();

}

template<typename T,typename Container>
void Stack<T,Container>::pop(){
 ob.pop_back();
}
template<typename T,typename Container>
void Stack<T,Container>::push(ConstReference el){
 ob.push_back(el);
}
template<typename T,typename Container>
typename Stack<T,Container>:: SizeType Stack<T,Container>::size_s(){
 return ob.size();
}
template<typename T,typename Container>
bool Stack<T,Container>::empty_s(){
 return ob.empty();
}
template<typename T,typename Container>
Stack<T,Container>::Stack(const Stack<T,Container>& rhv)
: ob(rhv.ob){}

template<typename T,typename Container>
void Stack<T,Container>::swap(Stack<T,Container>& el1)
{
	ob.swap(el1.ob);
}
template<typename T,typename Container>
Stack<T,Container>::~Stack()
{}


template<typename T, typename Container>
bool operator<(Stack<T, Container>& ob1, Stack<T, Container>& ob2) {
    if (ob1.size_s() != ob2.size_s())
        return ob1.size_s() < ob2.size_s();

    Stack<T, Container> temp1 = ob1;
    Stack<T, Container> temp2 = ob2;

    while (!temp1.empty_s() && !temp2.empty_s()) {
        if (temp1.top() != temp2.top())
            return temp1.top() < temp2.top();
        temp1.pop();
        temp2.pop();
    }

    // If all elements are equal, return false
    return false;
}

template<typename T, typename Container>
bool operator>(Stack<T, Container>& ob1, Stack<T, Container>& ob2) {
    if (ob1.size_s() != ob2.size_s())
        return ob1.size_s() > ob2.size_s();

    Stack<T, Container> temp1 = ob1;
    Stack<T, Container> temp2 = ob2;

    while (!temp1.empty_s() && !temp2.empty_s()) {
        if (temp1.top() != temp2.top())
            return temp1.top() > temp2.top(); 
        temp1.pop();
        temp2.pop();
    }

    // If all elements are equal, return false
    return false;
}

template<typename T, typename Container>
bool operator==(Stack<T, Container>& ob1, Stack<T, Container>& ob2) {
    if (ob1.size_s() != ob2.size_s())
        return false;

    Stack<T, Container> temp1 = ob1;
    Stack<T, Container> temp2 = ob2;

    while (!temp1.empty_s() && !temp2.empty_s()) {
        if (temp1.top() != temp2.top())
            return false;
        temp1.pop();
        temp2.pop();
    }

    // If all elements are equal, return true
    return true;
}

template<typename T, typename Container>
bool operator!=(Stack<T, Container>& ob1,Stack<T, Container>& ob2) {
    if (ob1.size_s() != ob2.size_s())
        return true;

    Stack<T, Container> temp1 = ob1;
    Stack<T, Container> temp2 = ob2;

    while (!temp1.empty_s() && !temp2.empty_s()) {
        if (temp1.top() != temp2.top())
            return true;
        temp1.pop();
        temp2.pop();
    }

    // If all elements are equal, return false
    return false;
}

template<typename T, typename Container>
bool operator>=(Stack<T, Container>& ob1, Stack<T, Container>& ob2) {
    if (ob1.size_s() != ob2.size_s())
        return ob1.size_s() >= ob2.size_s();

    Stack<T, Container> temp1 = ob1;
    Stack<T, Container> temp2 = ob2;

    while (!temp1.empty_s() && !temp2.empty_s()) {
        if (temp1.top() != temp2.top())
            return temp1.top() >= temp2.top(); 
        temp1.pop();
        temp2.pop();
    }

    // If all elements are equal, return true
    return true;
}

template<typename T, typename Container>
bool operator<=(Stack<T, Container>& ob1, Stack<T, Container>& ob2) {
    if (ob1.size_s() != ob2.size_s())
        return ob1.size_s() <= ob2.size_s();

    Stack<T, Container> temp1 = ob1;
    Stack<T, Container> temp2 = ob2;

    while (!temp1.empty_s() && !temp2.empty_s()) {
        if (temp1.top() != temp2.top())
            return temp1.top() <= temp2.top();
        temp1.pop();
        temp2.pop();
    }

    // If all elements are equal, return true
    return true;
}


#endif
