#include<iostream>
#include<algorithm>

#include "rope.hpp"


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

void Rope::print() const {
	for (Node* it = head; it != nullptr; it = it->next) {
		std::cout << it->value << " ";
	}

	std::cout << "\n";
}


void Rope::insert(const int& new_el) {
	Node* pred = nullptr, * succ = head;
	Node* creator = new Node(new_el);

	while (succ != nullptr) {
		pred = succ;
		succ = succ->next;
	}

	if (pred == nullptr)
		head = creator;
	else
		pred->next = creator;
	creator->next = succ;
	size++;
}

void Rope::funny_remove(const int& M, const int& N) {
	Node* succ = head, * pred = nullptr, * destr = nullptr;
	int counter;
	while (succ != nullptr) {
		counter = M - 1;
		while (succ != nullptr && counter > 0) {
			pred = succ;
			succ = succ->next;
			counter--;
		}

		destr = succ;
		if (destr != nullptr) {
			succ = succ->next;
			remove_node(pred, destr);
		}

		counter = N - 1;
		while (succ != nullptr && counter > 0) {
			pred = succ;
			succ = succ->next;
			counter--;
		}

		destr = succ;
		if (destr != nullptr) {
			succ = succ->next;
			remove_node(pred, destr);
		}
	}
}

void Rope::remove_node(Node* pred, Node* succ)
{
	Node* destr = succ;
	if (pred != nullptr) {
		pred->next = succ->next;
	}
	else {
		head = succ->next;
	}

	succ = succ->next;
	delete destr;
	destr = nullptr;
	size--;
}

void Rope::move()
{
	Node* first, * second, * third;

	Node* pred = nullptr, * succ = head;

	Node* threes_begin = nullptr, * threes_end = nullptr;
	Node* pairs_begin = nullptr, * pairs_end = nullptr;


	while (succ != nullptr && succ->next != nullptr && succ->next->next != nullptr) {
		first = succ;
		second = succ->next;
		third = succ->next->next;
		succ = third->next;

		if (first->value == second->value && second->value == third->value) {
			// to threes
			if (pred != nullptr) {
				pred->next = succ;
			}
			else {
				head = succ;
			}

			if (threes_begin == nullptr) {
				threes_begin = first;
			}
			else {
				threes_end->next = first;
			}
			threes_end = third;
			threes_end->next = nullptr;
		}
		else { // to pairs
			if (first->value == second->value) {
				if (pred == nullptr) {
					head = third;
				}
				else {
					pred->next = third;
				}
				pred = third;

				if (pairs_begin == nullptr) {
					pairs_begin = first;
				}
				else {
					pairs_end->next = first;
				}
				pairs_end = second;
				pairs_end->next = nullptr;
			}

			if (second->value == third->value) {
				if (pred == nullptr) {
					head = first;
				}
				else {
					pred->next = first;
				}
				pred = first;

				if (pairs_begin == nullptr) {
					pairs_begin = second;
				}
				else {
					pairs_end->next = second;
				}
				pairs_end = third;
				pairs_end->next = nullptr;
			}

			if (first->value == third->value) {
				if (pred != nullptr) {
					pred->next = second;
				}
				else {
					head = second;
				}
				pred = second;
				pred->next = succ;

				first->next = second;

				if (pairs_begin == nullptr) {
					pairs_begin = first;
				}
				else {
					pairs_end->next = first;
				}

				pairs_end = third;
				pairs_end->next = nullptr;
			}

			if (first->value != second->value && first->value != third->value && second->value != third->value) {
				pred = third;
			}
		}
	}

	if (pairs_begin != nullptr) {
		pairs_end->next = head;
		head = pairs_begin;
	}
	if (threes_begin != nullptr) {
		// find end
		Node* it = head, * end = nullptr;

		while (it != nullptr) {
			end = it;
			it = it->next;
		}

		end->next = threes_begin;
	}

}

void Rope::move_pairs(Rope& other, const int& M) {
	Node* other_head = other.head;

	Node* succ = head, * pred = nullptr;

	Node* pairs_begin = nullptr, * pairs_end = nullptr;

	bool skip_pair = false;

	while (succ != nullptr && succ->next != nullptr) {
		Node* first = succ, * second = succ->next;
		succ = second->next;
		if (!skip_pair) {
			if (pred != nullptr) {
				pred->next = succ;
			}
			else {
				head = succ;
			}

			if (pairs_begin == nullptr) {
				pairs_begin = second;
				pairs_end = first;
				pairs_begin->next = pairs_end;
				pairs_end->next = nullptr;
			}
			else {
				pairs_end->next = second;
				second->next = first;
				first->next = nullptr;
				pairs_end = first;
			}
		}
		else {
			pred = second;
		}

		skip_pair = !skip_pair;
	}

	Node* m_begin = other.head, * pred_m = nullptr;
	// find M-end
	for (int i = std::max(int(other.size - M), 0); i > 0; --i) {
		pred_m = m_begin;
		m_begin = m_begin->next;
	}

	Node* pairs_it = pairs_begin;

	while (pairs_it != nullptr) {
		Node* first = pairs_it;
		Node* second = pairs_it->next;
		pairs_it = second->next;

		if (pred_m == nullptr) {
			other.head = first;
			second->next = m_begin;
		}
		else {
			pred_m->next = first;
			second->next = m_begin;
		}

		if (m_begin != nullptr) {
			pred_m = m_begin;
			m_begin = m_begin->next;
		}
		else {
			pred = second;
		}
	}
	
}