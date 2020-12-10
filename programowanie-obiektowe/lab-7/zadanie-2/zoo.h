#ifndef ZOO
#define ZOO

#include "zwierze.h"
#include<iostream>

class Pies : public Zwierze {
    public:
        void dajGlos() { std::cout << "Hau hau\n"; }
        Pies() = default;
        ~Pies() = default;
};

class Kot : public Zwierze {
    public:
        void dajGlos() { std::cout << "Miau miau\n"; }
        Kot() = default;
        ~Kot() = default;
};


class Swinia : public Zwierze {
    public:
        void dajGlos() { std::cout << "Chrum chrum\n"; }
        Swinia() = default;
        ~Swinia() = default;
};

#endif 
