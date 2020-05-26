#include<iostream>
#include<stdexcept>

#include "sorted-list-generic.h"

template <typename T>
SortedList<T>::~SortedList() {
    SortedList<T>::Node *it = head, *destroyer = nullptr;
    while(it != nullptr) {
        destroyer = it;
        it = it->next;
        delete destroyer;
    }
};

template <typename T>
void SortedList<T>::insertNode(T element) {
    SortedList<T>::Node *creator = new SortedList<T>::Node(element), *pred = nullptr, *succ = head;
    
    while(succ != nullptr) {
        if(creator->element > succ->element) {
            pred = succ;
            succ = succ->next;
        } else {
            break;
        }
    }

    if(pred == nullptr) {
        head = creator;
    } else {
        pred->next = creator;
    }

    creator->next = succ;
    size++;
};

template <typename T>
void SortedList<T>::deleteNode(const T& value) {
    SortedList<T>::Node *destroyer = nullptr, *pred = nullptr, *succ = head;

    while(succ != nullptr) {
        if(succ->element == value) {
            destroyer = succ;
            succ = succ->next;
            if(pred == nullptr) {
                head = succ;
            } else {
                pred->next = succ;
            }
            delete destroyer;
            size--;
            break;
        } else {
            pred = succ;
            succ = succ->next;
        }
    }
};

template <typename T>
void SortedList<T>::empty() {
    SortedList<T>::Node destroyer = nullptr, it = head;
    while(it != nullptr) {
        destroyer = it;
        it = it->next;
        delete destroyer;
    }
    size = 0;
};

template <typename T>
void SortedList<T>::removeNode(SortedList<T>::Node *&pred, SortedList<T>::Node *&succ) {
    SortedList::Node* destroyer = succ;
    succ = succ->next;

    if(pred == nullptr) {
        head = succ;
    } else {
        pred->next = succ;
    }

    delete destroyer;
}

template <typename T>
void SortedList<T>::removeEveryNth(int N) {
    int counter = N;

    SortedList::Node *pred = nullptr, *succ=head;

    while(succ != nullptr) {
        if(counter > 1) {
            pred = succ;
            succ = succ->next;
            counter--;
        } else {
            removeNode(pred, succ);
            size--;
            counter = N;
        }
    }
    
};

template<typename T>
void SortedList<T>::deleteChain(SortedList<T>::Node*& pred, SortedList<T>::Node*& begin, SortedList<T>::Node*& end, SortedList<T>::Node*& succ) {
    if(pred == nullptr) {
        head = succ;
    } else {
        pred->next = succ;
    }

    end->next = nullptr;

    SortedList<T>::Node *destroyer = begin;

    while(begin != nullptr) {
        destroyer = begin;
        begin = begin->next;
        delete destroyer;
        size--;
    }

    begin = succ;
    end = succ;
};

template <typename T>
void SortedList<T>::removeDuplicated() {
    SortedList<T>::Node *pred = nullptr, *succ = head, *begin = head, *end = head;
    int duplicate_counter = 0;

    while(succ != nullptr) {
        if(succ->element == end->element) {
            end = succ;
            succ = succ->next;
            duplicate_counter++;
        } else {
            if(duplicate_counter > 1) {
                if(pred == nullptr) {
                    pred = head;
                } else {
                    pred = pred->next;
                }
                begin = begin->next;
                deleteChain(pred, begin, end, succ);
            } else {
                pred = end;
                begin = succ;
                end = succ;
            }
                duplicate_counter = 0;
        }
    }
    if(duplicate_counter > 1) {
        if(pred == nullptr) {
            pred = head;
        } else {
            pred = pred->next;
        }
        begin = begin->next;
        deleteChain(pred, begin, end, succ);
    }
}
