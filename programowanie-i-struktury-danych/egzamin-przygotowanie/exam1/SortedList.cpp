#include<iostream>
#include "SortedList.h"

template<class T>
SortedList<T>::~SortedList()
{
	Node* it = head, * destr = nullptr;

	while (it != nullptr) {
		destr = it;
		it = it->next;
		delete destr;
		destr = nullptr;
	}
}

template<class T>
void SortedList<T>::print() const
{
	Node* it = head;
	while (it != nullptr) {
		std::cout << it->value << " ";
		it = it->next;
	}
}

template<class T>
T SortedList<T>::pop_front()
{
	if(size < 1) {
		throw std::out_of_range("List empty");
	}

	Node* destr = nullptr;
	T first_element = head->value;

	destr = head;
	head = head->next;
	delete destr;
	destr = nullptr;
	size--;

	return first_element;
}

template<class T>
void SortedList<T>::insert(const T& new_el)
{
	Node* creator = new Node(new_el), * pred = nullptr, * succ = head;

	while (succ != nullptr && creator->value < succ->value) {
		pred = succ;
		succ = succ->next;
	}

	if (pred == nullptr) {
		head = creator;
	}
	else {
		pred->next = creator;
	}
	creator->next = succ;
	size++;
}

template<class T>
size_t SortedList<T>::get_size() const {
	return size;
}