#include "sznur.h"
#include<iostream>

void sznur::wypisz() const
{
	for (Node* it = head; it != nullptr; it = it->next) {
		std::cout << it->value << " ";
	}
	std::cout << "\n";
}

void sznur::wstaw(const int& new_el)
{
	Node* creator = new Node(new_el);
	Node* pred = nullptr, * succ = head;
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

void usun(sznur& sznur)
{
	sznur::Node* pred = nullptr, * succ = sznur.head;
	while (succ != nullptr && succ->next != nullptr && succ->next->next != nullptr) {
		sznur::Node* first = succ, * second = first->next, * third = second->next;
		succ = third->next;

		if (first->value - second->value == 1) {
			// remove first
			if (pred == nullptr) {
				sznur.head = second;
			}
			else {
				pred->next = second;
			}
			delete first;
			first = nullptr;
			sznur.size--;
			pred = third;
		}
		else {
			// remove first and third
			if (pred == nullptr) {
				sznur.head = second;
			}
			else {
				pred->next = second;
			}
			second->next = succ;
			delete first, third;
			first = nullptr;
			third = nullptr;
			sznur.size -= 2;
			pred = second;
		}
	}
}
