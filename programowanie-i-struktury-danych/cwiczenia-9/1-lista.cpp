#include <iostream>
#include <stdexcept>
#include "1-lista.hpp"


// constructors, assignment, destructors
Lista_studentow::~Lista_studentow() {
    Node* it = _head;
    Node* destroyer = nullptr;

    while(it != nullptr) {
        destroyer = it;
        it = it->next;
        delete destroyer;
    }
}

// output
std::ostream& operator<<(std::ostream& out, const Lista_studentow& list) {
    out << "Lista: " << list._head << std::endl;

    Lista_studentow::Node* it = list._head;

    while(it != nullptr) {
        out << it->student.indeks << " " << it->student.srednia_ocen << std::endl;
        it = it->next;
    }

    return out;
}

// insert
void Lista_studentow::push(const Student& student){
    Node* pred = nullptr;
    Node* succ = _head;

    Node* maker = new Node(student);

    while(succ != nullptr) {
        if(succ->student.indeks < student.indeks) {
            pred = succ;
            succ = succ->next;
        } else {
            if(succ->student.indeks == student.indeks) {
                throw std::invalid_argument("Student already exists.\n");
            } else {
                break;
            }
        }
    }

    // succ now points to the el place after
    // pred now point to the el before insertion

    if(pred == nullptr) {
        _head = maker;
    } else {
        pred->next = maker;
    }
    maker->next = succ;
}

// passed?
void Lista_studentow::ordered_output(const float& G) {
    Node* passing_begin = nullptr;
    Node* passing_end = nullptr;
    Node* failing_begin = nullptr;
    Node* failing_end = nullptr;

    Node* succ = _head;
    Node* pred = nullptr;

    while(succ != nullptr) {
        if(succ->student.srednia_ocen < G) {
            // to failing
            if(failing_begin == nullptr) {
                failing_begin = succ;
                failing_end = succ;
            } else {
                failing_end->next = succ;
                failing_end = succ;
            }

            if(pred == nullptr) {
                _head = succ->next;
            } else {
                pred->next = succ->next;
            }
            succ = succ->next;
            failing_end->next = nullptr;
        } else {
            // to passing
            if(passing_begin == nullptr) {
                passing_begin = succ;
                passing_end = succ;
            } else {
                passing_end->next = succ;
                passing_end = succ;
            }

            if(pred == nullptr) {
                _head = succ->next;
            } else {
                pred->next = succ->next;
            }
            succ = succ->next;
            passing_end->next = nullptr;
        }
    }

    if(passing_begin != nullptr) {
        _head = passing_begin;
        passing_end->next = failing_begin;
    } else {
        _head = failing_begin;
    }
}

void Lista_studentow::delete_failing(const float& G) {
    Node* pred = nullptr;
    Node* succ = _head;
    Node* destroyer = nullptr;

    while(succ != nullptr) {
        if(succ->student.srednia_ocen < G) {
            // delete
            destroyer = succ;
            succ = succ->next;
            if(pred == nullptr) {
                _head = succ;
            } else {
                pred->next = succ;
            }
            delete destroyer;
        } else {
            // iterate 
            pred = succ;
            succ = succ->next;
        }
    }
}
