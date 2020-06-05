#include<iostream>
#include<stdexcept>

#include "rope.hpp"

template<typename T>
Rope<T>::~Rope() {
    Node* destroyer = nullptr;
    Node* it = head;

    while(it != nullptr) {
        destroyer = it;
        it = it->next;
        delete destroyer;
        destroyer = nullptr;
    }

    size = 0;
};

template<typename T>
void Rope<T>::push(const T &new_value) {
    Node *pred = nullptr, *succ = head, *creator = new Node(new_value);

    while(succ != nullptr && creator->value <= succ->value) {
        pred = succ;
        succ = succ->next;
    }

    pred == nullptr ? head = creator : pred->next = creator;
    creator->next = succ;
    size++;
};

template<typename T>
void Rope<T>::removePlus(const int &K) {
    Node *pred_pair = nullptr, *begin = nullptr, *end = nullptr, *succ_pair = head;

    while(succ_pair != nullptr && succ_pair->next != nullptr) {
        // set begin to succ, end to begin->next and succ to end->next
        begin = succ_pair;
        end = succ_pair->next;
        succ_pair = end->next;

        if(begin->value == end->value) {
            // check if the next three values are lower
            if(succ_pair != nullptr && succ_pair->next != nullptr && succ_pair->next->next != nullptr) {
                Node *first = succ_pair, *second = first->next, *third = second->next, *after_threes = third->next;
                if(begin->value - first->value <= K &&
                    begin->value - second->value <= K &&
                    begin->value - third->value <= K) {
                        // remove them
                        end->next = after_threes;
                        succ_pair = after_threes;
                        delete first, second, third;
                        size -= 3;
                }
            }

            // remove the pair
            pred_pair == nullptr ? head = succ_pair : pred_pair->next = succ_pair;
            delete begin;
            delete end;
            size -= 2;

        } else {
            // reset pred_pair
            pred_pair = end;
        } 
    }
};

template<typename T>
void Rope<T>::moveEven() {
    if(size < 2) return;
    
    Node *pred = nullptr, *it = head;

    Node *odd_before_middle = nullptr, *middle = nullptr, *it_loop = head;

    // finding odd before middle
    for(int i = 0; i < size / 2; i++) {
        if(it_loop->value % 2 == 1) {
            odd_before_middle = it_loop;
        }
        it_loop = it_loop->next;
    }

    // assigning middle if odd size
    if(size % 2) {
        middle = it_loop;
        it_loop = it_loop->next;
    }

    Node *odd_after_middle = nullptr;
    for(int i = 0; i < size / 2; i++) {
        if(it_loop->value % 2 == 1) {
            odd_after_middle = it_loop;
            break;
        }
        it_loop = it_loop->next;
    }
    

    // even pre middle
    // even post middle
    Node *pre_begin = nullptr, *pre_end = nullptr, *post_begin = nullptr, *post_end = nullptr;
    bool add_to_pre = true;
    while(it != nullptr) { // making chains
        Node *succ = it->next;
        
        // skip the middle value
        if (it == middle) {
            pred = it;
            it = it->next;
            continue;
        }

        // if even then add to one of the chains
        if(it->value % 2 == 0) {    // value even
            // unlink
            if(pred == nullptr) {
                head = succ;
            } else {
                pred->next = succ;
            }

            if(add_to_pre) {        // add to pre chain
                if(pre_begin == nullptr) {
                    pre_begin = it;
                    pre_end = it;
                    pre_end->next = nullptr;
                } else {
                    pre_end->next = it;
                    pre_end = it;
                    it->next = nullptr;
                }
            } else {        // add to post chain
                if(post_begin == nullptr) {
                    post_begin = it;
                    post_end = it;
                    post_end->next = nullptr;
                } else {
                    it->next = post_begin;
                    post_begin = it;
                }
            }

            add_to_pre = !add_to_pre;
            it = succ;
        } else {        // value odd
            pred = it;
            it = it->next;
        }
    }

    // linking chains
    if(size % 2 == 0) {
        pre_end->next = post_begin;
    } else {
        pre_end->next = middle;
        middle->next = post_begin;
    }

    if(odd_before_middle == nullptr) {
        head = pre_begin;
    } else {
        odd_before_middle->next = pre_begin;
    }

    post_end->next = odd_after_middle;
};



