#include "ForwardList.h"
#ifndef Forward_List_hpp
#define Forward_List_hpp
#include<iostream>

template <typename T>
Forward_list<T>::Forward_list()
	:head(nullptr)
{}

template <typename T>
Forward_list<T>::Forward_list(Forward_list<T>&& rhv)
	:head{rhv.head}
{
	rhv.head=nullptr;
}

template<typename T>
Forward_list<T>::~Forward_list() {
	clear();
}
template<typename T>
Forward_list<T>::Forward_list(const Forward_list<T>& other)
	:head(nullptr)
{
	
 if(other.head == nullptr){
	 return;
 }

Node<value_type>* otherPtr = other.head;
while( otherPtr != nullptr){
	push_back(otherPtr->data);
	otherPtr = otherPtr->next;
      }
 }

template<typename T>
Forward_list<T>& Forward_list<T>::operator=(const Forward_list<T>& rhv){
	if(this != &rhv){
		clear();
	Node<value_type>* rhvPtr  = rhv.head;
    	while(rhvPtr != nullptr){
	    	push_back(rhvPtr->data);
	    	rhvPtr = rhvPtr->next;
       }  
	}
	return *this;
}
template <typename T>
Forward_list<T>& Forward_list<T>::operator=(Forward_list<T>&& rhv){
	if(this != &rhv){
		this->clear();
		head = rhv.head;
		rhv.head = nullptr;
	}
	return *this;
}
template <typename T>
void Forward_list<T>::clear() {
	while(head != nullptr){
		Node<value_type>* ptr = head;
		head = head->next;
		delete ptr;
	}
}
template <typename T>
void Forward_list<T>::display() {
	Node<value_type>* ptr = head;
	while(ptr != nullptr){
		std::cout<< ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
}
template<typename T>
void Forward_list<T>::empty() {
	if(head == nullptr) {

		std::cout<< "List is empty"<< std::endl;;
}

	else 
    { 
		std::cout<< "List is not empty" << std::endl;;
	}
}
template <typename T>
void Forward_list<T>::pop_back(){

	if(head == nullptr) {
		return;
	}
	else if(head->next == nullptr)
	{
		delete head;
		head=nullptr;
	}
	else
	{
		Node<value_type>* ptr = head;
		while(ptr->next->next!=nullptr){
			ptr = ptr->next;
		}
		delete ptr->next;
		ptr->next = nullptr;
	}
	return;
}
template<typename T>
void Forward_list<T>::push_back(const_referance rhv){
	Node<value_type>* temp = new Node<value_type>;
	temp->data = rhv;
	temp->next = nullptr;
	if(head == nullptr){
		head = temp;
	}
	else
	{
		Node<value_type>* ptr = head;
    	while(ptr->next != nullptr){
	    	ptr = ptr->next;
    	}
    	ptr->next = temp;
	}
}

template <typename T>
void Forward_list<T>::push_front(const_referance rhv){
	Node<value_type>* newNode = new Node<value_type>;
	newNode->data = rhv;
	newNode->next = head;
	head = newNode;
}
template <typename T>
void Forward_list<T>::pop_front(){
	if(head==nullptr){
		return;
	}
	else
	{
	Node<value_type>* first = head;
	head = head->next;
	delete first ;
	}
return ;
}
template <typename T>
void Forward_list<T>::insert(size_type position ,const_referance rhv){
	Node<value_type>* newNode = new Node<value_type>;
	newNode->data = rhv;
	newNode->next = nullptr;
	Node<value_type>* tmp = head;
	position--;
	while(position != 1){
		tmp = tmp->next;
		position--;
	}
	newNode->next = tmp->next;
	tmp->next = newNode;
}
template <typename T>
void Forward_list<T>::remove(const_referance value){
	 if (head == nullptr) {
            return;
        }  
     if (head->data == value) { 
            Node<value_type>* temp = head;
            head = head->next;
            delete temp;
            return;
	 }
        Node<value_type>* prev = nullptr;
        Node<value_type>* current = head;
     while (current != nullptr && current->data != value) {
            prev = current; //keep previous node
            current = current->next;
        }

        if (current == nullptr) {  //if the value isn`t find
                 return;
        }

        prev->next = current->next;
        delete current;
    }

#endif
