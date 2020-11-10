#include "Ciag.h"

#include<iostream>
#include<time.h>
#include<stdlib.h>

void Ciag::push(const int& new_el)
{
	Node* creator = new Node(new_el);

	Node* pred = nullptr, * succ = head;

	while (succ != nullptr) {
		pred = succ;
		succ = succ->next;
	}

	if (pred == nullptr) {
		head = creator;
	}
	else {
		pred->next = creator;
	}
	size++;
}

Ciag::Ciag(int size, int min, int max)
{
	srand(time(NULL));
	head = nullptr;

	for (int i = 0; i < size; i++) {
		int new_int = rand() % (max - min + 1) + min;
		push(new_int);
	}

	size = size;
}

Ciag::Ciag(const Ciag& other)
{
	Node* other_succ = other.head;
	size = 0;
	head = nullptr;

	while (other_succ != nullptr) {
		push(other_succ->value);
		other_succ = other_succ->next;
	}
}

Ciag::~Ciag()
{
	Node* destructor = nullptr, * succ = head;
	std::cout << "// usunieto ciag " << *this;

	while (succ != nullptr) {
		destructor = nullptr;
		succ = succ->next;

		delete destructor;
		destructor = nullptr;		
	}

}

Ciag& Ciag::operator++()
{
	push(0);

	return *this;
}

int& Ciag::operator[](int id)
{
	Node* it = head;

	while (it != nullptr && id > 0) {
		it = it->next;
		id--;
	}

	return it->value;
}

Ciag Ciag::operator++(int)
{
	Ciag temp = *this;
	++* this;
	return temp;
}

std::ostream& operator<<(std::ostream& out, const Ciag& ciag)
{
	std::cout << "(";
	Ciag::Node* it = ciag.head;
	for (int i = 0; i < int(ciag.size) - 1; i++) {
		std::cout << it->value << ",";
		it = it->next;
	}
	if (it != nullptr) {
		std::cout << it->value;
	}
	std::cout << ")";
	return out;
}
