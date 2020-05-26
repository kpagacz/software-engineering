#include<iostream>

#include"sorted-list-generic.h"
#include"1-lista.hpp"

int main() {
    int a=1,b=2,c=3,d=-1;
    SortedList<int> l1;

    std::cout << "Insert:" << std::endl;
    l1.insertNode(a);
    l1.insertNode(b);
    l1.insertNode(c);
    l1.insertNode(d);

    std::cout << l1 << std::endl;

    l1.insertNode(7);
    l1.insertNode(8);
    l1.insertNode(0);

    std::cout << l1;
    l1.removeEveryNth(3);
    std::cout << l1;


    l1.insertNode(-1);
    l1.insertNode(2);
    l1.insertNode(8);
    std::cout << l1;
    l1.removeDuplicated();
    std::cout << l1;

    SortedList<int> l2;
    l2.insertNode(7);
    l2.insertNode(7);
    l2.removeDuplicated();
    std::cout << l2;


    // Student
    Student s1(8, 4.5), s2(6, 3), s3(3, 2.5);
    SortedList<Student> l3;
    l3.insertNode(s1);
    l3.insertNode(s2);
    l3.insertNode(s3);
    l3.insertNode(s3);

    std::cout << l3;

    l3.removeDuplicated();
    std::cout << l3;
    l3.removeEveryNth(2);
    std::cout << l3;
    return 0;
}