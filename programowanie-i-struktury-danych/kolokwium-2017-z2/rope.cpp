#include <iostream>
#include "rope.h"

Rope::~Rope()
{
	Node* it = head, * destr = nullptr;
	while (it != nullptr) {
		destr = it;
		it = it->next;
		delete destr;
		destr = nullptr;
	}
}

void Rope::print() const
{
	for (Node* it = head; it != nullptr; it = it->next) {
		std::cout << it->value << " ";
	}

	std::cout << "\n";
}

void Rope::insert(const int& el)
{
	Node* creator = new Node(el), * pred = nullptr, * succ = head;

	while (succ != nullptr && creator->value > succ->value) {
		pred = succ;
		succ = succ->next;
	}

	if (head == nullptr) {
		head = creator;
	}
	else {
		if (pred != nullptr) {
			pred->next = creator;
		}
		else {
			head = creator;
		}
		creator->next = succ;
	}

	size++;
}

void Rope::funny_remove()
{
	Node* succ = head, * pred = nullptr, * destr = nullptr;

	while (succ != nullptr && succ->next != nullptr && succ->next->next != nullptr && succ->next->next->next != nullptr) {
		Node* first = succ, * second = first->next, * third = second->next, * fourth = third->next;
		succ = fourth->next;

		if (third->value % first->value == 0 && third->value % second->value == 0) {
			// remove all 4 nodes
			if (pred == nullptr) {
				head = succ;
			}
			else {
				pred->next = succ;
			}

			delete first, second, third, fourth;
			first = nullptr;
			second = nullptr;
			third = nullptr;
			fourth = nullptr;

			size = size - 4;
		}
		else {
			// remove only fourth
			pred = third;
			pred->next = succ;
			delete fourth;
			fourth = nullptr;
			size--;
		}
	}
}

void Rope::moveWithStep(const int& K)
{
	Node* pred = nullptr, * succ = head, * to_head_begin = nullptr, * to_head_end = nullptr, * to_tail_begin = nullptr, * to_tail_end = nullptr, * mover = nullptr;
	bool to_head = true;

	while (succ != nullptr) {
		int value = K - 1;
		while (succ != nullptr && value > 0) {
			pred = succ;
			succ = succ->next;
			value--;
		}

		if (succ == nullptr) continue;

		mover = succ;
		succ = succ->next;
		if (pred != nullptr) {
			pred->next = succ;
		}
		else {
			head = succ;
		}

		if (to_head) {
			// to head
			if (to_head_begin == nullptr) {
				to_head_begin = mover;
				to_head_end = mover;
				to_head_end->next = nullptr;
			}
			else {
				mover->next = to_head_begin;
				to_head_begin = mover;
			}
		}
		else {
			// to tail
			if (to_tail_begin == nullptr) {
				to_tail_begin = mover;
				to_tail_end = mover;
				to_tail_end->next = nullptr;
			}
			else {
				mover->next = to_tail_begin;
				to_tail_begin = mover;
			}
		}

		to_head = !to_head;
	}



	if (to_head_begin != nullptr) {
		if (head == nullptr) {
			head = to_head_begin;
		}
		else {
			to_head_end->next = head;
			head = to_head_begin;
		}
	}

	if (to_tail_begin != nullptr) {
		// find tail
		Node* tail = nullptr, * it = head;
		while (it != nullptr) {
			tail = it;
			it = it->next;
		}

		if (tail == nullptr) {
			head = to_tail_begin;
		}
		else {
			tail->next = to_tail_begin;
		}
	}
}

void Rope::exchangeGroups(Rope& other)
{
	Node* this_succ = head, * this_pred = nullptr, * other_succ = other.head, * other_pred = nullptr;
	Node* to_this_begin = nullptr, * to_this_end = nullptr, * to_other_begin = nullptr, * to_other_end = nullptr;

	int counter = 0;
	int to_this_size = 1;
	int to_other_size = 1;

	while (this_succ != nullptr && other_succ != nullptr) {
		// finding longest in this
		to_other_begin = this_succ;
		to_other_end = this_succ;
		this_succ = this_succ->next;

		while (this_succ != nullptr && this_succ->value == to_other_end->value) {
			to_other_end = this_succ;
			this_succ = this_succ->next;
			to_other_size++;
		}

		// finding longest in other
		to_this_begin = other_succ;
		to_this_end = other_succ;
		other_succ = other_succ->next;

		while (other_succ != nullptr && other_succ->value == to_this_end->value) {
			to_this_end = other_succ;
			other_succ = other_succ->next;
			to_this_size++;
		}

		// exchange
		if (counter == 0) {
			if (this_pred == nullptr) {
				head = to_this_begin;
			}
			else {
				this_pred->next = to_this_begin;
			}

			this_pred = to_this_end;
			this_pred->next = this_succ;


			if (other_pred == nullptr) {
				other.head = to_other_begin;
			}
			else {
				other_pred->next = to_other_begin;
			}

			other_pred = to_other_end;
			other_pred->next = other_succ;

			counter = 1;

			size = size + to_this_size - to_other_size;
			other.size = other.size + to_other_size - to_this_size;
		}
		else {
			this_pred = to_other_end;
			other_pred = to_this_end;
			counter--;
		}

		to_this_size = 1;
		to_other_size = 1;
	}
}