#ifndef ROPE
#define ROPE
#include<cstddef>

template <typename T>
class Rope {
    private:
        struct Node {
            T value;
            Node* next;
            Node(): next(nullptr) {};
            Node(T _value): value(_value), next(nullptr) {};
        };
        Node* head;
        std::size_t size;
    
    public:
        // constructors destructors
        Rope(): head(nullptr), size(0) {};
        ~Rope();

        // insertion
        void push(const T &new_value);

        // other
        void removeSeqs(const int &S, const int &K);

        // operators
        friend std::ostream& operator<<(std::ostream &os, const Rope &rope) {
            Node *it = rope.head;
            while(it != nullptr) {
                os << it->value << " ";
                it = it->next;
            }
            os << std::endl;
            return os;
        }
};

#include "rope.cpp"

#endif