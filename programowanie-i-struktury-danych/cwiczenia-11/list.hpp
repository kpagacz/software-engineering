#ifndef SORTED_LIST
#define SORTED_LIST
#include<cstddef>
#include<iostream>

template<typename T>
class SortedList {
    private:
        struct Node {
            T element;
            Node* next;
            Node(T new_el): element(new_el), next(nullptr) {};
            Node(): next(nullptr) {};
            std::ostream& operator<<(std::ostream& ostream) {
                ostream << element;
                return ostream;
            };
        };
        Node* head;
        std::size_t size;
    public:
        // constructors, destructor, assignments
        SortedList(): head(nullptr), size(0) {};
        SortedList(const SortedList<T>&);
        ~SortedList();

        // insert
        void push(T new_el);

        // operators
        friend std::ostream& operator<<(std::ostream &ostream, const SortedList<T> &list) {
            SortedList<T>::Node *iterator = list.head;
            while(iterator != nullptr) {
                ostream << iterator->element;
                iterator = iterator->next;
            }
            return ostream;
        };

        // iterators
        struct InputIt {
            private:
                Node* pointer;
                const SortedList<T> *owner;
            public:
                InputIt(SortedList<T>& owner): owner(&owner), pointer(nullptr) {
                    pointer = owner.head;
                };
                void next() {
                    pointer = pointer->next;
                };
                T operator->() {
                    return pointer->element;
                };
                T operator*() {
                    return pointer->element;
                };

                bool operator==(std::nullptr_t ptr) {
                    return pointer == ptr;
                };

                bool operator!=(std::nullptr_t ptr) {
                    return pointer != ptr;
                }

        };

        // other
        InputIt begin() {
            InputIt it(*this);
            return it;
        };

        int getSize() {
            return size;
        };

};

#include "list.cpp"

#endif