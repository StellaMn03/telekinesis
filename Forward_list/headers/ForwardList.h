#include<iostream>
#ifndef Forward_List_h_
#define Forward_List_h_
 template <typename T>
    struct Node {
        T data;
        Node<T>* next;
    };

template <typename T>
class Forward_list{
	private:
	 Node<T>* head;
	public:
     using value_type = T;
     using size_type = std::size_t;
     using referance = value_type&;
     using const_referance = const value_type&;
     using pointer = value_type*;
     using const_pointer = const value_type*;
     public:
     Forward_list();
     Forward_list(Forward_list<T>&&);
     Forward_list(const Forward_list<T>&);
     Forward_list<T>& operator = (const Forward_list&);
     Forward_list<T>& operator=(Forward_list<T>&&);
     ~Forward_list();
     void clear();
     void display();
     void empty();
	 void pop_back();
     void push_back(const_referance);
     void push_front(const_referance);
     void pop_front();
     void insert(size_type, const_referance);
     void remove(const_referance);
};

#include "ForwardList.hpp"
#endif
