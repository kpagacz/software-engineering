#ifndef __SZNUR
#define __SZNUR
#include<cstddef>
#include<iostream>

class Rope {
    private:
        struct Node {
            int value;
            Node* next;
            Node(): next(nullptr) {};
            Node(int _value): value(_value), next(nullptr) {};
        };
        Node* head;
        std::size_t size;
        
        // other
        void moveChainToTarget(Node*, Node*, Node*, Node*, Node*, Node*);
    public:
        // constructors, destructors, assignment
        Rope(): head(nullptr), size(0) {};
        ~Rope();


        // push
        void push(const int&);


        // other
        friend void remove(Rope&, const int&);
        friend void move(Rope&);
        friend void exchangeConstantSequences(Rope&, Rope&);
        friend void lookForConstant(Rope::Node*& pred, Rope::Node*& begin, Rope::Node*& end, Rope::Node*& succ);
        friend void lookForVariable(Rope::Node*& pred, Rope::Node*& begin, Rope::Node*& end, Rope::Node*& succ);
        int getSize() const;

        // operators
        friend std::ostream& operator<<(std::ostream& os, const Rope& rope) {
            Node* it = rope.head;
            while(it != nullptr) {
                os << it->value << " ";
                it = it->next;
            }
            os << std::endl;

            return os;
        }
};
#endif