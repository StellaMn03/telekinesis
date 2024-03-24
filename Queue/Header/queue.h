#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <vector>
#include <initializer_list>

template<typename T, typename Container = std::vector<T>>
class Queue {
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
    Queue();
    Queue(std::initializer_list<T> initList);
    Queue(const Queue<T, Container>& rhv);
    const Queue<T,Container>& operator=(Queue&& rhv);
    Queue(Queue&& rhv);
    const Queue<T,Container>& operator=(const Queue& rhv);
    ~Queue();

    Reference front_q();
    void pop();
    void push(ConstReference el);
    SizeType size_q();
    void swap(Queue<T, Container>& other);
    bool empty_q();
};


template<typename T, typename Container>
bool operator==(Queue<T, Container>& ob1,Queue<T, Container>& ob2);

template<typename T, typename Container>
bool operator!=(Queue<T, Container>& ob1, Queue<T, Container>& ob2);

template<typename T, typename Container>
bool operator>(Queue<T, Container>& ob1, Queue<T, Container>& ob2);

template<typename T, typename Container>
bool operator<(Queue<T, Container>& ob1, Queue<T, Container>& ob2);

template<typename T, typename Container>
bool operator>=(Queue<T, Container>& ob1, Queue<T, Container>& ob2);

template<typename T, typename Container>
bool operator<=(Queue<T, Container>& ob1, Queue<T, Container>& ob2);

#include "queue.hpp"

#endif // QUEUE_HPP_

