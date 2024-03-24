#ifndef Vector_hpp_
#define Vector_hpp_

#include <iostream>
#include "queue.h"
template<typename T,typename Container>
Queue<T,Container>::Queue()
:ob{}
{}

template<typename T, typename Container>
Queue<T, Container>::Queue(std::initializer_list<T> initList)
 : ob(initList)
  {}

template<typename T, typename Container>
Queue<T, Container>::Queue(Queue<T, Container>&& rhv)
: ob(std::move(rhv.ob))
{}

template<typename T , typename Container>
const Queue<T,Container>& Queue<T,Container>::operator=(const Queue& rhv){
    if (this != &rhv){
          for (const T& val : rhv){
              ob = rhv.ob;
          }
    }
     return *this; 
}

template<typename T , typename Container>
const Queue<T,Container>& Queue<T,Container>::operator=(Queue&& rhv){
        if (this != &rhv){
              for (const T& val : rhv){
                ob = std::move(rhv.ob);
            }
        }
    return *this; 
}

template<typename T,typename Container>
typename Queue<T,Container>:: Reference Queue<T,Container>::front_q(){
 return ob.front();
}


template<typename T,typename Container>
void Queue<T,Container>::pop(){
 ob.erase(ob.begin());
}
template<typename T,typename Container>
void Queue<T,Container>::push(ConstReference el){
 ob.push_back(el);
}
template<typename T,typename Container>
typename Queue<T,Container>:: SizeType Queue<T,Container>::size_q(){
 return ob.size();
}
template<typename T,typename Container>
bool Queue<T,Container>::empty_q(){
 return ob.empty();
}
template<typename T,typename Container>
Queue<T,Container>::Queue(const Queue<T,Container>& rhv)
: ob(rhv.ob){}

template<typename T,typename Container>
void Queue<T,Container>::swap(Queue<T,Container>& el1)
{
	ob.swap(el1.ob);
}
template<typename T,typename Container>
Queue<T,Container>::~Queue()
{}

template<typename T, typename Container>
bool operator<(Queue<T, Container>& ob1, Queue<T, Container>& ob2) {
    if (ob1.size_q() != ob2.size_q())
        return ob1.size_q() < ob2.size_q();

    Queue<T, Container> temp1 = ob1;
    Queue<T, Container> temp2 = ob2;

    while (!temp1.empty_q() && !temp2.empty_q()) {
        if (temp1.front_q() != temp2.front_q())
            return temp1.front_q() < temp2.front_q();
        temp1.pop();
        temp2.pop();
    }

    // If all elements are equal, return false
    return false;
}

template<typename T, typename Container>
bool operator>(Queue<T, Container>& ob1,Queue<T, Container>& ob2) {
    if (ob1.size_q() != ob2.size_q())
        return ob1.size_q() > ob2.size_q();

    Queue<T, Container> temp1 = ob1;
    Queue<T, Container> temp2 = ob2;

    while (!temp1.empty_q() && !temp2.empty_q()) {
        if (temp1.front_q() != temp2.front_q())
            return temp1.front_q() > temp2.front_q();
        temp1.pop();
        temp2.pop();
    }

    // If all elements are equal, return false
    return false;
}

template<typename T, typename Container>
bool operator==(Queue<T, Container>& ob1, Queue<T, Container>& ob2) {
    if (ob1.size_q() != ob2.size_q())
        return false;

    Queue<T, Container> temp1 = ob1;
    Queue<T, Container> temp2 = ob2;

    while (!temp1.empty_q() && !temp2.empty_q()) {
        if (temp1.front_q() != temp2.front_q())
            return false;
        temp1.pop();
        temp2.pop();
    }

    // If all elements are equal, return true
    return true;
}

template<typename T, typename Container>
bool operator!=(Queue<T, Container>& ob1,Queue<T, Container>& ob2) {
    if (ob1.size_q() != ob2.size_q())
        return true;

    Queue<T, Container> temp1 = ob1;
    Queue<T, Container> temp2 = ob2;

    while (!temp1.empty_q() && !temp2.empty_q()) {
        if (temp1.front_q() != temp2.front_q())
            return true;
        temp1.pop();
        temp2.pop();
    }

    // If all elements are equal, return false
    return false;
}

template<typename T, typename Container>
bool operator>=(Queue<T, Container>& ob1,Queue<T, Container>& ob2) {
    if (ob1.size_q() != ob2.size_q())
        return ob1.size_q() >= ob2.size_q();

    Queue<T, Container> temp1 = ob1;
    Queue<T, Container> temp2 = ob2;

    while (!temp1.empty_q() && !temp2.empty_q()) {
        if (temp1.front_q() != temp2.front_q())
            return temp1.front_q() >= temp2.front_q();
        temp1.pop();
        temp2.pop();
    }

    // If all elements are equal, return true
    return true;
}

template<typename T, typename Container>
bool operator<=(Queue<T, Container>& ob1, Queue<T, Container>& ob2) {
    if (ob1.size_q() != ob2.size_q())
        return ob1.size_q() <= ob2.size_q();

    Queue<T, Container> temp1 = ob1;
    Queue<T, Container> temp2 = ob2;

    while (!temp1.empty_q() && !temp2.empty_q()) {
        if (temp1.front_q() != temp2.front_q())
            return temp1.front_q() <= temp2.front_q();
        temp1.pop();
        temp2.pop();
    }

    // If all elements are equal, return true
    return true;
}


#endif
