#include<iostream>
#include<stdexcept>


template <typename T>
Rope<T>::~Rope() {
    Node *it = head, *destroyer = nullptr;
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

    while(succ != nullptr) {
        if(creator->value <= succ->value) {
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

template<typename T>
void Rope<T>::removeSeqs(const int &S, const int &K) {
    // input check
    if(S <= 0 || K <= 0) {
        throw std::invalid_argument("S and K need to be positive!");
    }

    Node *pred_chain = nullptr, *begin = nullptr, *end = nullptr, *succ_chain = head;
    while(succ_chain != nullptr) {
        T sum = 0;
        // find the sequence with the sum lower  than S
        while(succ_chain != nullptr) {
            sum += succ_chain->value;
            if(sum <= S) {
                // add to sum and exted the chain
                if(begin == nullptr) {
                    begin = succ_chain;
                }
                end = succ_chain;
                succ_chain = succ_chain->next;
            } else {
                break;
            }
        }

        // remove that sequence
        Node* destroyer = nullptr;
        if(begin != nullptr) {
            while(begin != succ_chain) {
                destroyer = begin;
                begin = begin->next;
                delete destroyer;
                destroyer = nullptr;
                size--;
            }
        }

        if(pred_chain == nullptr) {
            head = succ_chain;
        } else {
            pred_chain->next = succ_chain;
        }

        // skip K elements
        int counter = K;
        while(succ_chain != nullptr && counter > 0) {
            pred_chain = succ_chain;
            succ_chain = succ_chain->next;
            counter--;
        }
        
        // reset begin and end pointers
        begin = nullptr;
        end = nullptr;
    }
};
