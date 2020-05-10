#ifndef __sznur
#define __sznur

#include<iostream>

class Sznur{
    private:
        class Node{
            public:
                int value;
                Node* next;
                Node(): value(0), next(nullptr) {};
                Node(const Node&);
                Node(const int& _value): value(_value), next(nullptr) {};
        };

        Node* _head;
        std::size_t _size;

    public:
        // constructor, assignment, destructor
        Sznur(): _head(nullptr), _size(0) {};
        Sznur(const Sznur&);
        Sznur(Sznur&&);
        Sznur& operator=(const Sznur&);
        Sznur& operator=(Sznur&&);

        ~Sznur();

        // other
        friend std::ostream& operator<<(std::ostream&, const Sznur&);

        void push_back(const int&);

        void UsunFragmenty(const int&);
        void usunZPar(const int&);
        void przestawParzyste();
        void Odwroc(int);
        void Przegrupuj(Sznur&);
    
        void empty();
};

#endif