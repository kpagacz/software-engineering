#include <iostream>
#include "sznur.hpp"


int main() {
    Sznur sz1;
    sz1.insert(1);
    sz1.print();
    

    sz1.insert(2);
    sz1.insert(-9);
    sz1.print();

    Sznur test1;
    test1.insert(4);
    test1.insert(7);
    test1.insert(5);
    test1.insert(1);
    test1.insert(6);
    test1.insert(6);
    test1.insert(1);
    test1.insert(7);
    test1.insert(7);
    test1.insert(3);
    test1.insert(2);
    test1.insert(1);
    test1.insert(2);
    test1.insert(3);
    test1.insert(1);

    test1.print();
    test1.removeFragments(3);
    test1.print();


    return 0;
}