#ifndef Vector_hpp__
#define Vector_hpp__

#include "vector_class.h"
#include <iostream>

template<typename T>
Vector<T>::Vector()
{
    v_size = 0;
    v_capacity = 0;
    v_arr = nullptr;
}

template<typename T>
Vector<T>::Vector(SizeType n)
	:v_size(n)
	,v_capacity(n)
{
    v_arr = new T[v_capacity];
}

template<typename T>
Vector<T>::Vector(SizeType n, const T& val)
{
    v_size = n;
    v_capacity = n;
    v_arr = new T[v_capacity];

    for(SizeType i = 0; i < n; ++i)
        v_arr[i] = val;
}

template<typename T>
Vector<T>::Vector(const Vector<T>& rhv)
{
	this->v_size = rhv.v_size;
	this->v_capacity = rhv.v_capacity;
	this->v_arr = new T[this->v_capacity];

	for(SizeType i = 0; i < v_size;++i){
		v_arr[i] = rhv.v_arr[i];
	}
}
template<typename T>
Vector<T>::Vector(Vector<T>&& other) 
: v_size(other.v_size)
, v_capacity(other.v_capacity)
, v_arr(other.v_arr) 
{
    
    other.v_arr = nullptr;  
    other.v_size = 0;
    other.v_capacity = 0;
}


template<typename T>
const Vector<T>& Vector<T>::operator=(const Vector<T>& rhv){
	if(this != &rhv){
		delete[] v_arr;

		v_size = rhv.v_size;
		v_capacity = rhv.v_capacity;
		v_arr = new T[v_capacity];

		for(SizeType i = 0; i < v_size; ++i){
			v_arr[i] = rhv.v_arr[i];
		}
	}
	return *this;
}
template<typename T>
const Vector<T>& Vector<T>::operator=( Vector <T>&& rhv){
	if(this!=&rhv){
	this->clear();
	v_size = rhv.v_size;
	v_ capacity = rhv.v_capacity;
	v_arr = rhv.v_arr;
	rhv.v_arr = nullptr;
	}
	return *this;
}
template<typename T>
Vector<T>::~Vector()
{
   delete[] v_arr;
    v_arr = nullptr;
    v_size = 0;
}

template<typename T>
T& Vector<T>::front()
{
    return v_arr[0];
}

template<typename T>
T& Vector<T>::back()
{
    return v_arr[v_size - 1];
}

template<typename T>
T& Vector<T>::at(SizeType index)
{
	return v_arr[index];
}

template<typename T>
void Vector<T>::realloc_vect()
{
    T* tmp = new T[v_capacity];

    for(SizeType i = 0; i < v_size; ++i)
        tmp[i] = v_arr[i];

    delete[ ] v_arr;
    v_arr = tmp;
}

template<typename T>
void Vector<T>::push_back(ConstReference v)
{
    if(v_size == v_capacity){
        realloc_vect();
    }
    v_arr[v_size] = v;
    ++v_size;
}
template<typename T>
void Vector<T>::push_front(ValueType v)
{
    if(v_size == v_capacity){
        realloc_vect();
    }
    
    for (SizeType i = v_size; i > 0; --i) {
        v_arr[i] = v_arr[i - 1];
    }

    v_arr[0] = v;
    ++v_size;
}


template<typename T>
void Vector<T>::pop_back()
{
    --v_size;
}

template<typename T>
void  Vector<T>::clear()
{
    delete[] v_arr;
    v_arr = nullptr;
    v_size = 0;
}

template<typename T>
bool Vector<T>::empty(){
	if(v_size  == 0){
		return true;
	}
	return false;
}

template<typename T>
void Vector<T>::print(){
	for(size_t i = 0; i < v_size; ++i){
		std::cout<< v_arr[i] << " ";
	}
	std::cout << "\n";
}

template<typename T>
void Vector<T>::resize(SizeType n)
{
    if(n > v_capacity)
    {
        v_capacity = n;
        realloc_vect();
    }

    v_size = n;
}

template<typename T>
void Vector<T>::resize(SizeType n, const T& v)
{
    if(n > v_capacity)
    {
        v_capacity = n;
        realloc_vect();
    }

    if(n > v_size)
    {
        for(int i = v_size; i < n; ++i)
            v_arr[i] = v;
    }

    v_size = n;
}

template<typename T>
void Vector<T>::remove(SizeType index) {
    if (index >= v_size) {
        return;
    }
    
    T* tmp = new T[v_size - 1];

    for (SizeType i = 0; i < index; ++i) {
        tmp[i] = v_arr[i];
    }

    for (SizeType i = index + 1; i < v_size; ++i) {
        tmp[i - 1] = v_arr[i];
    }
    --v_size;
    delete[] v_arr;
    v_arr = tmp;
}

template <typename T>
void Vector<T>::insert(SizeType index, T val) {
    if (index > v_size) {
        return;
    }
    if (v_size == v_capacity) {
        realloc_vect();
    }

    ++v_size;
    T* tmp = new T[v_capacity];

    for (SizeType i = 0; i < index; ++i) {
        tmp[i] = v_arr[i];
    }
    tmp[index] = val;

    for (SizeType i = index + 1; i < v_size; ++i) {
        tmp[i] = v_arr[i - 1];
    }
    delete[] v_arr;
    v_arr = tmp;
}

#endif
