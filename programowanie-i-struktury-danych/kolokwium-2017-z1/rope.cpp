#include <iostream>

#include "rope.h"

void Rope::print() const
{
	for (Node* it = head; it != nullptr; it = it->next) {
		std::cout << it->value << " ";
	}
	std::cout << "\n";
}

void Rope::insert(const int& el)
{
	Node* pred = nullptr, * succ = head;
	Node* creator = new Node(el);

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

	creator->next = succ;
	size++;
}

void Rope::funny_remove(const unsigned int& M)
{
	if (size < M) {
		return;
	}

	float mean;
	int sum = 0;

	Node* it = head;
	for (int j = 0; j < M - 1; j++) {
		it = it->next;
	}
	sum += it->value;

	for (int i = 0; i < size / M - 1; i++) {
		for (int j = 0; j < M; j++) {
			it = it->next;
		}
		sum += it->value;
	}

	mean = 1.0 * sum / (size / M);

	Node* pred = nullptr, * succ = head;

	while (succ != nullptr) {
		if (succ->value > mean) {
			// remove node
			Node* destr = nullptr;
			destr = succ;
			succ = succ->next;
			if (pred == nullptr) {
				head = succ;
			}
			else {
				pred->next = succ;
			}
			delete destr;
			destr = nullptr;
			size--;
		}
		else {
			pred = succ;
			succ = succ->next;
		}

	}

}

void Rope::moveThrees()
{
	Node* succ = head, * pred = nullptr;
	Node* threes_begin = nullptr, * threes_end = nullptr;

	while (succ != nullptr && succ->next != nullptr && succ->next->next != nullptr) {
		Node* first = succ, * second = succ->next, * third = succ->next->next;
		succ = third->next;

		if (first->value != second->value && first->value != third->value && second->value != third->value) {
			// move the three to threes
			if (pred == nullptr) {
				head = succ;
			}
			else {
				pred->next = succ;
			}

			third->next = second;
			second->next = first;
			first->next = nullptr;
			if (threes_begin == nullptr) {
				threes_begin = third;
			}
			else {
				threes_end->next = third;
			}

			threes_end = first;
			threes_end->next = nullptr;
		}
		else {
			pred = third;
		}

	}

	// find tail
	Node* tail = nullptr, * it = head;
	while (it != nullptr) {
		tail = it;
		it = it->next;
	}

	// join threes
	if (threes_begin != nullptr) {
		if (head == nullptr) {
			head = threes_begin;
		} 
		else {
			tail->next = threes_begin;
		}
	}
}

void Rope::exchangePairs(Rope& other)
{
	Node* this_pred = nullptr, * this_succ = head, * other_pred = nullptr, * other_succ = other.head;

	bool exchange = false;
	while (this_succ != nullptr && this_succ->next != nullptr && other_succ->next != nullptr && other_succ != nullptr) {
		if (exchange) {
			// exchange pairs
			Node* this_first = this_succ, * this_second = this_succ->next, * other_first = other_succ, * other_second = other_succ->next;
			this_succ = this_second->next;
			other_succ = other_second->next;

			if (this_pred != nullptr) {
				this_pred->next = other_first;
			}
			else {
				head = other_first;
			}
			other_second->next = this_succ;

			if (other_pred != nullptr) {
				other_pred->next = this_first;
			}
			else {
				other.head = this_first;
			}
			this_second->next = other_succ;
		}
		else {
			// move forward
			this_pred = this_succ->next;
			this_succ = this_succ->next->next;

			other_pred = other_succ->next;
			other_succ = other_succ->next->next;
		}
		exchange = !exchange;
	}
}