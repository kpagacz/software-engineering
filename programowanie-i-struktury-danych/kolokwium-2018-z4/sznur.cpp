#ifndef SZNUR
#define SZNUR
#include<iostream>
#include "sznur.hpp"

Sznur::~Sznur() {
    Node* destr = nullptr;
    Node* it = head;

    while(it != nullptr) {
        destr = it;
        it = it->next;

        delete destr;
        destr = nullptr;
    }
}

void Sznur::print() const {
    Node* it = head;

    while(it != nullptr) {
        std::cout << it->value << " ";
        it = it->next;
    }

    std::cout << "\n";
}

void Sznur::insert(const int& new_el) {
    Node* constr = new Node(new_el);

    Node *prev = nullptr, *it = head;

    if(head == nullptr) {
        head = constr;
    } else {
        while(it != nullptr) {
            prev = it;
            it = it->next;
        }
        prev->next = constr;
    }

    size++;
}


void Sznur::removeFragments(const int &P) {
    Node* succ = head;
    Node* pred = nullptr;

    while(succ != nullptr) {
        // removal of P elements
		Node *destr = nullptr;
        int counter = P;
        while(succ != nullptr && counter > 0) {
			if (pred != nullptr) {
				pred->next = succ->next;
			}
			destr = succ;
            succ = succ->next;

            if(destr == head) {
                head = succ;
            }

			delete destr;
			destr = nullptr;
            counter --;
            size--;
        }


        // skipping increasing series
		if (succ != nullptr) {
			Node *inc_succ = succ->next, *inc_pred = succ;
			while (inc_succ != nullptr && inc_succ->value > inc_pred->value) {
				inc_pred = inc_succ;
				inc_succ = inc_succ->next;
			}

			if (succ != inc_pred) {
				succ = inc_succ;
				pred = inc_pred;
			}
		}
    }
}

void Sznur::move() {
	if (size < 2) {
		return;
	}

	// finding middle
	Node *middle = nullptr, *succ_middle = head;

	for (int i = (size + 1) / 2; i > 0; i++) {
		middle = succ_middle;
		succ_middle = succ_middle->next;
	}

	// moving odd from before middle
	Node *it = head, *pred = nullptr, *mover = nullptr, *moved_end = middle;

	while (it != middle) {
		if (it->value % 2 == 0) {
			mover = it;

			it = it->next;

			if (pred == nullptr) {
				head = it;
			}
			else {
				pred->next = it;
			}

			// actually moving
			mover->next = succ_middle;
			moved_end->next = mover;
			moved_end = mover;
		}
		else {
			pred = it;
			it = it->next;
		}
	}

	// finding element just before middle
	if (size % 2 == 0) {
		Node *pred_middle = middle;
		middle = middle->next;
		it = middle;
		pred = pred_middle;
	}
	else {
		Node *pred_middle = head;

		while (pred_middle->next != middle) {
			pred_middle = pred_middle->next;
		}
		it = middle->next;
		pred = middle;
	}


	// moving even from after middle
	while (it != nullptr) {
		if (it->value % 2 == 0) {

		}
	}

}


#endif