#include <iostream>
#ifndef Vector_H__
#define Vector_H__

template<typename T>
class Vector
{
    size_t  v_size;
    size_t  v_capacity;
	T* v_arr;
    void realloc_vect();
public:
   using ValueType = T;
   using SizeType = std::size_t;
   using Reference = ValueType&;
   using ConstReference = const ValueType&;
   using Pointer = ValueType*;
   using ConstPointer = const ValueType*;

public:
    Vector();
    Vector(SizeType n);
    Vector(SizeType n, const T&);
    Vector(const Vector<T>&);
    Vector(Vector<T>&& other);

    ~Vector();
    const Vector<T>& operator=(const Vector<T>&);
    const Vector <T>& operator=(Vector <T>&& rhv);
    T& front();
    T& back();
    T& at(SizeType);
    void push_back(ConstReference);
    void push_front(ValueType);
    void pop_back();
    void clear();
    bool empty();
    void print();
    void resize(SizeType);
    void resize(SizeType, const T&);
    void remove(SizeType);
    void insert(SizeType, ValueType);
	
};

#include "vector_class.hpp"
#endif

