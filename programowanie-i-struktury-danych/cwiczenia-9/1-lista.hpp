#ifndef __LISTA
#define __LISTA

#include<iostream>

struct Student {
    unsigned int indeks;
    float srednia_ocen;
    Student(unsigned int _indeks, float _srednia_ocen): indeks(_indeks), srednia_ocen(_srednia_ocen) {};
};

class Lista_studentow{
    private:
        class Node{
            public:
                Student student;
                Node* next;
                Node(Student _student): student(_student), next(nullptr) {};  
        };
        Node* _head;

    public:
        // constructors, assignment, destructors
        Lista_studentow(): _head(nullptr) {};
        ~Lista_studentow();

        // output
        friend std::ostream& operator<<(std::ostream&, const Lista_studentow&);

        // insert
        void push(const Student&);

        // passed?
        void ordered_output(const float&);
        void delete_failing(const float&);
};

#endif