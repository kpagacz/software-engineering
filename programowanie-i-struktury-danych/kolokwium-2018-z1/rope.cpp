#include <iostream>
#include "rope.h"

Rope::~Rope()
{
	Node* it=head, * destr = nullptr;
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

void Rope::insert(const int& new_el)
{
	Node* it = head,* pred = nullptr;
	Node* creator = new Node(new_el);

	while (it != nullptr) {
		if (creator->value < it->value) {
			pred = it;
			it = it->next;
		}
		else {
			break;
		}
	}
	if (head == nullptr) {
		head = creator;
	}
	else {
		if (pred == nullptr) {
			creator->next = head;
			head = creator;
		}
		else {
			pred->next = creator;
		}
	}
	creator->next = it;
	size++;
	return;
}

void Rope::funny_remove(const int& K)
{
	Node* succ = head, * pred = nullptr;

	while (succ != nullptr && succ->next != nullptr && succ->next->next != nullptr) {
		Node* first = succ, * second = succ->next, * third = succ->next->next;
		succ = third->next;

		float mean = (first->value + second->value + third->value) / 3;

		if (mean < K) {
			// remove first
			if (pred != nullptr) {
				pred->next = second;
			}
			else {
				head = second;
			}

			delete first;
			first = nullptr;
			size--;

			pred = third;
		}
		else {
			// remove second and third
			first->next = succ;
			delete second, third;
			second = nullptr;
			third = nullptr;
			size = size - 2;

			pred = first;
		}
	}
}

void Rope::funny_move()
{
	Node* pred = nullptr, * succ = head;
	Node* equal_begin = nullptr, * equal_end = nullptr, * different_begin = nullptr, * different_end = nullptr;

	while (succ != nullptr && succ->next != nullptr) {
		Node* first = succ, * second = succ->next;
		succ = second->next;

		if (first->value == second->value) {
			// move both - preserve order
			if (pred != nullptr) {
				pred->next = succ;
			}
			else {
				head = succ;
			}

			if (equal_begin == nullptr) {
				equal_begin = first;
				equal_end = second;
			}
			else {
				equal_end->next = first;
			}
			equal_end = second;
			equal_end->next = nullptr;
		}
		else {
			// move second - reverse order
			first->next = succ;

			if (different_begin == nullptr) {
				different_begin = second;
				different_end = second;
				different_end->next = nullptr;
			}
			else {
				second->next = different_begin;
				different_begin = second;
			}

			pred = first;
		}
	}

	// find tail
	Node* it = head, * tail = nullptr;
	while (it != nullptr) {
		tail = it;
		it = it->next;
	}

	if (head == nullptr) {
		if (equal_begin != nullptr) {
			head = equal_begin;
			equal_end->next = different_begin;
		}
	}
	else {
		if (equal_begin != nullptr) {
			equal_end->next = head;
			head = equal_begin;
		}

		tail->next = different_begin;
	}
}

void Rope::exchangeConstantVectors(Rope& other)
{
	Node* this_pred = nullptr, * this_succ = head, * other_pred = nullptr, * other_succ = other.head;

	while (this_succ != nullptr && other_succ != nullptr) {
		// find constant in this
		Node *this_constant_pred = nullptr, *this_constant_begin = nullptr, * this_constant_end = nullptr;
		while (this_succ != nullptr && this_succ->next != nullptr) {
			if (this_succ->value == this_succ->next->value) {
				// add to this_constant
				if (this_constant_begin == nullptr) {
					this_constant_begin = this_succ;
					this_constant_end = this_succ->next;
				}
				else {
					this_constant_end = this_succ->next;
				}
				this_succ = this_succ->next;
			}
			else {
				if (this_constant_begin != nullptr) {
					this_succ = this_succ->next;
					break;
				}
				else {
					this_pred = this_succ;
					this_succ = this_succ->next;
				}
			}
		}
		if (this_succ->next == nullptr) {
			this_succ = nullptr;
		}

		// find constant in other
		Node* other_constant_begin = nullptr, * other_constant_end = nullptr;
		while (other_succ != nullptr && other_succ->next != nullptr) {
			if (other_succ->value == other_succ->next->value) {
				// add to other_constant
				if (other_constant_begin == nullptr) {
					other_constant_begin = other_succ;
					other_constant_end = other_succ->next;
				}
				else {
					other_constant_end = other_succ->next;
				}
				other_succ = other_succ->next;
			}
			else {
				if (other_constant_begin != nullptr) {
					other_succ = other_succ->next;

					break;
				}
				else {
					other_pred = other_succ;
					other_succ = other_succ->next;
				}
			}
		}

		if (other_succ->next == nullptr) {
			other_succ = nullptr;
		}

		// exchange sequences
		if (this_constant_begin != nullptr && other_constant_begin != nullptr) {
			// paste other_constant in this
			if (this_pred != nullptr) {
				this_pred->next = other_constant_begin;
			}
			else {
				head = other_constant_begin;
			}

			this_pred = other_constant_end;
			this_pred->next = this_succ;

			// paster this_constant in other
			if (other_pred != nullptr) {
				other_pred->next = this_constant_begin;
			}
			else {
				other.head = this_constant_begin;
			}

			other_pred = this_constant_end;
			other_pred->next = other_succ;
		}

	}
}

void Rope::exchangeConstantVectors2(Rope& other)
{
	Node* this_pred = nullptr, * this_succ = head, * other_pred = nullptr, * other_succ = other.head;

	while (this_succ != nullptr && other_succ != nullptr) {
		// find constant in this
		Node* this_constant_begin = nullptr, * this_constant_end = nullptr;
		if (this_succ != nullptr) {
			this_constant_begin = this_succ;
			this_constant_end = this_succ;
			this_succ = this_succ->next;
		}

		while (this_succ != nullptr) {
			if (this_succ->value == this_constant_end->value) {
				this_constant_end = this_succ;
				this_succ = this_succ->next;
			}
			else {
				break;
			}
		}

		// find constant in other
		Node* other_constant_begin = nullptr, * other_constant_end = nullptr;
		if (other_succ != nullptr) {
			other_constant_begin = other_succ;
			other_constant_end = other_succ;
			other_succ = other_succ->next;
		}

		while (other_succ != nullptr) {
			if (other_succ->value == other_constant_end->value) {
				other_constant_end = other_succ;
				other_succ = other_succ->next;
			}
			else {
				break;
			}
		}

		// exchange sequences
		if (this_constant_begin != nullptr && other_constant_begin != nullptr) {
			// paste other_constant in this
			if (this_pred != nullptr) {
				this_pred->next = other_constant_begin;
			}
			else {
				head = other_constant_begin;
			}

			this_pred = other_constant_end;
			this_pred->next = this_succ;

			// paster this_constant in other
			if (other_pred != nullptr) {
				other_pred->next = this_constant_begin;
			}
			else {
				other.head = this_constant_begin;
			}

			other_pred = this_constant_end;
			other_pred->next = other_succ;
		}

		// find sequence of differing in this
		if (this_succ != nullptr) {
			this_pred = this_succ;
			this_succ = this_succ->next;

			while (this_succ != nullptr) {
				if (this_succ->value != this_pred->value) {
					this_pred = this_succ;
					this_succ = this_succ->next;
				}
				else {
					break;
				}
			}
		}

		// find sequence of differing in other
		if (other_succ != nullptr) {
			other_pred = other_succ;
			other_succ = other_succ->next;

			while (other_succ != nullptr) {
				if (other_succ->value != other_pred->value) {
					other_pred = other_succ;
					other_succ = other_succ->next;
				}
				else {
					break;
				}
			}
		}
	}
}
