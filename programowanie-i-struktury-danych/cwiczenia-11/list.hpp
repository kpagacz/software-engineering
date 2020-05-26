#ifndef SORTED_LIST
#define SORTED_LIST

template<typename T>
class SortedList {
    private:
        struct Node {
            T element;
            Node* next;
            Node(T new_el): element(new_el), next(nullptr) {};
        };
        Node* head;
        std::size_t size;
    public:
        // constructors, destructor, assignments
        SortedList(): head(nullptr), size(0) {};
        ~SortedList();

        // insert
        void push(T new_el);

        // operators
        T& operator[](const int&);

        // other
};

#include "list.cpp"

#endif