#include<iostream>
#include<stdexcept>

template <typename T>
SortedList<T>::SortedList(const SortedList<T>& other_list) {
    Node* this_pred = nullptr;
    Node* other_it = other_list.head;
    size = 0;

    while(other_it != nullptr) {
        Node* creator = new Node;
        creator->element = other_it->element;
        creator->next = nullptr;

        if(this_pred == nullptr) {
            head = creator;
        } else {
            this_pred->next = creator;
        }

        size++;
        other_it = other_it->next;
        this_pred = creator;
    }   
};

template <typename T>
SortedList<T>::~SortedList() {
    Node *it = head, *destroyer = nullptr;

    while (it != nullptr) {
        destroyer = it;
        it = it->next;
        delete destroyer;
    }

    size = 0;
}

// insert
template <typename T>
void SortedList<T>::push(T new_el) {
    Node *creator = new Node();
    creator->element = new_el;
    creator->next = nullptr;
    Node *succ = head, *pred = nullptr;

    // iteration through the list
    // finding the right spot to insert
    while(succ != nullptr) {
        if(creator->element > succ->element) {
            pred = succ;
            succ = succ->next;
        } else {
            break;
        }
    }

    // succ now points to the node after the insertion place
    // pred now points to the node before the insertion place
    // insertion
    if(pred == nullptr) {
        head = creator;
    } else {
        pred->next = creator;
    }
    creator->next = succ;
    size++;
};

// other
