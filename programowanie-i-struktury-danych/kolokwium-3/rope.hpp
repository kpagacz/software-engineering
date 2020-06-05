#ifndef ROPE
#define ROPE

#include<iostream>
#include<cstddef>

template<typename T>
class Rope {
    private:
        struct Node {
            T value;
            Node* next;
            Node(const T &new_value): value(new_value), next(nullptr) {};
        };
        Node* head;
        std::size_t size;
    
    public:
        Rope(): head(nullptr), size(0) {};
        ~Rope();

        // other
        void push(const T &new_element);
        void removePlus(const int &K);
        void moveEven();

        // operators
        friend std::ostream &operator<<(std::ostream &os, const Rope &rope) {
            for(Node* it = rope.head; it != nullptr; it = it->next) {
                os << it->value << " ";
            }
            os << std::endl;
            return os;
        }
};

#include"rope.cpp"
#endif