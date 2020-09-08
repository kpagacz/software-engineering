#include "List.h"

#include<stdexcept>

template<class T>
List<T>::~List()
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
int List<T>::size() const
{
	return size_;
}

template<class T>
void List<T>::insert(const T& new_el)
{
	Node* creator = new Node(new_el);
	
	if (tail == nullptr) {
		head = creator;
	}
	else {
		tail->next = creator;
	}
	tail = creator;

	size_++;
}

template<class T>
T List<T>::pop_front()
{
	if (size_ < 1) {
		throw std::runtime_error("List empty");
	}

	T to_return = head->value;
	Node* destr = head;
	head = head->next;
	delete destr;
	destr = nullptr;

	size_--;
	return to_return;
}